#include <stdio.h>
#include "pico/stdlib.h"


//Função responsável por inicializar o pino do buzzer 
void init_buzzer(uint pin_buzzer, uint botao){
    gpio_init(pin_buzzer); 
    gpio_set_dir(pin_buzzer, GPIO_OUT);
    stdio_init_all();
}


// Função para gerar som no buzzer por um tempo específico e com a frequência desejada
void buzzer_on(uint buzzer_pin, float frequency, uint duration_ms) {
    float period = 1.0f / frequency;       // Período da onda quadrada
    float half_period = period / 2;        // Meio período em segundos
    uint cycles = (uint)((duration_ms / 1000.0f) / period); // Número de ciclos

    for (uint i = 0; i < cycles; i++) {
        gpio_put(buzzer_pin, 1);           // Seta o pino como HIGH
        sleep_us((int)(half_period * 1e6)); // Espera pelo meio período
        gpio_put(buzzer_pin, 0);           // Seta o pino como LOW
        sleep_us((int)(half_period * 1e6)); // Espera pelo meio período
    }
}


int main()
{
    init_buzzer(21, 13);
    while (true) {
        buzzer_on(21, 440, 250);

        sleep_ms(1000);
    }
}
