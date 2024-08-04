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

/* These Macros toggle certain LEDs connected to certain pins*/
#define PA15_red (*(volatile unsigned int*)(0x40020014)) ^= (1U << (15))
#define PB15_blue (*(volatile unsigned int*)(0x40020414)) ^= (1U << (15))
#define PC15_orange (*(volatile unsigned int*)(0x40020814)) ^= (1U << (15))

#include "tp.h"
#include "tpl_os.h"

//simple Delay function
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
//-------------------------------------------
#define APP_Task_Task1_START_SEC_CODE
#include "tpl_memmap.h"

uint32_t Global_Task1_Count = 0;


TASK(Task1)
{
	uint8_t Local_Error_Code = 0;

	// Do Some Job //
	while(Global_Task1_Count++ < 100)
	{
		PA15_red;
		mydelay(100);

	}


	Local_Error_Code = ActivateTask(Task2); // Scheduler will run Task2 //

	// Do Some Job //
	while(Global_Task1_Count++ < 200)
	{
		PA15_red;
		mydelay(100);

	}

	Local_Error_Code = TerminateTask();

}
#define APP_Task_Task1_STOP_SEC_CODE

//=============================================================//

#define APP_Task_Task2_START_SEC_CODE
#include "tpl_memmap.h"

uint32_t Global_Task2_Count = 0;

TASK(Task2)
{

	// Do Some Job //
	while(Global_Task2_Count++ < 100)
	{
		PB15_blue;
		mydelay(100);

	}

	ActivateTask(Task3); // Scheduler will run Task3 //

	TerminateTask(); // Scheduler will run Task1 //

}
#define APP_Task_Task2_STOP_SEC_CODE

//=============================================================//

#define APP_Task_Task3_START_SEC_CODE
#include "tpl_memmap.h"

uint32_t Global_Task3_Count = 0;

TASK(Task3)
{

	// Do Some Job //
	while(Global_Task3_Count++ < 100)
	{
		PC15_orange;
		mydelay(100);

	}
	ActivateTask(Task1); // Scheduler will run Task1 //
	TerminateTask(); // Scheduler will run Task1 //

}
#define APP_Task_Task3_STOP_SEC_CODE

//-------------------------------------------


/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
		{
		}

