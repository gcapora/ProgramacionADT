/******************************************************************************
 * Archivo: main.c
 * Autor:   GFC
 * Breve:   Patrón de diseño ADT (Abstract Data Type, Tipo de Datos Abstracto),
 *          realizado en IdS, CESE-FIUBA.
 * Fecha:   Abril 2023
 *****************************************************************************/

#include <stdio.h>
#include "main.h"
#include "gpio.h"

int main(void) {
    gpio_t led_rojo = gpioCreate(1, 2, true);
    gpio_t tecla = gpioCreate (1, 7, false);
    printf("Reconozco 'S' o 's' como botón presionado.\n");
    printf("Ingresa un caracter y luego 'Entrar'.\n\n");

    while (true) {
        if (gpioGetValue(tecla) == true) 
        {
            gpioSetValue(led_rojo, true);
        } else {
            gpioSetValue(led_rojo, false);
        }
    }

    return 0;
}