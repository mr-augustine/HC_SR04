/*
Library for HC-SR04 Sensor
*/

#include "Arduino.h"
#include "DistanceSensor.h"

/**
constructor:
takes care of assigning pins for you 

@param trigPin the pin number on the physical arduino board which is connected to the trigger ("trig") pin on the sensor 
@param echoPin the pin number on the physical arduino board which is connected to the echo pin on the sensor 
*/
DistanceSensor::DistanceSensor(int trigPin, int echoPin){
	//turn debug statements on/off
	debug = false;
	
	pingPin = trigPin;
	inPin = echoPin;
	
	//pin setup
	pinMode(pingPin, OUTPUT);
	pinMode(inPin, INPUT);
}

/**
returns the distance for a given set of ultrasonic pins

@param returnCm if true, returns in cm. if false, returns dinstance in inches
*/
long DistanceSensor::getDistance(bool returnCm){

	long pulseRead = -1;
	long cm = -1;

	//sending the signal, starting with LOW for a clean signal
	//digitalWrite(pingPin, LOW);
	//delayMicroseconds(2);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(pingPin, LOW);


	//calculate distance
	pulseRead = pulseIn(inPin, HIGH, 18000);

	// convert the time into a distance
	cm = microsecondsToCentimeters(pulseRead);


	//printing the current readings to ther serial display
	if (debug) {
		Serial.print(cm);
		Serial.print("cm");
		Serial.println();
	}
	
	if(returnCm)
		return cm;
	else
		return cmToInches(cm);
}

/**
converts from microseconds to cm
*/
long DistanceSensor::microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

/**
converts cm to inches
*/
long DistanceSensor::cmToInches(long centim) {
  //Serial.println("converting inches");
  return centim / 2.54;
}
