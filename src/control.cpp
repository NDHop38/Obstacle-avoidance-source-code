#include "control.h"
#include <Arduino.h>
// DC left
int ENA = 5;
const int DC_Left1 = 8;
const int DC_Left2 = 9;
// DC right
int ENB = 6;
const int DC_Right1 = 10;
const int DC_Right2 = 11;
// Pin sensor
const int leftSensor = A1;
const int midSensor = A0; // Initialize midSensor to a default value
const int rightSensor = A2;
void goBackward()
{
  digitalWrite(DC_Left1, LOW);
  digitalWrite(DC_Left2, HIGH);
  digitalWrite(DC_Right1, LOW);
  digitalWrite(DC_Right2, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}
void goStraight()
{
  digitalWrite(DC_Left1, HIGH);
  digitalWrite(DC_Left2, LOW);
  digitalWrite(DC_Right1, HIGH);
  digitalWrite(DC_Right2, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}
void turnLeft()
{
  digitalWrite(DC_Left1, LOW);
  digitalWrite(DC_Left2, HIGH);
  digitalWrite(DC_Right1, HIGH);
  digitalWrite(DC_Right2, LOW);
  analogWrite(ENA, 125);
  analogWrite(ENB, 255);
}
void turnRight()
{
  digitalWrite(DC_Left1, HIGH);
  digitalWrite(DC_Left2, LOW);
  digitalWrite(DC_Right1, LOW);
  digitalWrite(DC_Right2, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 125);
}
void stop()
{
  digitalWrite(DC_Left1, LOW);
  digitalWrite(DC_Left2, LOW);
  digitalWrite(DC_Right1, LOW);
  digitalWrite(DC_Right2, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
