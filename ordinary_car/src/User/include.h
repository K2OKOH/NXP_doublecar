#ifndef INCLUDE_H_
#define INCLUDE_H_

//通用头文件
    #include    <stdio.h>                       //printf
    #include    <string.h>                      //memcpy
    #include    <stdlib.h>                      //malloc

//Cortex-M内核MCU寄存器头文件
    #include "MK66F18.h"   //寄存器映像头文件
    #include "arm_math.h "
    #include "Systick.h"

//MCU内部模块驱动的头文件
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

//中断向量表及中断函数声明
    #include "vectors.h"

//数据类型及端口名称重定义
    #include "common.h"

//外部设备及自定义功能驱动的头文件
    //#include "LQ9AX.h"
    #include "LQLED.h"
    #include "LQKEY.h"
    #include "OV7620.h"
    //#include "LQSERVO.h"
    #include "OLED.h"
    //#include "LQnRF24L01.h"

#endif