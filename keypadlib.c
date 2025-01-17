#include "pico/stdlib.h"

void keypad_init()
{
    // inicializa as GPIO's - GPIO2 à GPIO9
    gpio_init_mask((0xFF << 2));

}