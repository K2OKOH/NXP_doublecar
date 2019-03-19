#include "include.h"

void car_init()
{
   DisableInterrupts;        //关闭总中断
   PLL_Init(PLL200);         //初始化PLL为200M，总线为40MHZ
   PIT_Init(PIT0,500);      //中断定时500ms，1s闪烁一次
   PIT_Init(PIT1,100);
   LED_Init();               //LED初始化
   LED_Ctrl(LEDALL, OFF);     //LED全灭  
   
   FTM_PWM_Init(FTM3,FTM_CH6,50000,7500);//PTC10
   
   FTM_PWM_Init(FTM0,FTM_CH0,10000,0);      //PTC1s
   FTM_PWM_Init(FTM0,FTM_CH1,10000,2000);          //PTC2  right
   FTM_PWM_Init(FTM0,FTM_CH2,10000,0);      //PTC3
   FTM_PWM_Init(FTM0,FTM_CH3,10000,2000);          //PTC4 left
   
   FTM_AB_Init(FTM1);
   FTM_AB_Init(FTM2);
   
   OV7620_Init();               //摄像头初始化  
   UART_Init(UART_4,19200);     //串口4初始化   
   time_delay_ms(500);
   
   OLED_Init();               //OLED模块初始化
   OLED_CLS();                //OLED清屏
  //Draw_Frame();
   EnableInterrupts;
}