//Harini Cherupalla and Karen Yen
//Date modified: 4/22/2017

#include <stdint.h>
#include "tm4c123gh6pm.h"

// ADC initialization function 
// Input: none
// Output: none
void ADC_Init(void){ 
	unsigned long delay = 10000;
	SYSCTL_RCGCADC_R |= 0x01; // 6) activate ADC0 
	while(delay >0){
		delay--;
	}
	
}

void PortE_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x11; //1) activate clock for Port E 
	while((SYSCTL_PRGPIO_R&0x10) == 0){};
	GPIO_PORTE_DIR_R &= ~0x10; // 2) make PE0-3 input
	GPIO_PORTE_AFSEL_R |= 0x08; // 3) enable alternate fun on PE4
	GPIO_PORTE_AFSEL_R &= ~0x07; // 6) regular function on PE2-0
	GPIO_PORTE_DEN_R &= ~0x08; // 4) disable digital I/O on PE4
	GPIO_PORTE_DEN_R |= 0x07;    // 7) enable digital on PE2-0	
	GPIO_PORTE_AMSEL_R |= 0x08; // 5) enable analog fun on PE4
	GPIO_PORTE_AMSEL_R &= ~0x07; // 3) disable analog function on PE2-0
	GPIO_PORTE_PCTL_R &= ~0x0000FFF; // 4) enable regular GPIO
	
}
