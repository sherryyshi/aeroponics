#include <Arduino.h>
#include <7seg.h>
#include <Encoder.h>
#include <pthread.h>

static const int ON_DURATION_MS = 30000;
static const int OFF_DURATION_MS = 30000;

Encoder encoder(34, 35);

volatile long position  = -999;

void *displayDigits(void * _)
{
  while (1) {
    int positionCopy = position;
    display_digit(A, (positionCopy / 1000));
    display_digit(B, (positionCopy % 1000) / 100);
    display_digit(C, (positionCopy % 100) / 10);
    display_digit(D, (positionCopy % 10));
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(PIN1, INPUT);
  pinMode(PIN2, INPUT);
  pinMode(PIN3, INPUT);
  pinMode(PIN4, INPUT);
  pinMode(PIN5, INPUT);
  pinMode(PIN6, INPUT);
  pinMode(PIN7, INPUT);

  pthread_t displayThread;
  int threadCreate = pthread_create(&displayThread, NULL, displayDigits, NULL);

  Serial.print("Thread create result: ");
  Serial.println(threadCreate);
}

void loop() {
  long newPosition = encoder.read();

  if (position != newPosition) {
    position = newPosition;
  }

  delay(10); // Long Running Code
}
