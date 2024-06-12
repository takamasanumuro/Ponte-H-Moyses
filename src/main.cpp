#include <Arduino.h>
#define outputPWM 9
#define outputA 8  
#define outputB 7 
#define potentiometerPin A0
#define buttonChangeDirectionPin 6

void setup() {
    Serial.begin(9600);
    pinMode(outputPWM, OUTPUT);
    pinMode(outputA, OUTPUT);
    pinMode(outputB, OUTPUT);
    pinMode(potentiometerPin, INPUT);
    pinMode(buttonChangeDirectionPin, INPUT_PULLUP);

}

void loop() {

    bool buttonState = digitalRead(buttonChangeDirectionPin);

    if (buttonState == LOW) {
        digitalWrite(outputA, LOW);
        digitalWrite(outputB, HIGH);
    } else {
        digitalWrite(outputA, HIGH);
        digitalWrite(outputB, LOW);
    }

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
        
        Serial.print("Button state: ");
        Serial.println(buttonState);
        
    }



}