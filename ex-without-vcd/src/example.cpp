#include <Arduino.h>

uint8_t count=0;

void setup(void)
{
  pinMode(13, OUTPUT);
}

void loop(void)
{
  count++;
  digitalWrite(13, HIGH);
  delay(1);
  digitalWrite(13, LOW);
  delay(1);
}
