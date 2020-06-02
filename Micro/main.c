#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
#include "GPIO.h"
#include "stdio.h"
#include "stdint.h"
#include "interface_GPIO_KPD.h"
typedef unsigned int uint32_t;
void SystemInit(){}

struct room{
	char roomNumber;
	char password[4];
	char status;
};
	
//////////////////////////////////////*UART*/////////////////////////////////////////////////
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
//////////////////////////////////////*UART*/////////////////////////////////////////////////



void init(void){
	initPortA();
	initPortB();
	initPortC();
	initPortD();
	initPortE();
	initPortF();
	UART_init();
}
	
	


struct room rooms[50];
char option;
int chosenRoom;
int status;
	int main(){
	init();
	while(1){
		/*message out to choose user type: 1-for PC, 2-for GUEST*/
		char user;
		//enter here the choice
		user = KPD_charGetPressedKey();
		if(user=='1'){
			/*message out to enter rooms number: if 0 entered stop taking rooms*/
			int roomNo;
			int i=0; //room counter
			while(1){
				roomNo = KPD_charGetPressedKey();
				if(roomNo=='0'){
					break;
				}
				rooms[i].roomNumber = roomNo;
				i++;
			}
			/*message out to choose specific room*/
			
			//enter room number here
			chosenRoom = (int)KPD_charGetPressedKey();
			/*message out to show options for this room: 1-free, 2-occupied, 3-room cleaning*/
			
			//enter option here
			option = KPD_charGetPressedKey();
			if(option=='1'){
				/*message out: enter rooms password 4 digits*/
				char first,second,third,forth;
				//enter here the password
				first = KPD_charGetPressedKey();//enter first digit of password
				second = KPD_charGetPressedKey();//enter second digit of password
				third = KPD_charGetPressedKey();//enter third digit of password
				forth = KPD_charGetPressedKey();//enter forth digit of password
				rooms[chosenRoom].password[0]=first; //set passowrd for the room
				rooms[chosenRoom].password[1]=second; //set passowrd for the room
				rooms[chosenRoom].password[2]=third; //set passowrd for the room
				rooms[chosenRoom].password[3]=forth; //set passowrd for the room
				rooms[chosenRoom].status = '2';
				UART_Transmission(2);
			}
			else if(option=='2'){
				//room is closed, message out room is occupied
				GPIO_PORTF_DATA_R = 0x00;
			}
			else if(option=='3'){
				//room opens (red led on)
				GPIO_PORTF_DATA_R = 0x02;
				rooms[chosenRoom].status = '3';
				UART_Transmission(3);
				}
		}
			
		else if(user=='2'){
			/*message out: enter room number*/
			//enter room number here
			chosenRoom = (int)KPD_charGetPressedKey();
			/*message out enter password*/
			status = UART_Reciever();
			if(status==1){
				/*message out room is free can't open*/
		}else if(status ==2){
			char first,second,third,forth;
			first = KPD_charGetPressedKey();//enter first digit of password
			second = KPD_charGetPressedKey();//enter second digit of password
			third = KPD_charGetPressedKey();//enter third digit of password
			forth = KPD_charGetPressedKey();//enter forth digit of password
			if(rooms[chosenRoom].password[0]==first && rooms[chosenRoom].password[1]==second 
				&&rooms[chosenRoom].password[2]==third&&rooms[chosenRoom].password[3]==forth){
				//room opens (red led on)
				GPIO_PORTF_DATA_R = 0x02;
			}else{
				/*message out: wrong password, room still closed*/
				GPIO_PORTF_DATA_R = 0x00;
			}
		}
			else if(status ==3){
				//room opens
				GPIO_PORTF_DATA_R = 0x02;
			}
		}
	}
}
	
