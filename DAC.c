//Harini Cherupalla and Karen Yen
//Date modified: 4/22/2017

#include <stdint.h>
#include "tm4c123gh6pm.h"

// **************DAC_Init*********************
// Initialize 6-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){
	unsigned long volatile delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; // activate port B
  delay = SYSCTL_RCGC2_R;    // allow time to finish activating
  GPIO_PORTB_AMSEL_R &= ~0x2F;      // no analog
  GPIO_PORTB_PCTL_R &= ~0x00FFFFFF; // regular GPIO function
  GPIO_PORTB_DIR_R |= 0x2F;      // make PB2-0 out
  GPIO_PORTB_AFSEL_R &= ~0x2F;   // disable alt funct on PB2-0
  GPIO_PORTB_DEN_R |= 0x2F;      // enable digital I/O on PB2-0
}

// **************DAC_Out*********************
// output to DAC
// Input: 6-bit data, 0 to 63 
// Output: none
void DAC_Out(uint32_t data){
	GPIO_PORTB_DATA_R = data;
}
