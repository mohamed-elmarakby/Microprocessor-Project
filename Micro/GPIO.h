#define Toggle_BIT(var,BIT)  var^=(1<<BIT)
#define Get_BIT(var,BIT)    (var>>BIT)&1
#define SET_BIT(var,BIT) var|=(1<<BIT)
#define CLR_BIT(var,bit) var&=(~(1<<bit))
#define GET_BIT(var,bit)  (var>>bit)&1
#include "interface_GPIO_KPD.h"
#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"
typedef unsigned int uint32_t;
typedef enum{output,input} direction;





void initPortA(){
	SYSCTL_RCGCGPIO_R= SYSCTL_RCGCGPIO_R|0x01;
	while((SYSCTL_PRGPIO_R & 0X01)==0){};
		GPIO_PORTA_CR_R=0xFF;
		GPIO_PORTA_DEN_R=0xFF;
		GPIO_PORTA_AFSEL_R=0x00;
		GPIO_PORTA_PCTL_R=0x00;
		GPIO_PORTA_AMSEL_R=0x00;
}

void initPortB(){
	SYSCTL_RCGCGPIO_R=SYSCTL_RCGCGPIO_R|0x02;
	while((SYSCTL_PRGPIO_R & 0X02)==0){};
		GPIO_PORTB_CR_R=0xFF;
		GPIO_PORTB_DEN_R=0xFF;
		GPIO_PORTB_AFSEL_R=0x00;
		GPIO_PORTB_PCTL_R=0x00;
		GPIO_PORTB_AMSEL_R=0x00;
}

void initPortC(){
	SYSCTL_RCGCGPIO_R=SYSCTL_RCGCGPIO_R|0x04;
	while((SYSCTL_PRGPIO_R & 0X04)==0){};
		GPIO_PORTC_CR_R=0xFF;
		GPIO_PORTC_DEN_R=0xFF;
		GPIO_PORTC_AFSEL_R=0x00;
		GPIO_PORTC_PCTL_R=0x00;
		GPIO_PORTC_AMSEL_R=0x00;
}

void initPortD(){
	SYSCTL_RCGCGPIO_R=SYSCTL_RCGCGPIO_R|0x08;
	while((SYSCTL_PRGPIO_R & 0X08)==0){};
		GPIO_PORTD_CR_R=0xFF;
		GPIO_PORTD_DEN_R=0xFF;
		GPIO_PORTD_AFSEL_R=0x00;
		GPIO_PORTD_PCTL_R=0x00;
		GPIO_PORTD_AMSEL_R=0x00;
}

void initPortE(){
	SYSCTL_RCGCGPIO_R=SYSCTL_RCGCGPIO_R|0x10;
	while((SYSCTL_PRGPIO_R & 0X10)==0){};
		GPIO_PORTE_CR_R=0x3F;
		GPIO_PORTE_DEN_R=0x3F;
		GPIO_PORTE_AFSEL_R=0x00;
		GPIO_PORTE_PCTL_R=0x00;
		GPIO_PORTE_AMSEL_R=0x00;
}

void initPortF(){
	SYSCTL_RCGCGPIO_R=SYSCTL_RCGCGPIO_R|0x20;
	while((SYSCTL_PRGPIO_R & 0X20)==0){};
		GPIO_PORTF_CR_R=0x1F;
		GPIO_PORTF_DEN_R=0x1F;
		GPIO_PORTF_AFSEL_R=0x00;
		GPIO_PORTF_PCTL_R=0x00;
		GPIO_PORTF_AMSEL_R=0x00;
		GPIO_PORTF_DIR_R=0XE;
}


