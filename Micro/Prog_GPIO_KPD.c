#include "stdint.h"
#include "interface_GPIO_KPD.h"
#include "C:/Keil/Labware/inc/tm4c123gh6pm.h"


#define CLR_BIT(VAR,BIT)     VAR&=~(1<<BIT)
#define SET_BIT(VAR,BIT)     VAR|=(1<<BIT)
#define GET_BIT(VAR,BIT)     (VAR>>BIT)&1
#define TOGGLE_BIT(VAR,BIT)  VAR^=(1<<BIT)

char KeysNumber[ROW_NB][COL_NB]={ {'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'} };

//return key that has been pushed 
char KPD_charGetPressedKey(void)
{
	char KeyNB_Loc='x';
	u8 u8ColIdx_Loc;
	u8 u8RowIdx_Loc;
	GPIO_Pin_Value enuPinValue_Loc=GPIO_HIGH; 
	for(u8ColIdx_Loc =0;u8ColIdx_Loc<COL_NB ;u8ColIdx_Loc++)
	{
		GPIO_voidSetPinValue(KPD_PORT,u8ColIdx_Loc,GPIO_LOW);
		for(u8RowIdx_Loc=0;u8RowIdx_Loc<ROW_NB;u8RowIdx_Loc++)
		{
		  enuPinValue_Loc=GPIO_enuGetPinValue(KPD_PORT,(u8RowIdx_Loc+COL_NB));

			while(enuPinValue_Loc==GPIO_LOW)
			{
				KeyNB_Loc=KeysNumber[u8RowIdx_Loc][u8ColIdx_Loc];
				enuPinValue_Loc=GPIO_enuGetPinValue(KPD_PORT,(u8RowIdx_Loc+COL_NB));
			}
		}
	 GPIO_voidSetPinValue(KPD_PORT,u8ColIdx_Loc,GPIO_HIGH);
	}
	return  KeyNB_Loc;
}
