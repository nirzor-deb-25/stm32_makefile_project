#ifndef LED_H
#define LED_H

#include <stdbool.h>

void led_init(void);
void led_green_set(bool on);
void led_blue_set(bool on);

#endif