#include <Arduino.h>
#include <control.h>

const int DC_Left1 = 8;
const int DC_Left2 = 9;
const int DC_Right1 = 10;
const int DC_Right2 = 11;
const int ENA = 5;
const int ENB = 6;
const int leftSensor = A1;
const int midSensor = A2;
const int rightSensor = A0;

void readSensor() {
  const int midSensor = analogRead(A0);
  const int leftSensor = analogRead(A1);
  const int rightSensor = analogRead(A2);
}

void runRobot()
  {
    // cam bien truoc nhan
    if (midSensor < 500)
    {
      goBackward();
      delay(1000);
      int left_or_right = random(0, 2);
      if (left_or_right == 0)
      {
        turnRight();
        delay(150);
      }
      else
      {
        turnLeft();
        delay(150);
      }
      // cam bien truoc, trai, phai deu nhan
      if (leftSensor < 500 && rightSensor < 500)
      {
        goBackward();
        delay(1000);
      }
      // cam bien truoc , trai deu nhan
      else if (leftSensor < 500)
      {
        turnRight();
        delay(150);
      }
      // cam bien truoc, phai deu nhan
      else if (rightSensor < 500)
      {
        turnLeft();
        delay(150);
      }
      delay(1000);
    }
    // cam bien trai , phai deu nhan
    else if (leftSensor < 500 && rightSensor < 500)
    {
      goStraight();
    }
    // cam bien trai nhan
    else if (leftSensor < 500)
    {
      turnRight();
      delay(150);
    }
    // cam bien phai nhan
    else if (rightSensor < 500)
    {
      turnLeft();
      delay(150);
    }
    else
    {
      goStraight();
    }
  }

void setup()
{
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


void loop()
{
  void readSensor();
  void runRobot();

}
