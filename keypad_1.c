#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"


void imprimir_binario(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        (num & (1 << i)) ? printf("1") : printf("0");
    }
}

