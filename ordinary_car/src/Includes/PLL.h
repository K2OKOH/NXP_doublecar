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

#ifndef __PLL_H__
#define __PLL_H__

extern uint32 core_clk_M;//��λMHZ
extern uint32 bus_clk_M;//��λMHZ

//PLL����
typedef enum clk_option
{
    PLLUNULL ,
    PLL80    ,
    PLL90    ,
    PLL100   ,
    PLL120   ,
    PLL130   ,
    PLL140   ,
    PLL150   ,
    PLL160   ,
    PLL170   ,
    PLL180   ,
    PLL200   ,
    PLL220   ,
    PLL225   ,
    PLL230   ,
    PLL235   ,
    PLL237_5 , //ʵ��Ϊ237.5M
} clk_option;



/*********************** PLL���ܺ��� **************************/
void PLL_Init(clk_option);     //���໷��ʼ��




#endif
