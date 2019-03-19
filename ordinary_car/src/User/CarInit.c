#include "include.h"

void car_init()
{
   DisableInterrupts;        //�ر����ж�
   PLL_Init(PLL200);         //��ʼ��PLLΪ200M������Ϊ40MHZ
   PIT_Init(PIT0,500);      //�ж϶�ʱ500ms��1s��˸һ��
   PIT_Init(PIT1,100);
   LED_Init();               //LED��ʼ��
   LED_Ctrl(LEDALL, OFF);     //LEDȫ��  
   
   FTM_PWM_Init(FTM3,FTM_CH6,50000,7500);//PTC10
   
   FTM_PWM_Init(FTM0,FTM_CH0,10000,0);      //PTC1s
   FTM_PWM_Init(FTM0,FTM_CH1,10000,2000);          //PTC2  right
   FTM_PWM_Init(FTM0,FTM_CH2,10000,0);      //PTC3
   FTM_PWM_Init(FTM0,FTM_CH3,10000,2000);          //PTC4 left
   
   FTM_AB_Init(FTM1);
   FTM_AB_Init(FTM2);
   
   OV7620_Init();               //����ͷ��ʼ��  
   UART_Init(UART_4,19200);     //����4��ʼ��   
   time_delay_ms(500);
   
   OLED_Init();               //OLEDģ���ʼ��
   OLED_CLS();                //OLED����
  //Draw_Frame();
   EnableInterrupts;
}