#ifndef _KEY_H_
#define _KEY_H_

//定义模块号
typedef enum
{
    KEY0=0,
    KEY1=1,
    KEY2=2,   
} KEYn_e;
typedef enum
{
    LOW=0,  //亮
    HIGH=1, //灭   
    FAIL=0xff,
}KEYs_e;


/*********************** UART功能函数 **************************/
//初始化
extern void KEY_Init(void);
extern u8 KEY_Read(KEYn_e keyno);
/********************************************************************/

#endif 
