#include <TinyWireS.h>
#include <Manchester.h>

#define I2C_SLAVE_ADDR  0x26
void setup()
{
  man.setupTransmit(1, MAN_1200); // mejor pin 3 cuando en placa
  TinyWireS.begin(I2C_SLAVE_ADDR);
}

void loop() {
  if (TinyWireS.available()){
    int envio = TinyWireS.receive();
    man.transmit(envio);
  }
}
