/******************************************************************************
 * Archivo: gpio.c
 * Autor:   GFC
 * Breve:   Patrón de diseño ADT (Abstract Data Type, Tipo de Datos Abstracto),
 *          realizado en IdS, CESE-FIUBA.
 * Fecha:   Abril 2023
 *****************************************************************************/

/****** macros ***************************************************************/

#include <stdio.h>
#include "gpio.h"
#include "config.h"

/****** macros ***************************************************************/

#ifndef GPIO_COUNT
#define GPIO_COUNT 6
#endif

/****** estructuras **********************************************************/

struct gpio_s
{
    uint8_t port;
    uint8_t pin;
    bool output;
    bool alocated;
};

/****** declaración de funciones privadas ************************************/

gpio_t gpioAlocate(void);

/****** definición de funciones **********************************************/

gpio_t gpioAlocate (void) {
    // Reserva estática de memoria:
    // Se puede modificar la cantidad reservada 
    // mediante la modificación del parámetro en config.h.
    static struct gpio_s instances[GPIO_COUNT] = {0};
    
    // Recorremos vector-estructura para ver cuál está libre
    uint8_t elegido = GPIO_COUNT;
    for (uint8_t i=0; i < GPIO_COUNT; i++) {
        if (instances[i].alocated == false) {
            elegido = i;
            break;
        }
    }

    // Devuelvo lo que encontré:
    if (elegido < GPIO_COUNT) {
        return &instances[elegido];
    } else {
        return NULL;
    }
}

gpio_t gpioCreate (uint8_t port, uint8_t pin, bool output)
{
    /* Asignamos memoria para la estructura y me quedo con el puntero */
    gpio_t result = gpioAlocate();
        // Si asignáramos memoria dinámica sería:
        // gpio_t result = maloc(sizeof(struct gpio_s));
        // (Ojo! Tener presente qué OS usamos.)
    if ( NULL == result ) return NULL;  // Si no hay más memoria...
                                        // Podríamos dar mensaje de error.
    result->port = port;
    result->pin = pin;
    result->output = output;

    /* Lo configuro como entrada */
    // Bla bla bla... Depende del hardware.

    /* Devuelvo puntero a estructura, ya inicializada */
    return result;
}

bool gpioGetValue (gpio_t output)
{
    // Este código es una emulación que 
    // no hace más que leer un caracter de teclado.
    char entrada[20];
    scanf("%s", entrada);
    char tecla = entrada[0];
    bool salida = false;
    if ( tecla == 's' || tecla == 'S' ) salida = true;
    return salida;
}

bool gpioSetValue (gpio_t output, bool value)
{
    // Este código es una emulación que 
    if ( true == value ) {
        printf("Botón presionado.\n\n");
    } else {
        printf("Botón no presionado.\n\n");
    }
    return true;
}
