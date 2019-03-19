/****************************************************************************************************
【Target  】K66FX1M0VLQ18
【Crystal 】 50.000Mhz
【busclock】 40.000MHz
【pllclock】200.000MHz
=============================================================
接口定义：
LED测试GPIO
LED1--PTA17
LED2--PTC0
LED3--PTD15 
LED4--PTE26

OLED测试GPIO
DC  --PTC13
RST --PTC14
MISO--PTC15
CLK --PTC16
------------------------------------------------------------------------------------------------------
******************************************************************************************************/

#include "include.h" 

int LEFTSPEED = 0;
int RIGHTSPEED = 0;
int duty_L = 2000;
int duty_R = 2000;

//主函数
void main(void)
{
  
   u16 duty=7500;
   
   car_init();

   while(1)
   {   
//      DisableInterrupts;
      OLED_P6x8Str(40,3,"left");        OLED_PrintU16(80,3,LEFTSPEED);       
      OLED_P6x8Str(40,5,"right");       OLED_PrintU16(80,5,RIGHTSPEED);

//      EnableInterrupts;
      
      time_delay_ms(100); 
   }
}
