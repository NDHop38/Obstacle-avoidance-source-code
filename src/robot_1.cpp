#include <Arduino.h>
#include <control.h>

const int DC_Left1 = 2;
const int DC_Left2 = 3;
const int DC_Right1 = 4;
const int DC_Right2 = 5;
const int ENA = 6;
const int ENB = 7;
const int leftSensor = A1;
const int midSensor = A0;
const int rightSensor = A2;

void setup() {
  // put your setup code here, to run once:
  pinMode(DC_Left1, OUTPUT);
  pinMode(DC_Left2, OUTPUT);
  pinMode(DC_Right1, OUTPUT);
  pinMode(DC_Right2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  pinMode(leftSensor, INPUT);
  pinMode(midSensor, INPUT);
  pinMode(rightSensor, INPUT);
}


// void readSensor() {
//   const int midSensor = analogRead(A0);
//   const int leftSensor = analogRead(A1);
//   const int rightSensor = analogRead(A2);
// }

void goStraight() {
  digitalWrite(DC_Left1, HIGH);
  digitalWrite(DC_Left2, LOW);
  digitalWrite(DC_Right1, HIGH);
  digitalWrite(DC_Right2, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
  const int midSensor = analogRead(A0);
  const int leftSensor = analogRead(A1);
  const int rightSensor = analogRead(A2);
  // cam bien truoc nhan
  if (midSensor < 500) {
    goBackward();
    delay(1000);
    int left_or_right = random(0, 2);
    if (left_or_right == 0) {
      turnRight();
      delay(150);
    } else {
      turnLeft();
      delay(150);
    }
    // cam bien truoc, trai, phai deu nhan
    if (leftSensor < 500 && rightSensor < 500) {
      goBackward();
      delay(1000);
    }
    // cam bien truoc , trai deu nhan
    else if (leftSensor < 500) {
      turnRight();
      delay(150);
    }
    // cam bien truoc, phai deu nhan
    else if (rightSensor < 500) {
      turnLeft();
      delay(150);
    }
    delay(1000);
  }
  // cam bien trai , phai deu nhan 
  else if (leftSensor < 500 && rightSensor < 500) {
    goStraight();
  }
  //cam bien trai nhan
  else if (leftSensor < 500) {
    turnRight();
    delay(150);
  }
  // cam bien phai nhan
  else if (rightSensor < 500) {
    turnLeft();
    delay(150);
  }
  else {
    goStraight();
  }

}