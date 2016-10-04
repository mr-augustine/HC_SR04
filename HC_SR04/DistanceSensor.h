/*
Library for HC-SR04 Sensor
*/
#ifndef DistanceSensor_h
#define DistanceSensor_h

#include "Arduino.h"

class DistanceSensor
{
  public:
    DistanceSensor(int trigPin, int echoPin);
	long getDistance(bool returnCm);
  private:
	long microsecondsToCentimeters(long microseconds);
	long cmToInches(long centim);
	int pingPin;
    int inPin;
	bool debug;
};

#endif