#ifndef _LED_H
#define _LED_H

//����ģ���
typedef enum
{
    LED0=0,
    LED1=1,
    LED2=2,
    LED3=3,
    LED4=4,
    LED5=5,
    LEDALL=6,//ȫ���ĸ�   
} LEDn_e;

typedef enum
{
    ON=0,  //��
    OFF=1, //��
    RVS=2, //��ת  
}LEDs_e;


/*********************** UART���ܺ��� **************************/
//��ʼ��
extern void LED_Init(void);
extern void LED_Ctrl(LEDn_e ledno, LEDs_e sta);
/********************************************************************/

#endif 
