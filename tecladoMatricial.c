#include <stdio.h>
#include "pico/stdlib.h"

// Função responsável por inicializar o pino do buzzer
void init_buzzer(uint pin_buzzer, uint botao)
{
    gpio_init(pin_buzzer);
    gpio_set_dir(pin_buzzer, GPIO_OUT);
    stdio_init_all();
}

// Função para gerar som no buzzer por um tempo específico e com a frequência desejada
void buzzer_on(uint buzzer_pin, float frequency, uint duration_ms)
{
    float period = 1.0f / frequency;                        // Período da onda quadrada
    float half_period = period / 2;                         // Meio período em segundos
    uint cycles = (uint)((duration_ms / 1000.0f) / period); // Número de ciclos

    for (uint i = 0; i < cycles; i++)
    {
        gpio_put(buzzer_pin, 1);            // Seta o pino como HIGH
        sleep_us((int)(half_period * 1e6)); // Espera pelo meio período
        gpio_put(buzzer_pin, 0);            // Seta o pino como LOW
        sleep_us((int)(half_period * 1e6)); // Espera pelo meio período
    }
}
// Definição do teclado
uint columns[4] = {4, 3, 2, 1};
uint rows[4] = {8, 7, 6, 5};

char KEY_MAP[16] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'};

uint all_columns_mask = 0x0;
uint column_mask[4];

// Função que inicializa o teclado
void pico_keypad_init(void)
{
    for (int i = 0; i < 4; i++)
    {
        gpio_init(columns[i]);
        gpio_pull_up(columns[i]);
        gpio_set_dir(columns[i], GPIO_IN);
        all_columns_mask |= (1 << columns[i]);
        column_mask[i] = (1 << columns[i]);

        gpio_init(rows[i]);
        gpio_set_dir(rows[i], GPIO_OUT);
        gpio_put(rows[i], 1);
    }
}

// Função que capta as teclas digitadas
char pico_keypad_get_key(void)
{
    for (int row = 0; row < 4; row++)
    {
        gpio_put(rows[row], 0);
        busy_wait_us(100);

        uint32_t cols = gpio_get_all() & all_columns_mask;

        gpio_put(rows[row], 1);

        if (cols != all_columns_mask)
        {
            for (int col = 0; col < 4; col++)
            {
                if ((cols & column_mask[col]) == 0)
                {
                    return KEY_MAP[row * 4 + col];
                }
            }
        }
    }

    return 0;
}

// void ledOn(char key) {
//     if (key >= '0' && key <= '9') {
//         gpio_put(?, true);
//         sleep_ms(?);
//         gpio_put(?, false);
//     }
//     else if (key >= 'A' && key <= 'D') {
//         gpio_put(?, true);
//         sleep_ms(?);
//         gpio_put(?, false);
//     }
// }

int main()
{
    stdio_init_all();
    pico_keypad_init();
    char last_key = 0;
    // Buzzer fora do while para fins de teste do teclado - sujeito a alteração - toca apenas uma vez
    init_buzzer(21, 13);
    while (true)
    {

        // Teste do teclado - sujeito a alterações - imprime as teclas digitadas
        char caracter_press = pico_keypad_get_key();
        if (caracter_press == '#' || caracter_press == '*' && caracter_press != last_key)
        {
            last_key = caracter_press;
            printf("\nTecla pressionada: %c\n", caracter_press);
            buzzer_on(21, 440, 250);
            sleep_ms(1000);
        }
        else if (!caracter_press)
        {
            last_key = 0;
        }
        if (caracter_press && caracter_press != last_key)
        {
            last_key = caracter_press;
            printf("\nTecla pressionada: %c\n", caracter_press);
        }
        else if (!caracter_press)
        {
            last_key = 0;
        }
    }
}
