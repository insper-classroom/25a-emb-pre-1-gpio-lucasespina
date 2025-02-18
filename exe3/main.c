#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BTN_PIN 26
#define BTN_PIN_2 7

void debounce(int pin) {
    sleep_ms(50);  // Aguarda um tempo para filtrar bouncing
    while (!gpio_get(pin));  // Espera o botão ser solto
    sleep_ms(50);  // Garante que não há bouncing residual
}

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
            debounce(BTN_PIN);  // Aplica debounce
            cnt_1++;
            printf("Botao 1: %d\n", cnt_1);
            fflush(stdout);
        }

        if (!gpio_get(BTN_PIN_2)) {
            debounce(BTN_PIN_2);  // Aplica debounce
            cnt_2++;
            printf("Botao 2: %d\n", cnt_2);
            fflush(stdout);
        }
    }

    return 0;
}
