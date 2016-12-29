#include <ADXL335.h>

ADXL335 acc(A4, A3, A2);

void setup() {
  Serial.begin(9600);
  
  acc.setExtVoltage(5.13);
  acc.setZeroGVoltage(X, 1.64);
  acc.setZeroGVoltage(Y, 1.64);
  acc.setZeroGVoltage(Z, 1.66);
  acc.setSensitivity(X, 0.3);
  acc.setSensitivity(Y, 0.3);
  acc.setSensitivity(Z, 0.4);
}

void loop() {
  acc.update(20, 1);
  
  float x = acc.getAcceleration(X);
  float y = acc.getAcceleration(Y);
  float z = acc.getAcceleration(Z);
  
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(z);
}
