#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    stdio_init_all();

    const int BTN_PIN_RED = 28;
    const int LED_RED = 5;
    const int LED_PURPLE = 8;
    const int LED_BLUE = 11;
    const int LED_GREEN = 15;

    gpio_init(BTN_PIN_RED);
    gpio_set_dir(BTN_PIN_RED, GPIO_IN);
    gpio_pull_up(BTN_PIN_RED);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);

    gpio_init(LED_PURPLE);
    gpio_set_dir(LED_PURPLE, GPIO_OUT);
    gpio_put(LED_PURPLE, 0);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, 0);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    while (true) {
        if (!gpio_get(BTN_PIN_RED)) {
            sleep_ms(200);
            while (!gpio_get(BTN_PIN_RED));

            gpio_put(LED_RED, 1);
            sleep_ms(300);
            gpio_put(LED_RED, 0);

            gpio_put(LED_PURPLE, 1);
            sleep_ms(300);
            gpio_put(LED_PURPLE, 0);

            gpio_put(LED_BLUE, 1);
            sleep_ms(300);
            gpio_put(LED_BLUE, 0);

            gpio_put(LED_GREEN, 1);
            sleep_ms(300);
            gpio_put(LED_GREEN, 0);
        }
    }
}
