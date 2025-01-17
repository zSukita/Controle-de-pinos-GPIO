#include "pico/stdlib.h"
#include <stdio.h>

void keypad_init()
{
  // inicializa as GPIO's - GPIO2 à GPIO9. O número 2 se refere a primeira GPIO no pino 2
  gpio_init_mask((0xFF << 2));

  // define as linhas (rows) como saída - GPIOs de 2 à 5
  gpio_set_dir_out_masked((0xF << 2));

  // define o nível lógico das saídas (linhas)
  gpio_put_masked((0xF << 2), (0x0 << 2));

  //
  printf("estado das GPIOs: ");
  for (size_t a = 2; a < 10; a++)
  {
    printf("%d", gpio_get(a));
  }
  printf("\ndireção das GPIOs: ");
  for (size_t a = 2; a < 10; a++)
  {
    printf("%d", gpio_get_dir(a));
  }
  printf("\n");
}
