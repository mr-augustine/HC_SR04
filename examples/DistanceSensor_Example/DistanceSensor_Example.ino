#include <DistanceSensor.h>

/*
 * Distance Sensor Library Example.
 * One main function:
 *   getDistance(true) - returns distance in cm
 *   getDistance(false) - returns distance in inches
 */
 

//Constructor with (Trig pin, Echo pin)
//NOTE: the pins do NOT have to be PWM(~)
DistanceSensor sensor(30,31);

long cm;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  cm = sensor.getDistance(true);
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println();
  
  delay(60);
}
