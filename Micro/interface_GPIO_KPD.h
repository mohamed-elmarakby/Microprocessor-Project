#ifndef interface_GPIO_KPD_h
#define interface_GPIO_KPD_h

#define KPD_PORT_GUEST GPIO_PORT_B
#define KPD_PORT_PC GPIO_PORT_A

//KPD config.
#define ROW_NB  4   
#define COL_NB  4

typedef unsigned char u8 ;  
typedef enum{ GPIO_LOW,GPIO_HIGH }GPIO_Pin_Value;

typedef enum{ GPIO_INPUT, GPIO_OUTPUT }GPIO_Pin_Dir;

typedef enum{ GPIO_PORT_A, GPIO_PORT_B, GPIO_PORT_C,
	            GPIO_PORT_D, GPIO_PORT_E, GPIO_PORT_F }GPIO_PORTS;

typedef enum{ GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3,
            	GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7 }GPIO_PINS;
				
			

void GPIO_voidPortF_Init(void);
void GPIO_voidPortB_Init(void);		
void GPIO_voidPortA_Init(void);							
char KPD_charGetPressedKey(void);
char KPD_charGetPressedKeyPC(void);

GPIO_Pin_Value GPIO_enuGetPinValue(GPIO_PORTS enuPortIndx_cpy  ,GPIO_PINS enuPinIndx_cpy);
void GPIO_voidSetPinValue(GPIO_PORTS enuPortIdx_cpy, GPIO_PINS enuPinIdx_cpy,GPIO_Pin_Value enuValue_cpy);

#endif