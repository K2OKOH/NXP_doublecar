/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
��ƽ    ̨�������������ܿƼ�MK66FX1M0VLQ18���İ�
����    д��CHIUSIR
����    ע��
������汾��V1.0
�������¡�2016��08��20��
�������Ϣ�ο����е�ַ��
����    վ��http://www.lqist.cn
���Ա����̡�http://shop36265907.taobao.com
���������䡿chiusir@163.com
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/

#include "include.h"


void SysTick_delay(u32 cmd)
{
   SysTick->LOAD |=cmd;
   SysTick->VAL  |=0;
   SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk
                   |SysTick_CTRL_CLKSOURCE_Msk;
   while( !(SysTick->CTRL&SysTick_CTRL_COUNTFLAG_Msk) );
}

void delay_us(u32 cmd)//��׼��ʱ1us
{
  cmd=(u32)(cmd*core_clk_M);
  SysTick_delay(cmd);
}

void DELAY_us(u32 cmd)//����׼��ʱ1us
{
  while(cmd--)
  {
    delay_us(1);
  }

}