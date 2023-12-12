/*eng salah ali */
/* animation application */
#include "systic.h"
#include "GPIO.h"

vuint32 counter ;

void systic_handler(void)
{
	counter ++ ;
}





int main(void)
{
	uint32_t app1 = 0 ,app2 = 0 , app3 = 0 ;
	/*clock enable */
	RCC_GPIOA_CLK_EN() ;
	RCC_GPIOB_CLK_EN() ;
	RCC_AFIO_CLK_EN() ;

	/*pins GPIO Configuration */
	//PB12
	GPIO_PinConfig_t GPIO_config ;
	GPIO_config.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	GPIO_config.GPIO_Output_Speed = GPIO_SPEED_10M ;
	GPIO_config.GPIO_PinNumber = GPIO_PIN_12 ;
	MCAL_GPIO_Init(GPIOB, &GPIO_config) ;

	//PB13
	GPIO_config.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	GPIO_config.GPIO_Output_Speed = GPIO_SPEED_10M ;
	GPIO_config.GPIO_PinNumber = GPIO_PIN_13 ;
	MCAL_GPIO_Init(GPIOB, &GPIO_config) ;

	//PB14
	GPIO_config.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	GPIO_config.GPIO_Output_Speed = GPIO_SPEED_10M ;
	GPIO_config.GPIO_PinNumber = GPIO_PIN_14 ;
	MCAL_GPIO_Init(GPIOB, &GPIO_config) ;

	//PB15
	GPIO_config.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	GPIO_config.GPIO_Output_Speed = GPIO_SPEED_10M ;
	GPIO_config.GPIO_PinNumber = GPIO_PIN_15 ;
	MCAL_GPIO_Init(GPIOB, &GPIO_config) ;

	Systic_VoidInit(systic_handler) ;


	while(1)
	{
		MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET) ;
		while(app1<4)
		{

			Systic_Void_Write(800000) ;
			if(counter == 1)
			{
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET) ;
			}
			if(counter == 2)
			{
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET) ;
			}
			if(counter == 3)
			{
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET) ;
			}
			if(counter == 4)
			{
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET) ;
			}
			if(counter == 5)
			{
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET) ;
			}
			if(counter == 6)
			{
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET) ;
				counter = 0 ;
				app1++ ;
			}

		}

		counter = 0 ;


		while (app2 < 4)
		{
			if(counter == 1)
			{
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET)  ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET)  ;
			}
			if(counter == 2)
			{
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET)  ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET)  ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET) ;
				counter = 0 ;
				app2++ ;
			}
		}
		counter = 0 ;
		while (app3 < 4)
		{
			if(counter == 1)
			{
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET)  ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET)  ;
			}
			if(counter == 2)
			{

				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET) ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET)  ;
				MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET)  ;
				counter = 0 ;
				app3++ ;
			}
		}
		app1 = 0 ;
		app2 = 0 ;
		app3 = 0 ;
		counter = 0 ;
	}
}
