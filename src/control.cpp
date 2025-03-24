#include <Arduino.h>
#include "control.h"

void goStraight()
{
  digitalWrite(DC_Left1, HIGH);
  digitalWrite(DC_Left2, LOW);
  digitalWrite(DC_Right1, HIGH);
  digitalWrite(DC_Right2, LOW);
} 
void goBackward()
{
  digitalWrite(DC_Left1, LOW);
  digitalWrite(DC_Left2, HIGH);
  digitalWrite(DC_Right1, LOW);
  digitalWrite(DC_Right2, HIGH);
}

void turnLeft()
{
  digitalWrite(DC_Left1, LOW);
  digitalWrite(DC_Left2, HIGH);
  digitalWrite(DC_Right1, HIGH);
  digitalWrite(DC_Right2, LOW);
}
void turnRight()
{
  digitalWrite(DC_Left1, HIGH);
  digitalWrite(DC_Left2, LOW);
  digitalWrite(DC_Right1, LOW);
  digitalWrite(DC_Right2, HIGH);
}
