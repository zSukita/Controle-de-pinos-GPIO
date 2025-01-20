#include "keypadlib.h"
#include <stdio.h>
#include "pico/stdlib.h"
// #include "hardware/timer.h"

#define GPIO_LED_GREEN 11
#define GPIO_LED_BLUE 12
#define GPIO_LED_RED 13
#define GPIO_BUZZER 21


void init_hardware()
{
    // Configuração dos LEDs como saída
    // gpio_init(GPIO_LED_BLUE);
    // gpio_set_dir(GPIO_LED_BLUE, GPIO_OUT);
    // gpio_init(GPIO_LED_RED);
    // gpio_set_dir(GPIO_LED_RED, GPIO_OUT);
    // gpio_init(GPIO_LED_GREEN);
    // gpio_set_dir(GPIO_LED_GREEN, GPIO_OUT);

    // // Configuração do buzzer como saída
    // gpio_init(GPIO_BUZZER);
    // gpio_set_dir(GPIO_BUZZER, GPIO_OUT);

    keypad_init();
} 

// Função para fazer o buzzer tocar
void beep(int duration_ms)
{
    // absolute_time_t end_time = make_timeout_time_ms(duration_ms);
    // while (absolute_time_diff_us(get_absolute_time(), end_time) > 0)
    // {
    //     gpio_put(GPIO_BUZZER, 1);
    //     sleep_us(500); // Meio período em nível alto
    //     gpio_put(GPIO_BUZZER, 0);
    //     sleep_us(500); // Meio período em nível baixo
    // }
}

int main()
{
    stdio_init_all();
    uint8_t keymap[16] = {0x28, 0x11, 0x21, 0x41, 0x12, 0x22, 0x42, 0x14, 0x24, 0x44, 0x81, 0x82, 0x84, 0x88, 0x18, 0x48};

    init_hardware();

    int key;

    while (true)
    {
        key = keypad_reader(keymap);
        if (key != -1)
        {
            // printf("[DECIMAL] %d [HEXADECIMAL] %x [BINARIO] %04b\n", key, key, key); // DEBUGGING
            printf("Tecla pressionada: %d\n", key);
            sleep_ms(100); // ajuste deboucing

            switch (key)
            {
            case 10:
                gpio_put(GPIO_LED_GREEN, 1);
                sleep_ms(100);
                break;
            case 11:
                gpio_put(GPIO_LED_BLUE, 1);
                sleep_ms(100);
                break;
            case 12:
                gpio_put(GPIO_LED_RED, 1);
                sleep_ms(100);
                break;
            case 13:
                gpio_put(GPIO_LED_GREEN, 1);
                gpio_put(GPIO_LED_BLUE, 1);
                gpio_put(GPIO_LED_RED, 1);
                sleep_ms(100);
                break;
            case 15:
                gpio_put(GPIO_BUZZER, 1);
                beep(500); // Toca o buzzer por 500ms
                sleep_ms(500);
            default:
                break;
            }
        }
        else
        {
            gpio_put(GPIO_LED_GREEN, 0);
            gpio_put(GPIO_LED_BLUE, 0);
            gpio_put(GPIO_LED_RED, 0);
            gpio_put(GPIO_BUZZER, 0);
        }
        //    break; // DEBUGGING
    }
}


