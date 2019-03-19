/******************** LQ_K60_������ v1.0 ********************
 * �ļ���           ��KEY.c
 * ����             �����ð����ڹ���ģʽ
 * ��ע             ���ٷ��������޸�
 * ����             ��2016-01-23
 * ʵ��ƽ̨         ������ k66F18���İ�VG2
 * ��������         ��IAR 7.3������
 * ����             ��CHIUSIR
 * �Ա���           ��https://longqiu.taobao.com
 * �������ܳ�����Ⱥ ��202949437
*************************************************************/

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

