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
#include "wdog.h"	//����wdog.hͷ�ļ�
       
//-------------------------------------------------------------------------*
//������: wdog_disable                                                     *
//��  ��: �رտ��Ź�ģ��                                                   * 
//��  ��: ��			  					   *	
//��  ��: ��                                                               *
//˵  ��: ��                                                               *
//-------------------------------------------------------------------------*
void wdog_disable(void)
{
    //�����Ź�ģ��������Ա�д�Ĵ���
    wdog_unlock();
    //�رտ��Ź�
    WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK;
}

//-------------------------------------------------------------------------*
//������: wdog_unlock                                                      *
//��  ��: ���Ź�����                                                       * 
//��  ��: ��							           *	
//��  ��: ��                                                               *
//˵  ��: ��                                                               *
//-------------------------------------------------------------------------*
void wdog_unlock(void)
{
    /* ע��: ��Ҫ�������Դ˳���!!! �����������CPU��λ*/
    //�����ж�
    DisableInterrupts;		
    //д�����Ĵ���
    WDOG_UNLOCK = 0xC520;	
    //��ɽ���
    WDOG_UNLOCK = 0xD928;	
    //�����ж�
    EnableInterrupts;		
}