// CÓDIGO ATUAL ORIGINAL /////////////////////////////
/*
uint columns[4] = {6, 7, 8, 9};
uint rows[4] = {2, 3, 4, 5};

// Mapeamento das teclas
char KEY_MAP[16] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'
};

// Variáveis para máscaras e estado do teclado
uint all_columns_mask = 0x0;
uint column_mask[4];

// Função para fazer o buzzer tocar
void beep(int duration_ms) {
    absolute_time_t end_time = make_timeout_time_ms(duration_ms);
    while (absolute_time_diff_us(get_absolute_time(), end_time) > 0) {
        gpio_put(GPIO_BUZZER, 1);
        sleep_us(500);  // Meio período em nível alto
        gpio_put(GPIO_BUZZER, 0);
        sleep_us(500);  // Meio período em nível baixo
    }
}

// Função para imprimir valor binário (depuração)
void imprimir_binario(int num)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%c", (num & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

// Função para inicializar as máscaras do teclado
void init_keypad_masks(uint columns[4])
{
    for (int i = 0; i < 4; i++)
    {
        column_mask[i] = 1 << columns[i];
        all_columns_mask |= column_mask[i];
    }
}

// Função para obter a tecla pressionada
char keypad_get_key()
{
    uint32_t cols;
    int row;

    // Ligar todas as linhas
    for (int j = 0; j < 4; j++)
    {
        gpio_put(rows[j], 1);
    }

    // Ler o estado das colunas
    cols = gpio_get_all() & all_columns_mask;
    if (cols == 0x0) // Nenhuma tecla pressionada
    {
        return 0;
    }

    // Desligar todas as linhas para iniciar a varredura
    for (int j = 0; j < 4; j++)
    {
        gpio_put(rows[j], 0);
    }

    // Varredura das linhas
    for (row = 0; row < 4; row++)
    {
        gpio_put(rows[row], 1);  // Ativar a linha atual
        busy_wait_us(1000);     // Pequeno atraso para estabilizar a leitura
        cols = gpio_get_all() & all_columns_mask;

        if (cols != 0x0) // Se alguma coluna estiver ativa
        {
            break;
        }
        gpio_put(rows[row], 0); // Desativar a linha atual
    }

    // Reativar todas as linhas
    for (int j = 0; j < 4; j++)
    {
        gpio_put(rows[j], 1);
    }

    // Verificar qual coluna está ativa
    for (int col = 0; col < 4; col++)
    {
        if (cols == column_mask[col])
        {
            return KEY_MAP[row * 4 + col];
        }
    }

    // Caso múltiplas colunas estejam ativas (erro)
    return 0;
}

// Função para inicializar o hardware e configurar os pinos GPIO
void init_hardware()
{
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

    // Inicializar teclado
    for (int i = 0; i < 4; i++)
    {
        gpio_init(columns[i]);
        gpio_set_dir(columns[i], GPIO_IN);
        gpio_pull_down(columns[i]);

        gpio_init(rows[i]);
        gpio_set_dir(rows[i], GPIO_OUT);
        gpio_put(rows[i], 1);
    }

    // Inicializar máscaras do teclado
    init_keypad_masks(columns);
}

int main()
{
    stdio_init_all();
    init_hardware();

    char caracter_press;

    while (true)
    {
        // Obter a tecla pressionada
        caracter_press = keypad_get_key();

        if (caracter_press)
        {
            printf("Tecla pressionada: %c\n", caracter_press);

            // Laço de repetição para que ao manter pressionado as teclas A, B, C e D os LEDs acendam, já o # é para ligar o buzzer
            if (caracter_press == 'A')
            {
                gpio_put(GPIO_LED_GREEN, 1);
            }
            else if (caracter_press == 'B')
            {
                gpio_put(GPIO_LED_BLUE, 1);
            }
            else if (caracter_press == 'C')
            {
                gpio_put(GPIO_LED_RED, 1);
            }
            else if (caracter_press == 'D')
            {
                gpio_put(GPIO_LED_GREEN, 1);
                gpio_put(GPIO_LED_BLUE, 1);
                gpio_put(GPIO_LED_RED, 1);
            }
            else if (caracter_press == '#')
            {
                gpio_put(GPIO_BUZZER, 1);
                beep(500);  // Toca o buzzer por 500ms
                sleep_ms(500);
            }
        }
        else
        {
            // Desligar todos os LEDs e o buzzer se nenhuma tecla estiver pressionada
            gpio_put(GPIO_LED_GREEN, 0);
            gpio_put(GPIO_LED_BLUE, 0);
            gpio_put(GPIO_LED_RED, 0);
            gpio_put(GPIO_BUZZER, 0);
        }

        busy_wait_us(500000); // Pequeno atraso entre leituras
    }
}
*/
