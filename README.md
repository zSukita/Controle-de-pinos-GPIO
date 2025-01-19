# -Controle-de-pinos-GPIO

# -Com o auxílio do simulador de eletrônica Wokwi, utilize um 
teclado matricial 4x4 (ilustrado na Figura 1) para controlar 
determinados pinos GPIO do microcontrolador RP2040, 
presente na placa de desenvolvimento Raspberry Pi Pico W. 
Para esta atividade, realize o acionamento de 03 LEDs (tipo 
RGB), juntamente com o controle do sinal sonoro de um buzzer. 
Nesta prática, será necessário simular os seguintes 
componentes: 
1) Teclado matricial 4x4. 
2) 03 LEDs – tipo RGB. 
3) Componente Buzzer. 
4) Microcontrolador Raspberry Pi Pico W. 



# Teclado e LEDs com Raspberry Pi Pico

Este projeto implementa o controle de LEDs e de um buzzer utilizando um teclado matricial conectado a um Raspberry Pi Pico. Dependendo da tecla pressionada, diferentes LEDs são acesos ou o buzzer é ativado.

## Recursos
- Controle de LEDs (verde, azul, vermelho) usando GPIOs.
- Ativação de um buzzer com a tecla `#`.
- Mapeamento e leitura de um teclado matricial 4x4.

## Hardware Necessário
- Raspberry Pi Pico
- Teclado matricial 4x4
- 3 LEDs (verde, azul, vermelho)
- Resistores (220 Ω recomendados para os LEDs)
- 1 Buzzer
- Protoboard e fios para conexão

## Conexões de Hardware

### Teclado Matricial
- **Linhas:** GPIO2, GPIO3, GPIO4, GPIO5
- **Colunas:** GPIO6, GPIO7, GPIO8, GPIO9

### LEDs
- **LED Verde:** GPIO11
- **LED Azul:** GPIO12
- **LED Vermelho:** GPIO13

### Buzzer
- **Buzzer:** GPIO21

## Compilação e Execução

### Requisitos
- [SDK do Raspberry Pi Pico](https://github.com/raspberrypi/pico-sdk) configurado
- Compilador `cmake` e `make`

### Passos
1. Clone ou copie o código para o seu ambiente de desenvolvimento:
   ```bash
   git clone https://github.com/seuprojeto/repo.git
   cd repo
   ```

2. Configure o SDK do Pico:
   ```bash
   export PICO_SDK_PATH=/caminho/para/pico-sdk
   ```

3. Compile o projeto:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Copie o arquivo `.uf2` gerado para o Raspberry Pi Pico conectado ao seu computador.

## Funcionamento

1. **Teclas Especiais:**
   - `A`: Liga o LED verde.
   - `B`: Liga o LED azul.
   - `C`: Liga o LED vermelho.
   - `D`: Liga todos os LEDs.
   - `#`: Ativa o buzzer por 500 ms.

2. **Reset:** Pressionar qualquer tecla diferente das mencionadas acima desliga todos os LEDs e o buzzer.
