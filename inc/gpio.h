/******************************************************************************
 * Archivo: gpio.h
 * Autor:   GFC
 * Breve:   Patrón de diseño ADT (Abstract Data Type, Tipo de Datos Abstracto),
 *          realizado en IdS, CESE-FIUBA.
 * Fecha:   Abril 2023
 *****************************************************************************/

#ifndef IDS_GPIO_H
#define IDS_GPIO_H

/***** librerías y módulos ***************************************************/
#include <stdbool.h>
#include <stdint.h>

/***** definición de tipos ***************************************************/
typedef struct gpio_s * gpio_t;

/***** declaración de funciones públicas *************************************/
gpio_t gpioCreate (uint8_t port, uint8_t pin, bool output);
bool gpioGetValue (gpio_t output);
bool gpioSetValue (gpio_t output, bool value);

#endif
