#ifndef KEYPADLIB
#define KEYPADLIB

#include <stdint.h>

/**
 * @brief Função que realiza a inicialização e configurações iniciais das GPIOs do teclado
 * @note Essa função realiza suas configurações utilizando funções com recursos de máscaras.
 * @note Um dos recursos aplicados foi o bit shift à esquerda a fim de fornecer o ajuste necessário para correspondência com layout do teclado
 */
void keypad_init(); 
 
/**
 * @brief Função que realiza a leitura e identificação das teclas de um teclado
 * @note O layout do teclado deverá ser 4 X 4 com 16 teclas, outras configurações necessitarão de alterações adicionais
 * @note A sequência no mapa de códigos abaixo é um exemplo de como a biblioteca pode ser utilizada:
 * @note
 * @note #define NUM_KEYS 16
 * @note uint8_t keymap[NUM_KEYS] = {0x28, 0x11, 0x21, 0x41, 0x12, 0x22, 0x42, 0x14, 0x24, 0x44, 0x81, 0x82, 0x84, 0x88, 0x18, 0x48};
 * 
 * @note Com a ajuda do printf a representação dos mapa acima pode ser visualizada para efeitos de debugging
 *
 * @note printf("decimal :: %d :: hexadecimal %x :: binário :: %08b\n", key, key, key);
 *
 * @note Exemplo de layout de teclado aplicável ao código
 *
 *    1,  2,  3,   A,
 *
 *    4,  5,  6,   B,
 *
 *    7,  8,  9,   C,
 *
 *  '*',  0,  # ,  D
 *
 * @note Números inteiros que devem ser retornados com a aplicação do mapa de exemplo
 *
 *  1, 2,  3, 10,
 *
 *  4, 5,  6, 11,
 *
 *  7, 8,  9, 12,
 *
 * 14, 0, 15, 13
 *
 *
 * @note Números hexadecimais que devem ser retornados com a aplicação do mapa de exemplo
 *
 *  1, 2, 3, a,
 *
 *  4, 5, 6, b,
 *
 *  7, 8, 9, c,
 *
 *  e, 0, f, d
 *
 */
int keypad_reader(uint8_t *keymap);

#endif