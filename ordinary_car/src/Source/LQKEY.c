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


void KEY_Init(void)
{
   GPIO_Init(PTB,20,GPI,1);
   GPIO_Init(PTB,21,GPI,1);
   GPIO_Init(PTB,22,GPI,1);   
}


u8 KEY_Read(KEYn_e keyno)
{
    switch(keyno) 
    {
      case KEY0:
        return GPIO_Get(PTB20);
      break;
      
      case KEY1:
        return GPIO_Get(PTB21);
      break;
      
      case KEY2:
        return GPIO_Get(PTB22);
      break;
      default:
        return 0XFF;
           
    }
}

//

