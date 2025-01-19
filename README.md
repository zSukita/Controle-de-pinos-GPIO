<h1 align = "center">Controle de pinos GPIO com o 
emprego de um teclado matricial</h1>

<p align = "center">O objetivo deste projeto é desenvolver um sistema interativo utilizando o microcontrolador Raspberry Pi Pico, um teclado matricial 4x4, LEDs e um buzzer. A proposta é integrar os componentes de forma programável para que diferentes teclas acionem funcionalidades específicas, como o acionamento de LEDs e do buzzer.</p>

## Características

- Leitura de teclado matricial 4x4
- Controle de 3 LEDs (Verde, Azul e Vermelho)
- Sistema de buzzer para feedback sonoro
- Interface de depuração via serial

## Hardware Necessário

- Raspberry Pi Pico
- Teclado Matricial 4x4
- 3 LEDs (Verde, Azul e Vermelho)
- 1 Buzzer
- Resistores para os LEDs (conforme especificação dos LEDs utilizados)
- Jumpers para conexão

## Pinagem

### Teclado Matricial
- Colunas: GPIO 6, 7, 8, 9
- Linhas: GPIO 2, 3, 4, 5

### LEDs
- LED Verde: GPIO 11
- LED Azul: GPIO 12
- LED Vermelho: GPIO 13

### Buzzer
- GPIO 21

## Funcionalidades

O sistema possui as seguintes funcionalidades através das teclas:

- Tecla 'A': Acende o LED Verde
- Tecla 'B': Acende o LED Azul
- Tecla 'C': Acende o LED Vermelho
- Tecla 'D': Acende todos os LEDs
- Tecla '#': Ativa o buzzer por 500ms

## Mapa do Teclado

```
| 1 | 2 | 3 | A |
| 4 | 5 | 6 | B |
| 7 | 8 | 9 | C |
| * | 0 | # | D |
```

## Como Compilar e Executar

1. Configure o ambiente de desenvolvimento do Raspberry Pi Pico conforme a documentação oficial
2. Clone este repositório
3. Compile o projeto usando o CMake:
```bash
mkdir build
cd build
cmake ..
make
```
4. Copie o arquivo `.uf2` gerado para o Raspberry Pi Pico em modo de bootloader

## Estrutura do Código

O código está organizado da seguinte forma:

- `init_hardware()`: Inicializa todos os GPIOs e configurações necessárias
- `keypad_get_key()`: Realiza a leitura do teclado matricial
- `beep()`: Controla o buzzer
- `init_keypad_masks()`: Configura as máscaras de bits para leitura do teclado
- `main()`: Loop principal do programa

## Customização

### Ajustando o Tom do Buzzer

Para modificar a frequência do som emitido pelo buzzer, ajuste os valores de `sleep_us()` na função `beep()`:
- Valores menores produzem sons mais agudos
- Valores maiores produzem sons mais graves

Por exemplo:
```c
sleep_us(250);  // Som mais agudo
sleep_us(1000); // Som mais grave
```

## Depuração

O sistema inclui uma função de depuração `imprimir_binario()` que pode ser utilizada para verificar os estados dos pinos em formato binário através da saída serial.

## Limitações

- O sistema não suporta pressionamento simultâneo de múltiplas teclas
- O debounce é implementado através de delays simples

## Colaboradores

- Andressa Martins Santana Santos <br>
- Camille Rodrigues Costa <br>
- Erick dos Santos Rezende <br>
- Jobson Ressureição de Almeida <br>
- Lucas Silva de Souza <br>