void  GPIO_voidSetPinValue(GPIO_PORTS enuPortIdx_cpy, GPIO_PINS enuPinIdx_cpy,GPIO_Pin_Value enuValue_cpy)
{
  switch(enuPortIdx_cpy)
	 {
		 case GPIO_PORT_A:
			 if(enuValue_cpy ==GPIO_LOW) //clear
			 {
				 CLR_BIT(GPIO_PORTA_DATA_R,enuPinIdx_cpy);
			 }
			 else if(enuValue_cpy==GPIO_HIGH)
			 {
				 SET_BIT(GPIO_PORTB_DATA_R,enuPinIdx_cpy);
			 }
		 break;

		 case  GPIO_PORT_B:
				 if(enuValue_cpy ==GPIO_LOW) //clear
				 {
					 CLR_BIT(GPIO_PORTB_DATA_R,enuPinIdx_cpy);
				 }
				 else if(enuValue_cpy==GPIO_HIGH)
				 {
					 SET_BIT(GPIO_PORTB_DATA_R,enuPinIdx_cpy);
				 }	  
		 break;

		 case  GPIO_PORT_C:
				 if(enuValue_cpy ==GPIO_LOW) //clear
				 {
					 CLR_BIT(GPIO_PORTC_DATA_R,enuPinIdx_cpy);
				 }
				 else if(enuValue_cpy==GPIO_HIGH)
				 {
					 SET_BIT(GPIO_PORTC_DATA_R,enuPinIdx_cpy);
				 }	  
		 break;

		 case  GPIO_PORT_D:
				 if(enuValue_cpy ==GPIO_LOW) //clear
				 {
					 CLR_BIT(GPIO_PORTD_DATA_R,enuPinIdx_cpy);
				 }
				 else if(enuValue_cpy==GPIO_HIGH)
				 {
					 SET_BIT(GPIO_PORTD_DATA_R,enuPinIdx_cpy);
				 }
		 break;
				 
		 case  GPIO_PORT_E:
				 if(enuValue_cpy ==GPIO_LOW) //clear
				 {
					 CLR_BIT(GPIO_PORTE_DATA_R,enuPinIdx_cpy);
				 }
				 else if(enuValue_cpy==GPIO_HIGH)
				 {
					 SET_BIT(GPIO_PORTE_DATA_R,enuPinIdx_cpy);
				 }	  
		 break;
				 
		 case  GPIO_PORT_F:
				 if(enuValue_cpy ==GPIO_LOW) //clear
				 {
					 CLR_BIT(GPIO_PORTF_DATA_R,enuPinIdx_cpy);
				 }
				 else if(enuValue_cpy==GPIO_HIGH)
				 {
					 SET_BIT(GPIO_PORTF_DATA_R,enuPinIdx_cpy);
				 }  
		 break;
	 } 
}



GPIO_Pin_Value GPIO_enuGetPinValue(GPIO_PORTS enuPortIndx_cpy  ,GPIO_PINS enuPinIndx_cpy)
{
	GPIO_Pin_Value enuPinValue_loc;
     switch(enuPortIndx_cpy)
     {
         case GPIO_PORT_A:
        	 enuPinValue_loc=GET_BIT(GPIO_PORTA_DATA_R ,enuPinIndx_cpy);
    	      break;

         case GPIO_PORT_B:
        	 enuPinValue_loc=GET_BIT(GPIO_PORTB_DATA_R ,enuPinIndx_cpy);
            	 break;

         case GPIO_PORT_C:
        	 enuPinValue_loc=GET_BIT(GPIO_PORTC_DATA_R,enuPinIndx_cpy);
            	 break;

         case GPIO_PORT_D:
        	 enuPinValue_loc=GET_BIT(GPIO_PORTD_DATA_R,enuPinIndx_cpy);
            	 break;
				 case GPIO_PORT_E:
        	 enuPinValue_loc=GET_BIT(GPIO_PORTE_DATA_R,enuPinIndx_cpy);
            	 break;
				 case GPIO_PORT_F:
        	 enuPinValue_loc=GET_BIT(GPIO_PORTF_DATA_R,enuPinIndx_cpy);
            	 break;
     }
 	return  enuPinValue_loc;
}
void SetPortDir (GPIO_PORTS PortName,direction DIR){
	
	switch(PortName)
	{ 
		case GPIO_PORT_A:
		{ switch(DIR)
			{case output:
			GPIO_PORTA_DIR_R=0xFF;
			case input:
			GPIO_PORTA_DIR_R=0x00;}
		}
		case GPIO_PORT_B:
		{ switch(DIR)
			{case output:
			GPIO_PORTB_DIR_R=0xFF;
			case input:
			GPIO_PORTB_DIR_R=0x00;}
		}
		case GPIO_PORT_C:
		{ switch(DIR)
			{case output:
			GPIO_PORTC_DIR_R=0xFF;
			case input:
			GPIO_PORTC_DIR_R=0x00;}
		}
		case GPIO_PORT_D:
		{ switch(DIR)
			{case output:
			GPIO_PORTD_DIR_R=0xFF;
			case input:
			GPIO_PORTD_DIR_R=0x00;}
		}
		case GPIO_PORT_E:
		{ switch(DIR)
			{case output:
			GPIO_PORTE_DIR_R=0x3F;
			case input:
			GPIO_PORTE_DIR_R=0x00;}
		case GPIO_PORT_F:
		{switch(DIR)
			{case output:
			GPIO_PORTF_DIR_R=0x1F;
			case input:
			GPIO_PORTF_DIR_R=0x00;}
		}
	}
}
	}

