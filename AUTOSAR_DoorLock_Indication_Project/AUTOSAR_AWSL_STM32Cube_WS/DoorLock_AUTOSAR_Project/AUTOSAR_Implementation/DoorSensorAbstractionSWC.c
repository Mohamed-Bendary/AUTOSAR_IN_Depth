/*
 * DoorSensorAbstractionSWC.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Bendary
 */

#include "RTE_Generated/Rte_DoorSensorAbstractionSWC.h"
#include "MCAL/DIO.h"

/*****************************************************
 * Port: 		PP_CS_LedSwitch
 * Interface:	IF_CS_LED
 * Operation:	LED_Switch
 *****************************************************/

#define LEDON   0
#define LEDOFF  1

Std_ReturnType LedSwitch_Runnable(myuint8 LED_State)
{

	if( (LED_State == LEDON) || (LED_State == LEDOFF) )
	{
		/* Activating the LED based on the client request */
		DIO_WriteChannel(LED_ID, LED_State);

		/* Returning the Error code (Success) */
		return RTE_E_IF_CS_LED_E_Ok;
	}
	else
	{
		/* Returning the Error code (Failure) */
		return RTE_E_IF_CS_LED_E_Not_Ok;
	}



}


/*****************************************************
 * Runnable: 	ReadDoorSensor
 * Period:		0.01
 *****************************************************/
void ReadDoorSensor_Runnable(void)
{
	uint8 DoorState = 0;

	/* Reading the Door sensor state */
	DoorState = DIO_ReadChannel(DIO_Door_ID);

	Rte_IWrite_DoorSensorAbstractionSWC_ReadDoorSensor_PP_SR_DoorSens_DoorLock_State(DoorState);


}
