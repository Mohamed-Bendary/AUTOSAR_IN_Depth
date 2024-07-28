/*
 * DIO.h
 *
 *  Created on: Jul 6, 2024
 *      Author: dell
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

#include "stm32f103x8_gpio_driver.h"

/* Here We will implement  MCAL_DIO APIS compliant with AUTOSAR Schema
 * But still not fully AUTOSAR compliant till we get to the MCAL unit */

unsigned char DIO_ReadChannel   (unsigned char ID);
void          DIO_WriteChannel  (unsigned char ID , unsigned char Level);


// DIO IDs (PORTA) //
#define DIO_Door_ID    GPIO_PIN_3
#define LED_ID		   GPIO_PIN_7


// PORTS used //
#define GPIO_PORT_USED           GPIOA




#endif /* MCAL_DIO_H_ */
