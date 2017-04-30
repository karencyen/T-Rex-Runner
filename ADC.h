//Harini Cherupalla and Karen Yen 
//Date modified: 4/22/2017

#include <stdint.h>

// ADC initialization function 
// Input: none
// Output: none
void ADC_Init(void);

//------------ADC_In------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
uint32_t ADC_In(void);


//-----Port E Initialization-----
void PortE_Init(void);

//-----SysTick Initialization-----
void SysTick_Init(void);

void SysTick_Handler(void);