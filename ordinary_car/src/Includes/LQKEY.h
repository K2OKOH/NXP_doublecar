#ifndef _KEY_H_
#define _KEY_H_

//����ģ���
typedef enum
{
    KEY0=0,
    KEY1=1,
    KEY2=2,   
} KEYn_e;
typedef enum
{
    LOW=0,  //��
    HIGH=1, //��   
    FAIL=0xff,
}KEYs_e;


/*********************** UART���ܺ��� **************************/
//��ʼ��
extern void KEY_Init(void);
extern u8 KEY_Read(KEYn_e keyno);
/********************************************************************/

#endif 
