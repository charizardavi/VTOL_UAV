#include <IBusBM.h>

IBusBM IBus;

void setup() {
  Serial.begin(115200);

  Serial4.setRx(PA1);
  Serial4.setTx(PA0);

  IBus.begin(Serial4, IBUSBM_NOTIMER);

  Serial.println("starting RX logging");
}

void loop() {
  IBus.loop();

  for(int i = 0; i < 6; i++) {
    int channelValue = IBus.readChannel(i);
    Serial.print("Channel ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.print(channelValue);
    Serial.print(", ");
  }
  Serial.println();
}
