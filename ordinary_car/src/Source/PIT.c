#include "include.h"

int speed_L =600, speed_R = 600;
int ERR_L, ERR_R;
extern int duty_L,duty_R;

extern int LEFTSPEED,RIGHTSPEED;
//-------------------------------------------------------------------------*
//函数名: pit_init
//功  能: 初始化PIT
//参  数: pitn:模块名PIT0或PIT1或PIT2或PIT3
//        cnt 中断时间，单位1ms
//返  回: 无
//简  例: pit_init(PIT0,1000); PIT0中断，1000ms，即1s进入PIT0_interrupt()一次
//-------------------------------------------------------------------------*
void PIT_Init(PITn pitn, u32 cnt)
{
    //PIT 用的是 Bus Clock 总线频率

    /* 开启时钟*/
    SIM_SCGC6       |= SIM_SCGC6_PIT_MASK;                            //使能PIT时钟

    /* PIT模块控制 PIT Module Control Register (PIT_MCR) */
    PIT_MCR         &= ~(PIT_MCR_MDIS_MASK | PIT_MCR_FRZ_MASK );      //使能PIT定时器时钟 ，调试模式下继续运行

    /* 定时器加载值设置 Timer Load Value Register (PIT_LDVALn) */
    PIT_LDVAL(pitn)  = cnt*40*1000;                                          //设置溢出中断时间

    //定时时间到了后，TIF 置 1 。写1的时候就会清0
    PIT_Flag_Clear(pitn);                                             //清中断标志位

    /* 定时器控制寄存器 Timer Control Register (PIT_TCTRL0) */
    PIT_TCTRL(pitn) |= ( PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK );   //使能 PITn定时器,并开PITn中断

    NVIC_EnableIRQ((IRQn_Type)(pitn + 48));			                                //开接收引脚的IRQ中断
}



//-------------------------------------------------------------------------*
//函数名: PIT0_interrupt
//功  能: PIT中断函数
//参  数: 无
//返  回: 无
//简  例: 由初始化决定，多长时间进入一次
//-------------------------------------------------------------------------*
void PIT0_Interrupt()
{
  int duty = 7500;
  PIT_Flag_Clear(PIT0);       //清中断标志位
 /*用户添加所需代码*/
  
  LED_Ctrl(LED1, RVS);
  FTM_CnV_REG(FTM3, FTM_CH6) = duty;
}

void PIT1_Interrupt()
{
  PIT_Flag_Clear(PIT1);       //清中断标志位
 /*用户添加所需代码*/
  
  LEFTSPEED = -FTM_AB_Get(FTM1);     //获取正交解码速度，正负表示方向
  RIGHTSPEED = FTM_AB_Get(FTM2);     //获取正交解码速度，正负表示方向
  
//  ERR_L = speed_L - LEFTSPEED;
//  ERR_R = speed_R - RIGHTSPEED;
//    
//  duty_L = duty_L + ERR_L;
//  duty_R = duty_R + ERR_R;
  
  FTM_PWM_Duty(FTM0, FTM_CH1, motor_encoder_PD(speed_R,RIGHTSPEED));
  FTM_PWM_Duty(FTM0, FTM_CH3, motor_encoder_PD(speed_L,LEFTSPEED));
}

void PIT2_Interrupt()
{
  PIT_Flag_Clear(PIT1);       //清中断标志位
  /*用户添加所需代码*/
}

void PIT3_Interrupt()
{
  PIT_Flag_Clear(PIT3);       //清中断标志位
  /*用户添加所需代码*/
}