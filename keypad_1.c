#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"


void imprimir_binario(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        (num & (1 << i)) ? printf("1") : printf("0");
    }
}

int main() {
    char caracter_press;

    while (true) {
        if (caracter_press == 'A') {
            //led
        } else if (caracter_press == 'B') {
            //led
        } else if (caracter_press == 'C') {
           //led
        } else if (caracter_press == 'D') {
            //3leds
        } else if (caracter_press == '1') {
            //buzzer
        } else {
            //desligar leds e buzzer
        }
    }
}