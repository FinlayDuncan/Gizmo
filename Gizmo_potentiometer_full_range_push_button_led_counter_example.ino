#include <Servo.h>

Servo myservo1;  // create servo objects to control servos
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

const int  buttonPin = 12; // push button to freeze control glove

int buttonPushCounter = 0; 
int buttonState = 0;
int lastButtonState = 0;
int potpin0 = 0;  // analog pin used to connect the potentiometer
int potpin1 = 1;
int potpin2 = 2;
int potpin3 = 3;
int potpin4 = 4;
int val1;    // variable to read the value from the analog pin
int val2;
int val3;
int val4;
int val5;


void setup() {
  pinMode(buttonPin, INPUT);
  myservo1.attach(5); // attaches the servo on pin n to the servo object
  myservo2.attach(6);  
  myservo3.attach(9);
  myservo4.attach(10);
  myservo5.attach(11);
  Serial.begin(9600);
}

void loop() {
 buttonState = digitalRead(buttonPin); // compare the buttonState to its previous state
  if (buttonState != lastButtonState) { // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0) {
    myservo1.write(90); // fix all servos at middle position whilst putting on glove
    myservo2.write(90);
    myservo3.write(90);
    myservo4.write(90);
    myservo5.write(90);
  }
  else { // begin glove control of servos
    int sensorValue1 = analogRead(A0);
    val1 = analogRead(potpin0);
    val1 = map(val1, 0, 700, 30, 160); // val mapped based on amount of potentiometer travel caused by each finger movement 
    myservo1.write(val1);
    delay(15);
    int sensorValue2 = analogRead(A1);
    val2 = analogRead(potpin1);
    val2 = map(val2, 0, 1023, 30, 150);
    myservo2.write(val2);
    delay(15);
    int sensorValue3 = analogRead(A2);
    val3 = analogRead(potpin2);
    val3 = map(val3, 0, 1023, 30, 150);
    myservo3.write(val3);
    delay(15);
    int sensorValue4 = analogRead(A3);
    val4 = analogRead(potpin3);
    val4 = map(val4, 0, 1023, 30, 170);
    myservo4.write(val4);
    delay(15);
    int sensorValue5 = analogRead(A4);
    val5 = analogRead(potpin4);
    val5 = map(val5, 0, 1023, 30, 150);
    myservo5.write(val5);
    delay(15);
}
}
