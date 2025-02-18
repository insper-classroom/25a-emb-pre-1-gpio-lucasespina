#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

int BTN_PIN = 7;
int BTN_PIN_2 = 26;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);

    int cnt_1 = 0;
    int cnt_2 = 0;

    while (true) {
        if (!gpio_get(BTN_PIN)) {
            sleep_ms(50); 
            if (!gpio_get(BTN_PIN)) { 
                while (!gpio_get(BTN_PIN)); 
                sleep_ms(50);
                printf("Botao 1: %d\n", ++cnt_1);
            }
        }

        if (!gpio_get(BTN_PIN_2)) {
            sleep_ms(50);
            if (!gpio_get(BTN_PIN_2)) {
                while (!gpio_get(BTN_PIN_2));
                sleep_ms(50);
                printf("Botao 2: %d\n", ++cnt_2);
            }
        }
    }
}
