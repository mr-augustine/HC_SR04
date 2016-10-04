#include <HC_SR04.h>

HC_SR04 us1(30,31);
HC_SR04 us2(32,33);
HC_SR04 us3(34,35);
HC_SR04 us4(36,37);
HC_SR04 us5(38,39);
HC_SR04 us6(40,41);

long cm;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	cm = us1.getDistance(true);
	Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println();
    
    cm = us2.getDistance(true);
	Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println();
    
    cm = us3.getDistance(true);
	Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println();
    
    cm = us4.getDistance(true);
	Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println();
    
    cm = us5.getDistance(true);
	Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println();
	
cm = us6.getDistance(true);
	Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println();
    
    Serial.println();
    Serial.println();
    
	delay(500);


}
