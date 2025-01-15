#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define GPIO_LED_BLUE 11
#define GPIO_LED_RED 12
#define GPIO_LED_GREEN 13
#define GPIO_BUZZER 21

uint columns[4] = {6, 7, 8, 9}; 
uint rows[4] = {2, 3, 4, 5};

char KEY_MAP[16] = {
    '1', '2' , '3', 'A',
    '4', '5' , '6', 'B',
    '7', '8' , '9', 'C',
    '*', '0' , '#', 'D'
};

uint _columns[4];
uint _rows[4];
char _matrix_values[16];
uint all_columns_mask = 0x0;
uint column_mask[4];

void imprimir_binario(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        (num & (1 << i)) ? printf("1") : printf("0");
    }
}

