#include <Arduino.h>
#include "7seg.h"

const int _0[] = {0, 1, 2, 3, 4, 5, -1};
const int _1[] = {1, 2, -1};
const int _2[] = {0, 1, 3, 4, 6, -1};
const int _3[] = {0, 1, 2, 3, 6, -1};
const int _4[] = {1, 2, 5, 6, -1};
const int _5[] = {0, 2, 3, 5, 6, -1};
const int _6[] = {0, 2, 3, 4, 5, 6, -1};
const int _7[] = {0, 1, 2, -1};
const int _8[] = {0, 1, 2, 3, 4, 5, 6, -1};
const int _9[] = {0, 1, 2, 3, 5, 6, -1};

const int *digits[] = {_0, _1, _2, _3, _4, _5, _6, _7, _8, _9};

void display_digit(const digit_display display, unsigned int number)
{
    int i = 0;
    const int *d = digits[number];

    while (d[i] >= 0)
    {
        // Write to the pins
        pinMode(display[d[i]].high_pin, OUTPUT);
        digitalWrite(display[d[i]].high_pin, HIGH);
        pinMode(display[d[i]].low_pin, OUTPUT);
        digitalWrite(display[d[i]].low_pin, LOW);

        delayMicroseconds(50);

        // Reset the pins
        pinMode(display[d[i]].high_pin, INPUT);
        digitalWrite(display[d[i]].high_pin, LOW);
        pinMode(display[d[i]].low_pin, INPUT);
        digitalWrite(display[d[i]].low_pin, LOW);

        delayMicroseconds(50);

        i++;
    }
}