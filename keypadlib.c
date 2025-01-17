#include "pico/stdlib.h"
#include <stdio.h>

void keypad_init()
{
    // inicializa as GPIO's - GPIO2 à GPIO9
    gpio_init_mask((0xFF << 2));




  for (size_t a = 2; a < 10; a++)
    {
        printf("%d", gpio_get(a));
    }
}