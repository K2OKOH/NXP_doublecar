#ifndef _LED_H
#define _LED_H

//定义模块号
typedef enum
{
    LED0=0,
    LED1=1,
    LED2=2,
    LED3=3,
    LED4=4,
    LED5=5,
    LEDALL=6,//全部四个   
} LEDn_e;

typedef enum
{
    ON=0,  //亮
    OFF=1, //灭
    RVS=2, //反转  
}LEDs_e;


/*********************** UART功能函数 **************************/
//初始化
extern void LED_Init(void);
extern void LED_Ctrl(LEDn_e ledno, LEDs_e sta);
/********************************************************************/

#endif 
