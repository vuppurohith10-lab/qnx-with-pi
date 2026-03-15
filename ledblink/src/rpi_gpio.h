/*
 * rpi_gpio.h
 *
 *  Created on: Mar 15, 2026
 *      Author: rohith
 */

#ifndef RPI_GPIO_H_
#define RPI_GPIO_H_

#ifndef RPI_GPIO_H
#define RPI_GPIO_H

#define GPIO_OUT 1
#define GPIO_IN  0

#define GPIO_HIGH 1
#define GPIO_LOW  0

#define GPIO16 16

int rpi_gpio_setup(int pin, int mode);
int rpi_gpio_output(int pin, int value);

#endif

#endif /* RPI_GPIO_H_ */
