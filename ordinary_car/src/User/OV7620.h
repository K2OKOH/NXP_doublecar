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
#ifndef __LQ_OV7620_H_
#define __LQ_OV7620_H_

#define LIN  320  //��
#define ROW  240  //��

#define L80   80
#define R60   60
 
#define OLEDV   80
#define OLEDH   60

extern void Seek_Becon_Dots(void);
extern u8 Calc_Offset(void);

extern unsigned char Image_data[ROW][LIN];
extern unsigned char Copy_Image[R60][L80];//������ͼ��
extern unsigned char ROW_Count;
extern unsigned char FieldCounter;
extern unsigned char Is_SendPhoto;

extern void Copy_Arr(unsigned char aa[],unsigned char b[]);            //����ͼ��
extern void BinaryZation(unsigned char (*p)[L80]);  //��ֵ��
extern void Peng_Fushi(unsigned char (*t)[L80],unsigned char (*temp)[L80],unsigned char b);
extern void Image_Filter(void);                               //һ����λ��������ֵ�����˲�

void OV7620_Init(void);
void SendPicture(void);


#endif