#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"


int main(void)
{
  long int i;
  int h=1;
  GPIO_InitTypeDef GPIO_InitStructure;

   RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC , ENABLE); // тактирование портов
  /**
  *	LED1 -> PB0   LED2 -> PB1
  */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; //настройка вывода порта
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_Init(GPIOC, &GPIO_InitStructure);

   GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;           //задаем номер вывода
   GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPD;        //цифровой вход, подтяжка к земле
   GPIO_Init(GPIOA, &GPIO_InitStructure);

  while (1) //Trigger
  {

	  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1 & h==1)
	  {
		  h=2;

		  //устраняем дребезг кнопки
		 long int k=0;
		  while(k<=500000)
		  {
			  k++;
		  }
		  k=0;
	  }

	  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1 & h==2)
	 	  {
	 		h=1;

	 		//устраняем дребезг кнопки
	 		long int r=0;
	 		while(r<=500000)
	 		{
	 			r++;
	 		}
	 		r=0;
	 	  }


		if (h==1)
		{
			GPIO_SetBits(GPIOC, GPIO_Pin_9);
		}
		if (h==2)
		{
			GPIO_ResetBits(GPIOC, GPIO_Pin_9);
		}
  }
}



