#include "keypadlib.h"
#include "pico/stdlib.h"
#include <stdio.h>

#define GPIO_STARTER_PIN 2 // referente a primeira GPIO destinada ao teclado, localizada no pino 2
#define NUM_ROWS 4
#define NUM_KEYS 16

  static uint32_t keypad;
  static int key = -1;
  static uint8_t keypress = 0xF0;
  static uint scancodes[NUM_ROWS] = {0x01, 0x02, 0x04, 0x08};
 
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
  gpio_pull_down(7); // GPIO7
  gpio_pull_down(8); // GPIO8
  gpio_pull_down(9); // GPIO9

  //========================================== DEBUGGING
  // printf("Estado das GPIOs: ");
  // for (size_t a = 2; a < 10; a++)
  //     printf("%d", gpio_get(a));
  // printf("\nGPIOs que são pulled down: ");
  // for (size_t a = 2; a < 10; a++)
  //     printf("%d", gpio_is_pulled_down(a));
  // printf("\nGPIOs que são pulled up: ");
  // for (size_t a = 2; a < 10; a++)
  //     printf("%d", gpio_is_pulled_up(a));
  // printf("\nDireção das GPIOs: ");
  // for (size_t a = 2; a < 10; a++)
  //     printf("%d", gpio_get_dir(a));
  // printf("\n");
}
 
int keypad_reader(uint8_t *keymap)
{
  for (key = 0; key < NUM_ROWS; key++)
  {
    // define o nível 1 em todas as entradas e saídas - rows and columns
    gpio_put_masked((0xF << GPIO_STARTER_PIN), (scancodes[key] << GPIO_STARTER_PIN));

    sleep_ms(15); // ajuste debouncing

    // ler o valor do keymap
    keypad = ((gpio_get_all() >> GPIO_STARTER_PIN) & 0xFF);

    // interrompe o loop quando uma tecla é pressionada
    if (keypad & keypress)
    {
      // DEBUGGING: Retorna a posição na matriz da tecla pressionada
      //           caso a soma entre os binários - keypad e keypress - seja 1
      // printf("[keypress] %b & %08b [COL/ROW]\n", keypress, keypad);
      // printf("[KEYPAD] %b\n", keypad);
      break;
    }

    // se tiver pressionado uma tecla
    if (keypad & keypress)
    {
      // validar o keymap.
      for (key = 0; key < NUM_KEYS; key++)
      {
        // printf("%x\n",keymap[key]);//DEBUGGING
        if (keypad == keymap[key])
        {
          // printf("%x\n",keypad);//DEBUGGING
          break; // finaliza o laço quando encontra correspondência da tecla
        }
      }
      //  valor do keymap inválido
      if (key == NUM_KEYS)
      {
        return -1;
      }
    }
    // contramedida para tecla não pressionada
    else
      return -1;
  }

  sleep_ms(30); // ajuste debouncing
  return key;
}