/*
 * AUTOSAR IN Depth Materials
 * www.learn-in-depth.com
 * Eng.Keroles Shenouda
 * eng.keroles.karam@gmail.com
 *
 */


//    PA15   (*(unsigned int*)(0x40020014)) >> 15
//    PB15   (*(unsigned int*)(0x40020414)) >> 15
//    PC15   (*(unsigned int*)(0x40020814)) >> 15
//    PD15:  (*(unsigned int*)(0x40020C14)) >> 15


#define PA15_red (*(volatile unsigned int*)(0x40020014)) ^= (1U << (15))
#define PB15_blue (*(volatile unsigned int*)(0x40020414)) ^= (1U << (15))
#define PC15_orange (*(volatile unsigned int*)(0x40020814)) ^= (1U << (15))

#include "tp.h"
#include "tpl_os.h"
//simple mydelay function
void mydelay(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms;i++)
	{
	}
}



FUNC(int, OS_APPL_CODE) main(void)
		{
	initBoard();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
		}
//------------------Init Task-------------------------
#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task1)
{

	//init HW (Sensor/Actuator)

	TerminateTask();

}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------------------
unsigned char  DetectError(volatile unsigned char Error)
{
	volatile unsigned char Err =0;
	switch (Error)
	{
	case E_OK:
		break;
	case E_OS_NOFUNC:
		//	 * E_OS_NOFUNC: Alarm <alarm_id> is already in use (Standard & Extended)
		Err++;
		break;
	case E_OS_ID:
		//	 * E_OS_ID: <alarm_id> is invalid (Extended)
		Err++;
		break;
	case E_OS_VALUE:
	//	E_OS_VALUE: <increment> out of bounds (Extended)
	//	 E_OS_VALUE: <cycle> out of bounds (Extended)
		Err++;
		break;

	}
	return Err;
}
//-------------------------------------------------------
#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task2)
{
	DetectError(SetAbsAlarm(orangeLed_Alarm,400,0));

	PB15_blue ; //toggle blue led
	TerminateTask();

}
#define APP_Task_task2_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------------------

//-------------------------------------------------------
#define APP_Task_task3_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task3)
{

	PC15_orange; //toggle orange led
	TerminateTask();

}
#define APP_Task_task3_STOP_SEC_CODE
#include "tpl_memmap.h"
//-------------------------------------------------------
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
		{
		}

