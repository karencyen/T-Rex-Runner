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
	ADC0_PC_R = 0x01; // 7) configure for 125K 
	ADC0_SSPRI_R = 0x0123; // 8) Seq 3 is highest priority
	ADC0_ACTSS_R &= ~0x0008; // 9) disable sample sequencer 3
	ADC0_EMUX_R &= ~0xF000; // 10) seq3 is software trigger
	ADC0_SSMUX3_R = ADC0_SSMUX3_R&0xFFFFFFF0; // 11) Ain0 (PE3)
	ADC0_SSCTL3_R = 0x0006; // 12) no TS0 D0, yes IE0 END0
	ADC0_IM_R &= ~0x0008; // 13) disable SS3 interrupts 
	ADC0_ACTSS_R |= 0x0008; // 14) enable sample sequencer 3
	ADC0_SAC_R = 0x04;
	
	
}

uint32_t ADC_In(void){  
	unsigned long result;
	ADC0_PSSI_R = 0x0008; // 1) initiate SS3
	while((ADC0_RIS_R&0x08)==0){};// 2) wait for conversion done
	result = ADC0_SSFIFO3_R&0xFFF; // 3) read result
	ADC0_ISC_R = 0x0008; // 4) acknowledge completion
	return result;

}


void PortE_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x11; //1) activate clock for Port E 
	while((SYSCTL_PRGPIO_R&0x10) == 0){};
	GPIO_PORTE_DIR_R &= ~0x0F; // 2) make PE0-3 input
	GPIO_PORTE_AFSEL_R |= 0x08; // 3) enable alternate fun on PE3
	GPIO_PORTE_AFSEL_R &= ~0x07; // 6) regular function on PE2-0
	GPIO_PORTE_DEN_R &= ~0x08; // 4) disable digital I/O on PE3
	GPIO_PORTE_DEN_R |= 0x07;    // 7) enable digital on PE2-0	
	GPIO_PORTE_AMSEL_R |= 0x08; // 5) enable analog fun on PE3
	GPIO_PORTE_AMSEL_R &= ~0x07; // 3) disable analog function on PE2-0
	GPIO_PORTE_PCTL_R &= ~0x0000FFF; // 4) enable regular GPIO
}

void SysTick_Init(void){
	NVIC_ST_CTRL_R = 0;         // disable SysTick during setup
  NVIC_ST_RELOAD_R = (250000*4) ;// reload value (40Hz)
  NVIC_ST_CURRENT_R = 0;      // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|(0x20000000); // priority 1
  NVIC_ST_CTRL_R = 0x007;	
}


