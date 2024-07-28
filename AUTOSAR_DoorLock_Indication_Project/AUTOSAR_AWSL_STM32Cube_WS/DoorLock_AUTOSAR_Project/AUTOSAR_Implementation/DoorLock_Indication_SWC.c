/*
 * DoorLock_Indication_SWC.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Bendary
 */

#include "RTE_Generated/Rte_DoorLock_Indication_SWC.h"


#define LEDON   0
#define LEDOFF  1

void DoorLock_Indication_Runnable(void)
{

 unsigned char DoorState = 0;

 /* Read the Door state from the SR interface sent by the ECU abstraction SWC */
 DoorState = Rte_IRead_DoorLock_Indication_SWC_DoorLock_Indication_Runnable_RP_SR_DoorState_DoorLock_State();

 /* Applying the algorithm to check whether the Door state is high or low */
 if(DoorState)
 {
	/* Door is opened */
	/* Invoke operation of "Led_Switch(LEDState)" in the ECU abstraction */
	Rte_Call_DoorLock_Indication_SWC_RP_CS_LedSwitch_LED_Switch(LEDON);

 }

 else
 {
	/* Door is closed */
	/* Invoke operation of "Led_Switch(LEDState)" in the ECU abstraction */
	Rte_Call_DoorLock_Indication_SWC_RP_CS_LedSwitch_LED_Switch(LEDOFF);
 }
}

