#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"


int main(void)
{
  long int i;
  GPIO_InitTypeDef GPIO_InitStructure;

   RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC , ENABLE); // ������������ ������
  /**
  *	LED1 -> PB0   LED2 -> PB1
  */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; //��������� ������ �����
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_Init(GPIOC, &GPIO_InitStructure);

   GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;           //������ ����� ������
   GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPD;        //�������� ����, �������� � �����
   GPIO_Init(GPIOA, &GPIO_InitStructure);

  while (1) //Trigger
  {
	  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)
	  {
		  GPIO_SetBits(GPIOC, GPIO_Pin_9); //������ �1� �� GPIO_Pin_9
	  }
	  else
		  GPIO_ResetBits(GPIOC, GPIO_Pin_9); //������ �0� �� GPIO_Pin_9
  }
}



