#ifndef _ADXL335_H_
#define _ADXL335_H_

enum AXIS {
  X = 0,
  Y = 1,
  Z = 2
};

class ADXL335 {
  private:
    const float MAX_VAL_ADC = 1023.0;
    float extVoltage = 5.0;
    float zeroGVoltage[3] = { 1.5, 1.5, 1.5 };
    float sensitivity[3] = { 0.3, 0.3, 0.3 };
    int rawValues[3] = { 512, 512, 512 };
    int pins[3];
  public:
    ADXL335(int pinX, int pinY, int pinZ);

    float getExtVoltage();
    void setExtVoltage(float v);

    float getZeroGVoltage(AXIS a); 
    void setZeroGVoltage(AXIS a, float v);

    float getSensitivity(AXIS a);
    void setSensitivity(AXIS a, float s);

    void update();
    void update(int rep, int delta_t);

    int rawValue(AXIS a);
    float getVoltage(AXIS a);
    float getAcceleration(AXIS a);
};
#endif
