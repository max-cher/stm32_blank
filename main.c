#include "stm32f10x.h"
#include "main.h"



int main(void) {	
	RCC->APB2ENR |= 0x10 | 0x04;									/* Enable the GPIOA (bit 2) and GPIOC (bit 8) */
	GPIOC->CRH = 0x11;												/* Set GPIOC Pin 8 and Pin 9 to outputs */
	GPIOA->CRL = 0x04;												/* Set GPIOA Pin 0 to input floating */


	while(1) {
        GPIOC->ODR = 0x00000100;
        ms_delay(100);
        GPIOC->ODR = 0x00000200;
        ms_delay(100);
	}
}



void ms_delay(int ms) {
    while(ms-- > 0) {
        volatile int x=5971;
        while(x-- > 0)
            __asm("nop");
    }
}

void delay(void) {
	int i = 100000;					/* About 1/4 second delay */
	while (i-- > 0) {
		asm("nop");					/* This stops it optimising code out */
	}
}

void nmi_handler(void) {
    return;
}

void hardfault_handler(void) {
    return;
}


