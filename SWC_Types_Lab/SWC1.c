#include "RTE_SWC1.h"

/* NOte that SUM is the runnable name defined in <SYMBOL> in ARXML */
void SUM()
{
unsigned short x =0 , y = 0;
unsigned int z = 0;
char status = 0;
	
/* Note that the RTE API is already defined in the RTE header for this SWC
   The API used we already discussed the arrangment (Port name_Variable) */	
status = RTE_Read_RPSUM_VAL1(&x);	
status = RTE_Read_RPSUM_VAL2(&y);

/* Berforming the algorithm of the SUM runnable */
z = x + y;

/* Sending the SUM to the user */
status = RTE_Write_PPSUM_SumResult(z);
	
	
	
}