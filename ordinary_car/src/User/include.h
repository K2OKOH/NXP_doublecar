#ifndef INCLUDE_H_
#define INCLUDE_H_

//ͨ��ͷ�ļ�
    #include    <stdio.h>                       //printf
    #include    <string.h>                      //memcpy
    #include    <stdlib.h>                      //malloc

//Cortex-M�ں�MCU�Ĵ���ͷ�ļ�
    #include "MK66F18.h"   //�Ĵ���ӳ��ͷ�ļ�
    #include "arm_math.h "
    #include "Systick.h"

//MCU�ڲ�ģ��������ͷ�ļ�
    #include "GPIO.h"
    #include "GPIO_Cfg.h"
    #include "PLL.h"
    #include "FTM.h"    
    #include "UART.h"
    #include "ADC.h"
    #include "PLL.h"    
    #include "PIT.h"
    #include "I2C.h"
    //#include "SPI.h"
    #include "DMA.h"
    #include "Lptmr.h"    
    #include "RTC.h"

//based on the car
    #include "PID.h"
    #include "CarInit.h"

//�ж��������жϺ�������
    #include "vectors.h"

//�������ͼ��˿������ض���
    #include "common.h"

//�ⲿ�豸���Զ��幦��������ͷ�ļ�
    //#include "LQ9AX.h"
    #include "LQLED.h"
    #include "LQKEY.h"
    #include "OV7620.h"
    //#include "LQSERVO.h"
    #include "OLED.h"
    //#include "LQnRF24L01.h"

#endif