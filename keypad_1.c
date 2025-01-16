#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos GPIO
#define GPIO_LED_GREEN 11
#define GPIO_LED_BLUE 12
#define GPIO_LED_RED 13
#define GPIO_BUZZER 21

uint columns[4] = {6, 7, 8, 9}; 
uint rows[4] = {2, 3, 4, 5};

void imprimir_binario(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        (num & (1 << i)) ? printf("1") : printf("0");
    }
}

// Função para inicializar o hardware e configurar os pinos GPIO
void init_hardware() {
    // Configuração dos LEDs como saída
    gpio_init(GPIO_LED_BLUE);
    gpio_set_dir(GPIO_LED_BLUE, GPIO_OUT);
    gpio_init(GPIO_LED_RED);
    gpio_set_dir(GPIO_LED_RED, GPIO_OUT);
    gpio_init(GPIO_LED_GREEN);
    gpio_set_dir(GPIO_LED_GREEN, GPIO_OUT);
    
    // Configuração do buzzer como saída
    gpio_init(GPIO_BUZZER);
    gpio_set_dir(GPIO_BUZZER, GPIO_OUT);
}

int main() {
    stdio_init_all();
    init_hardware();

    char caracter_press;

    while (true) {
        //Laço de repetição para que ao manter pressionado as teclas A, B, C e D os leds acendam, já o # é para ligar o buzzer
        if (caracter_press == 'A') {
            gpio_put(GPIO_LED_GREEN, 1);
        }

        else if (caracter_press == 'B') {
            gpio_put(GPIO_LED_BLUE, 1);
        } 

        else if (caracter_press == 'C') {
           gpio_put(GPIO_LED_RED, 1);
        } 

        else if (caracter_press == 'D') {
            gpio_put(GPIO_LED_GREEN, 1);
            gpio_put(GPIO_LED_BLUE, 1);
            gpio_put(GPIO_LED_RED, 1);
        }

        else if (caracter_press == '#') {
            gpio_put(GPIO_BUZZER, 1);
            sleep_ms(500);
        } 
        //Desliga os leds e o buzzer
        else {
            gpio_put(GPIO_LED_GREEN, 0);
            gpio_put(GPIO_LED_BLUE, 0);
            gpio_put(GPIO_LED_RED, 0);
            gpio_put(GPIO_BUZZER, 0);
        }
    }
}