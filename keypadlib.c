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

  // define as colunas como pull down
  gpio_pull_down(6); // GPIO6
  gpio_pull_down(5); // GPIO7
  gpio_pull_down(8); // GPIO8
  gpio_pull_down(9); // GPIO9

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
  printf("\nGPIOs que são pulled down: ");
  for (size_t a = 2; a < 10; a++)
  {
    printf("%d", gpio_is_pulled_down(a));
  }
  printf("\nGPIOs que são pulled up: ");
  for (size_t a = 2; a < 10; a++)
  {
    printf("%d", gpio_is_pulled_up(a));
  }
  printf("\n");
}
