#include <Arduino.h>
#define outputPWM 9
#define outputA 8  
#define outputB 7 
#define potentiometerPin A0


void setup() {
    pinMode(outputPWM, OUTPUT);
    pinMode(outputA, OUTPUT);
    pinMode(outputB, OUTPUT);
    pinMode(potentiometerPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    int potValue = analogRead(potentiometerPin);
    int motorSpeed = map(potValue, 0, 1023, 0, 255);
    analogWrite(outputPWM, motorSpeed);
    digitalWrite(outputA, HIGH);
    digitalWrite(outputB, LOW);

    static unsigned long lastTime = 0;
    unsigned long currentTime = millis();

    if(currentTime - lastTime >= 1000){ //debug
        lastTime = currentTime;
        Serial.print("Potentiometer value: ");
        Serial.println(potValue);

        Serial.print("Motor speed: ");
        Serial.println(motorSpeed);
    }



}