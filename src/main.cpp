#include <Arduino.h>
#include <7seg.h>

static const int ON_DURATION_MS = 30000;
static const int OFF_DURATION_MS = 30000;

void setup() {
  pinMode(PIN1, INPUT);
  pinMode(PIN2, INPUT);
  pinMode(PIN3, INPUT);
  pinMode(PIN4, INPUT);
  pinMode(PIN5, INPUT);
  pinMode(PIN6, INPUT);
  pinMode(PIN7, INPUT);
}

void loop() {
  display_digit(A, (millis()/1000) % 10);
  display_digit(B, (millis()/1000) % 10);
  display_digit(C, (millis()/1000) % 10);
  display_digit(D, (millis()/1000) % 10);
}
