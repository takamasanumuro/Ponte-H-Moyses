#include <Arduino.h>
#define motorOutputPWM 3
#define motorOutputA 4  
#define motorOutputB 5 
#define potentiometerSignalPin A6
#define potentiometerPowerPin  A5
#define potentiometerGroundPin A4
#define buttonChangeMotorDirectionPin A3
#define buttonChangeMotorDirectionGND A2

void setup() {
    Serial.begin(9600);
    pinMode(motorOutputPWM, OUTPUT);
    pinMode(motorOutputA, OUTPUT);
    pinMode(motorOutputB, OUTPUT);
    pinMode(potentiometerGroundPin, OUTPUT); digitalWrite(potentiometerGroundPin, LOW);
    pinMode(potentiometerPowerPin, OUTPUT);  digitalWrite(potentiometerPowerPin, HIGH);
    pinMode(potentiometerSignalPin, INPUT); 
    pinMode(buttonChangeMotorDirectionPin, INPUT_PULLUP);
    pinMode(buttonChangeMotorDirectionGND, OUTPUT); digitalWrite(buttonChangeMotorDirectionGND, LOW);

}

void loop() {

    bool buttonState = digitalRead(buttonChangeMotorDirectionPin);

    if (buttonState == LOW) {
        digitalWrite(motorOutputA, LOW);
        digitalWrite(motorOutputB, HIGH);
    } else {
        digitalWrite(motorOutputA, HIGH);
        digitalWrite(motorOutputB, LOW);
    }

    int potValue = analogRead(potentiometerSignalPin);
    int motorSpeed = map(potValue, 0, 1023, 0, 255);
    analogWrite(motorOutputPWM, motorSpeed);
    digitalWrite(motorOutputA, HIGH);
    digitalWrite(motorOutputB, LOW);



    static unsigned long lastTime = 0;
    unsigned long currentTime = millis();

    if(currentTime - lastTime >= 1000){ //debug
        lastTime = currentTime;
        Serial.print("Potentiometer value: ");
        Serial.println(potValue);

        Serial.print("Motor speed: ");
        Serial.println(motorSpeed);
        
        Serial.print("Button state: ");
        Serial.println(buttonState);
        
    }



}