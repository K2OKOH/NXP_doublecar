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

#ifndef _PIT_H_
#define _PIT_H_


#define PIT_Flag_Clear(PITn)   PIT_TFLG(PITn)|=PIT_TFLG_TIF_MASK      //���жϱ�־


//ģ�鶨��
typedef enum PITn
{
    PIT0,
    PIT1,
    PIT2,
    PIT3
} PITn;

/*********************** PIT���ܺ��� **************************/
void PIT_Init(PITn, u32 cnt);                                            //��ʼ��PITn�������ö�ʱʱ��(��λΪbusʱ������)
void PIT0_Interrupt();
void PIT1_Interrupt();
void PIT2_Interrupt();
void PIT3_Interrupt();

#endif  