/*
 * DIO.c
 *
 *  Created on: Jul 6, 2024
 *      Author: dell
 */

#include "../../AUTOSAR_Implementation/MCAL/DIO.h"


unsigned char DIO_ReadChannel   (unsigned char ID)
{

	/* Just mapping the AUTOSAR named API to our implemented DIO */
	return MCAL_GPIO_ReadPin(GPIO_PORT_USED, ID);


}
void          DIO_WriteChannel  (unsigned char ID , unsigned char Level)
{
	/* Just mapping the AUTOSAR named API to our implemented DIO */
	MCAL_GPIO_WritePin(GPIO_PORT_USED, ID, Level);

}