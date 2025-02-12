#include "hardware/gpio.h"
#include "pico/stdlib.h"

int main() {
    const int LED_PIN_R = 5;
    const int LED_PIN_Y = 28;

    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    gpio_put(LED_PIN_R, 0);

    gpio_init(LED_PIN_Y);
    gpio_set_dir(LED_PIN_Y, GPIO_OUT);
    gpio_put(LED_PIN_Y, 0);

    while (true) {
        gpio_put(LED_PIN_R, 1);
        gpio_put(LED_PIN_Y, 1);
        sleep_ms(10);  

        gpio_put(LED_PIN_R, 0);
        gpio_put(LED_PIN_Y, 0);
        sleep_ms(20);  

        gpio_put(LED_PIN_R, 1);
        gpio_put(LED_PIN_Y, 1);
        sleep_ms(20); 
    }

    return 0;
}
