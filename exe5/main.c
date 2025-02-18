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

    int contador_1 = 0;
    int contador_2 = 0;

    while (true) {

            if (!gpio_get(BTN_PIN)) { 
                ++contador_1;
                printf("Botao 1: %d\n", contador_1);
                sleep_ms(100);
            }

            if (!gpio_get(BTN_PIN_2)) {
                ++contador_2;
                printf("Botao 2: %d\n",contador_2);
                sleep_ms(100);
            }
        
        }
}
