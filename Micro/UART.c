#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
#include "stdint.h"
void UART_init(void){
	SYSCTL_RCGCUART_R |= 0x0002;
	SYSCTL_RCGCGPIO_R |= 0x0002;
	UART1_CTL_R &= ~0x0001;
	UART1_IBRD_R = 27;
	UART1_FBRD_R = 8;
	UART1_LCRH_R = 0x0070;
	UART1_CTL_R = 0x0301;
	UART1_CC_R = 0x05;
	GPIO_PORTB_AFSEL_R |=0x03;
	GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00)+0x00000011;
	GPIO_PORTB_DEN_R |= 0x03;
	GPIO_PORTB_AMSEL_R &= ~0x03;
}

void UART_Transmission(uint32_t data){
	while((UART1_FR_R &0x20)!=0x0){};
	UART1_DR_R = data;
}

 uint32_t UART_Reciever(void){
	 uint32_t recievedData;
	while((UART1_FR_R&0x10)!=0x0){};
	recievedData = UART1_DR_R;
	return recievedData;
}
