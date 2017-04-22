//Harini Cheupalla and Karen Yen
//Date modified: 4/22/2017

#include <stdint.h>

// **************DAC_Init*********************
// Initialize 6-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void);


// **************DAC_Out*********************
// output to DAC
// Input: 6-bit data, 0 to 63 
// Output: none
void DAC_Out(uint8_t data);

