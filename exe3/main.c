#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    stdio_init_all();

    const int BTN_PIN_RED = 28;
    const int BTN_PIN_GREEN = 26;
    const int LED_PIN_R = 4;
    const int LED_PIN_G = 6;

    int flag_red = 0;
    int flag_green = 0;

    gpio_init(BTN_PIN_RED);
    gpio_set_dir(BTN_PIN_RED, GPIO_IN);
    gpio_pull_up(BTN_PIN_RED);

    gpio_init(BTN_PIN_GREEN);
    gpio_set_dir(BTN_PIN_GREEN, GPIO_IN);
    gpio_pull_up(BTN_PIN_GREEN);

    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    gpio_put(LED_PIN_R, 0);

    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_G, GPIO_OUT);
    gpio_put(LED_PIN_G, 0);

    while (true) {
        if (!gpio_get(BTN_PIN_RED)) {
            sleep_ms(200);
            while (!gpio_get(BTN_PIN_RED));
            flag_red = !flag_red;
            gpio_put(LED_PIN_R, flag_red);
        }

        if (!gpio_get(BTN_PIN_GREEN)) {
            sleep_ms(200);
            while (!gpio_get(BTN_PIN_GREEN));
            flag_green = !flag_green;
            gpio_put(LED_PIN_G, flag_green);
        }
        
    }
}
