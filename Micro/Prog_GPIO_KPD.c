#include "stdint.h"
#include "C:/Users/20115/Desktop/Micro/interface_GPIO_KPD.h"
#include "C:/Users/20115/Desktop/TIVAC.h"
#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"

#define CLR_BIT(VAR,BIT)     VAR&=~(1<<BIT)
#define SET_BIT(VAR,BIT)     VAR|=(1<<BIT)
#define GET_BIT(VAR,BIT)     (VAR>>BIT)&1
#define TOGGLE_BIT(VAR,BIT)  VAR^=(1<<BIT)

char KeysNumber[ROW_NB][COL_NB]={ {'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'} };
void GPIO_voidPortF_Init(void)
{
    SYSCTL_RCGCGPIO_R|=0X20;
    while((SYSCTL_PRGPIO_R&0X20)==0){}
    GPIO_PORTF_DEN_R=0XE;
	GPIO_PORTF_CR_R=0XE;
    GPIO_PORTF_AMSEL_R=0;
	GPIO_PORTF_AFSEL_R=0;
	GPIO_PORTF_PCTL_R=0;
	GPIO_PORTF_DIR_R=0XE;	
}

void GPIO_voidPortA_Init(void){
	SYSCTL_RCGCGPIO_R= SYSCTL_RCGCGPIO_R|0x01;
	while((SYSCTL_PRGPIO_R & 0X01)==0){};
		GPIO_PORTA_CR_R=0xFF;
		GPIO_PORTA_DEN_R=0xFF;
		GPIO_PORTA_AFSEL_R=0x00;
		GPIO_PORTA_PCTL_R=0x00;
		GPIO_PORTA_AMSEL_R=0x00;
		GPIO_PORTB_PUR_R=0XF0;
		GPIO_PORTB_DIR_R=0X0F;
		GPIO_PORTB_DATA_R|=0XF;
}

void GPIO_voidPortB_Init(void)
{
	SYSCTL_RCGCGPIO_R|=0X2;
	while((SYSCTL_PRGPIO_R&0X2)==0){}
	GPIO_PORTB_DEN_R=0XFF;
	GPIO_PORTB_CR_R=0XFF;
	GPIO_PORTB_AMSEL_R=0;
	GPIO_PORTB_AFSEL_R=0;
	GPIO_PORTB_PCTL_R=0;
	GPIO_PORTB_PUR_R=0XF0;
	GPIO_PORTB_DIR_R=0X0F;
  GPIO_PORTB_DATA_R|=0XF;		
}

//return key that has been pushed 
char KPD_charGetPressedKey(void)
{
	char KeyNB_Loc='x';
	u8 u8ColIdx_Loc;
	u8 u8RowIdx_Loc;
	GPIO_Pin_Value enuPinValue_Loc=GPIO_HIGH; 
	for(u8ColIdx_Loc =0;u8ColIdx_Loc<COL_NB ;u8ColIdx_Loc++)
	{
		GPIO_voidSetPinValue(KPD_PORT_GUEST,u8ColIdx_Loc,GPIO_LOW);
		for(u8RowIdx_Loc=0;u8RowIdx_Loc<ROW_NB;u8RowIdx_Loc++)
		{
		  enuPinValue_Loc=GPIO_enuGetPinValue(KPD_PORT_GUEST,(u8RowIdx_Loc+COL_NB));

			while(enuPinValue_Loc==GPIO_LOW)
			{
				KeyNB_Loc=KeysNumber[u8RowIdx_Loc][u8ColIdx_Loc];
				enuPinValue_Loc=GPIO_enuGetPinValue(KPD_PORT_GUEST,(u8RowIdx_Loc+COL_NB));
			}
		}
	 GPIO_voidSetPinValue(KPD_PORT_GUEST,u8ColIdx_Loc,GPIO_HIGH);
	}
	return  KeyNB_Loc;
}
char KPD_charGetPressedKeyPC(void)
{
	char KeyNB_Loc='x';
	u8 u8ColIdx_Loc;
	u8 u8RowIdx_Loc;
	GPIO_Pin_Value enuPinValue_Loc=GPIO_HIGH; 
	for(u8ColIdx_Loc =0;u8ColIdx_Loc<COL_NB ;u8ColIdx_Loc++)
	{
		GPIO_voidSetPinValue(KPD_PORT_PC,u8ColIdx_Loc,GPIO_LOW);
		for(u8RowIdx_Loc=0;u8RowIdx_Loc<ROW_NB;u8RowIdx_Loc++)
		{
		  enuPinValue_Loc=GPIO_enuGetPinValue(KPD_PORT_PC,(u8RowIdx_Loc+COL_NB));

			while(enuPinValue_Loc==GPIO_LOW)
			{
				KeyNB_Loc=KeysNumber[u8RowIdx_Loc][u8ColIdx_Loc];
				enuPinValue_Loc=GPIO_enuGetPinValue(KPD_PORT_PC,(u8RowIdx_Loc+COL_NB));
			}
		}
	 GPIO_voidSetPinValue(KPD_PORT_PC,u8ColIdx_Loc,GPIO_HIGH);
	}
	return  KeyNB_Loc;
}
