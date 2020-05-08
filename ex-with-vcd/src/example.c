#include <Arduino.h>
#include <simavr/avr/avr_mcu_section.h>

AVR_MCU(F_CPU, "atmega328");
const struct avr_mmcu_vcd_trace_t _mytrace[]  _MMCU_ = {
  { AVR_MCU_VCD_SYMBOL("LED"), .mask = (1 << 5), .what = (void*)&PORTB}
};

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
