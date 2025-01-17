#include "pico/stdlib.h"
#include <stdio.h>

// referente a primeira GPIO destinada ao teclado, localizada no pino 2
#define GPIO_STARTER_PIN 2

void keypad_init()
{
  // inicializa as GPIO's - GPIO2 à GPIO9
  gpio_init_mask((0xFF << GPIO_STARTER_PIN));

  // define as linhas (rows) como saída - GPIOs de 2 à 5
  gpio_set_dir_out_masked((0xF << GPIO_STARTER_PIN));

  // define o nível lógico das saídas (linhas)
  gpio_put_masked((0xF << GPIO_STARTER_PIN), (0x0 << GPIO_STARTER_PIN));

  // define as colunas como pull down
  gpio_pull_down(6); // GPIO6
  gpio_pull_down(5); // GPIO7
  gpio_pull_down(8); // GPIO8
  gpio_pull_down(9); // GPIO9

  // printf("estado das GPIOs: ");
  // for (size_t a = GPIO_STARTER_PIN; a < 10; a++)
  // {
  //   printf("%d", gpio_get(a));
  // }
  // printf("\ndireção das GPIOs: ");
  // for (size_t a = GPIO_STARTER_PIN; a < 10; a++)
  // {
  //   printf("%d", gpio_get_dir(a));
  // }
  // printf("\nGPIOs que são pulled down: ");
  // for (size_t a = GPIO_STARTER_PIN; a < 10; a++)
  // {
  //   printf("%d", gpio_is_pulled_down(a));
  // }
  // printf("\nGPIOs que são pulled up: ");
  // for (size_t a = GPIO_STARTER_PIN; a < 10; a++)
  // {
  //   printf("%d", gpio_is_pulled_up(a));
  // }
  // printf("\n");
}
