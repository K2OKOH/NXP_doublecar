#include "include.h"

int speed_L =600, speed_R = 600;
int ERR_L, ERR_R;
extern int duty_L,duty_R;

extern int LEFTSPEED,RIGHTSPEED;
//-------------------------------------------------------------------------*
//������: pit_init
//��  ��: ��ʼ��PIT
//��  ��: pitn:ģ����PIT0��PIT1��PIT2��PIT3
//        cnt �ж�ʱ�䣬��λ1ms
//��  ��: ��
//��  ��: pit_init(PIT0,1000); PIT0�жϣ�1000ms����1s����PIT0_interrupt()һ��
//-------------------------------------------------------------------------*
void PIT_Init(PITn pitn, u32 cnt)
{
    //PIT �õ��� Bus Clock ����Ƶ��

    /* ����ʱ��*/
    SIM_SCGC6       |= SIM_SCGC6_PIT_MASK;                            //ʹ��PITʱ��

    /* PITģ����� PIT Module Control Register (PIT_MCR) */
    PIT_MCR         &= ~(PIT_MCR_MDIS_MASK | PIT_MCR_FRZ_MASK );      //ʹ��PIT��ʱ��ʱ�� ������ģʽ�¼�������

    /* ��ʱ������ֵ���� Timer Load Value Register (PIT_LDVALn) */
    PIT_LDVAL(pitn)  = cnt*40*1000;                                          //��������ж�ʱ��

    //��ʱʱ�䵽�˺�TIF �� 1 ��д1��ʱ��ͻ���0
    PIT_Flag_Clear(pitn);                                             //���жϱ�־λ

    /* ��ʱ�����ƼĴ��� Timer Control Register (PIT_TCTRL0) */
    PIT_TCTRL(pitn) |= ( PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK );   //ʹ�� PITn��ʱ��,����PITn�ж�

    NVIC_EnableIRQ((IRQn_Type)(pitn + 48));			                                //���������ŵ�IRQ�ж�
}



//-------------------------------------------------------------------------*
//������: PIT0_interrupt
//��  ��: PIT�жϺ���
//��  ��: ��
//��  ��: ��
//��  ��: �ɳ�ʼ���������೤ʱ�����һ��
//-------------------------------------------------------------------------*
void PIT0_Interrupt()
{
  int duty = 7500;
  PIT_Flag_Clear(PIT0);       //���жϱ�־λ
 /*�û�����������*/
  
  LED_Ctrl(LED1, RVS);
  FTM_CnV_REG(FTM3, FTM_CH6) = duty;
}

void PIT1_Interrupt()
{
  PIT_Flag_Clear(PIT1);       //���жϱ�־λ
 /*�û�����������*/
  
  LEFTSPEED = -FTM_AB_Get(FTM1);     //��ȡ���������ٶȣ�������ʾ����
  RIGHTSPEED = FTM_AB_Get(FTM2);     //��ȡ���������ٶȣ�������ʾ����
  
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
  PIT_Flag_Clear(PIT1);       //���жϱ�־λ
  /*�û�����������*/
}

void PIT3_Interrupt()
{
  PIT_Flag_Clear(PIT3);       //���жϱ�־λ
  /*�û�����������*/
}