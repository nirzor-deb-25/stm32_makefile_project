#include "led.h"
#include "button.h"
#include "timing.h"

#define SLOW_INTERVAL_MS 500U
#define FAST_INTERVAL_MS 100U

int main(void)
{
    bool fast_mode = false;
    bool green_on = true;
    bool previous_pressed = false;

    led_init();
    timing_init();
    button_init();

    led_green_set(green_on);

    uint32_t last_toggle_ms = timing_millis();

    while (1)
    {
        uint32_t now_ms = timing_millis();

        button_update(now_ms);
        bool pressed = button_is_pressed();

        led_blue_set(pressed);

        /* Change speed once per debounced button press. */
        if (pressed && !previous_pressed)
        {
            fast_mode = !fast_mode;
            green_on = true;
            led_green_set(green_on);
            last_toggle_ms = now_ms;
        }

        previous_pressed = pressed;

        uint32_t interval_ms = fast_mode
                             ? FAST_INTERVAL_MS
                             : SLOW_INTERVAL_MS;

        if ((uint32_t)(now_ms - last_toggle_ms) >= interval_ms)
        {
            last_toggle_ms = now_ms;
            green_on = !green_on;
            led_green_set(green_on);
        }
    }
}