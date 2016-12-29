#include "ADXL335.h"
#include <Arduino.h>

ADXL335::ADXL335(int pinX, int pinY, int pinZ) {
  pins[X] = pinX;
  pins[Y] = pinY;
  pins[Z] = pinZ;

  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(pinZ, INPUT);
}

float ADXL335::getExtVoltage() {
  return extVoltage;
}

void ADXL335::setExtVoltage(float v) {
  extVoltage = v;
}

float ADXL335::getZeroGVoltage(AXIS a) {
  return zeroGVoltage[a];
}

void ADXL335::setZeroGVoltage(AXIS a, float v) {
  zeroGVoltage[a] = v;
}

float ADXL335::getSensitivity(AXIS a) {
  return sensitivity[a];
}

void ADXL335::setSensitivity(AXIS a, float s) {
  sensitivity[a] = s;
}

void ADXL335::update() {
  rawValues[X] = analogRead(pins[X]);
  rawValues[Y] = analogRead(pins[Y]);
  rawValues[Z] = analogRead(pins[Z]);
}

void ADXL335::update(int rep, int delta_t) {
  rep = max(1, rep);
  int x_sum = 0;
  int y_sum = 0;
  int z_sum = 0;
  for (int i = 0; i < rep; i++) {
    x_sum += analogRead(pins[X]);
    y_sum += analogRead(pins[Y]);
    z_sum += analogRead(pins[Z]);
    delay(delta_t);
  }
  rawValues[X] = x_sum / rep;
  rawValues[Y] = y_sum / rep;
  rawValues[Z] = z_sum / rep;
}

int ADXL335::rawValue(AXIS a) {
  return rawValues[a];
}

float ADXL335::getVoltage(AXIS a) {
  return extVoltage * rawValues[a] / MAX_VAL_ADC;
}

float ADXL335::getAcceleration(AXIS a) {
  return (getVoltage(a) - getZeroGVoltage(a)) / sensitivity[a];
}


