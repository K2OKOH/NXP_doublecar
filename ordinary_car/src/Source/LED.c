/******************** LQ_K60_������ v1.0 ********************
 * �ļ���           ��LED.c
 * ����             ������LED�ڹ���ģʽ
 * ��ע             ���ٷ��������޸�
 * ����             ��2016-01-23
 * ʵ��ƽ̨         ������ k66F18���İ�VG2
 * ��������         ��IAR 7.3������
 * ����             ��CHIUSIR
 * �Ա���           ��https://longqiu.taobao.com
 * �������ܳ�����Ⱥ ��202949437
*************************************************************/

#include "include.h"


void LED_Init(void)
{
   GPIO_Init(PTB,17,GPO,0);
   GPIO_Init(PTB,16,GPO,0);
   GPIO_Init(PTB,18,GPO,1);
   GPIO_Init(PTB,19,GPO,1);
}

void LED_Ctrl(LEDn_e ledno, LEDs_e sta)
{
    switch(ledno) 
    {
    case LED0:
      if(sta==ON)        GPIO_Ctrl(PTB,16,0);
      else if(sta==OFF) GPIO_Ctrl(PTB,16,1);
      else if(sta==RVS) GPIO_Reverse (PTB, 16);
    break;
    
    case LED1:
      if(sta==ON)        GPIO_Ctrl(PTB,17,0);
      else if(sta==OFF) GPIO_Ctrl(PTB,17,1);
      else if(sta==RVS) GPIO_Reverse (PTB,17);
    break;
    
    case LED2:
      if(sta==ON)        GPIO_Ctrl(PTB,18,0);
      else if(sta==OFF) GPIO_Ctrl(PTB,18,1);
      else if(sta==RVS) GPIO_Reverse (PTB,18);
    break; 
    
    case LED3:
      if(sta==ON)        GPIO_Ctrl(PTB, 19,0);
      else if(sta==OFF) GPIO_Ctrl(PTB, 19,1);
      else if(sta==RVS) GPIO_Reverse (PTB, 19);
    break;
    case LEDALL:
      if(sta==ON) 
      {       
          GPIO_Ctrl(PTB,17,0);
          GPIO_Ctrl(PTB,18,0);
          GPIO_Ctrl(PTB,16,0);
          GPIO_Ctrl(PTB,19,0);
      }
      else if(sta==OFF)
      { 
          GPIO_Ctrl(PTB,17,1);
          GPIO_Ctrl(PTB,18,1);
          GPIO_Ctrl(PTB,16,1);
          GPIO_Ctrl(PTB,19,1);
      }
      else if(sta==RVS)
      {       
          GPIO_Reverse (PTB, 17);     
          GPIO_Reverse (PTB, 18);      
          GPIO_Reverse (PTB, 19);      
          GPIO_Reverse (PTB, 16);      
      }
    break;
    default:
    break;    
    }   
}