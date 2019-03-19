#ifndef _FTM_H_
#define _FTM_H_

/**********************************  FTM(���Ÿ���) ***************************************/

//      ģ��ͨ��    �˿�          ��ѡ��Χ              ����
#define FTM0_CH0    PTC1        //PTC1��PTA3            PTA3��Ҫ�ã���JLINK��ͻ��
#define FTM0_CH1    PTC2        //PTC2��PTA4
#define FTM0_CH2    PTC3        //PTC3��PTA5
#define FTM0_CH3    PTC4        //PTC4��PTA6
#define FTM0_CH4    PTD4        //PTD4��PTA7
#define FTM0_CH5    PTD5        //PTD5��PTA0            PTA0��Ҫ�ã���JLINK��ͻ��
#define FTM0_CH6    PTD6        //PTD6��PTA1            PTA1��Ҫ�ã���JLINK��ͻ��
#define FTM0_CH7    PTD7        //PTD7��PTA2            PTA2��Ҫ�ã���JLINK��ͻ��

//      ģ��ͨ��    �˿�          ��ѡ��Χ
#define FTM1_CH0    PTA8       //PTA8��PTA12��PTB0
#define FTM1_CH1    PTA9       //PTA9��PTA13��PTB1

//      ģ��ͨ��    �˿�          ��ѡ��Χ
#define FTM2_CH0    PTA10       //PTA10��PTB18
#define FTM2_CH1    PTA11       //PTA11��PTB19

//      ģ��ͨ��    �˿�          ��ѡ��Χ
#define FTM3_CH0    PTE5        // PTE5��PTD0
#define FTM3_CH1    PTE6        // PTE6��PTD1
#define FTM3_CH2    PTE7        // PTE7��PTD2
#define FTM3_CH3    PTE8        // PTE8��PTD3
#define FTM3_CH4    PTE9        // PTE9��PTC8
#define FTM3_CH5    PTE10       // PTE10��PTC9
#define FTM3_CH6    PTC10       // PTE11��PTC10
#define FTM3_CH7    PTC11       // PTE12��PTC11

//��������ģ��ͨ��  �˿�          ��ѡ��Χ
#define FTM1_QDPHA  PTA12       //PTA8��PTA12��PTB0
#define FTM1_QDPHB  PTA13       //PTA9��PTA13��PTB1

#define FTM2_QDPHA  PTB18       //PTA10��PTB18
#define FTM2_QDPHB  PTB19       //PTA11��PTB19

/**********************************  FTM(���Ÿ���) ***************************************/


//����FTM ͨ����
typedef enum
{

    FTM_CH0,
    FTM_CH1,
    FTM_CH2,
    FTM_CH3,
    FTM_CH4,
    FTM_CH5,
    FTM_CH6,
    FTM_CH7,

} FTM_CHn_e;


typedef enum
{
    FTM_Rising,               //�����ز�׽
    FTM_Falling,              //�½��ز�׽
    FTM_Rising_or_Falling     //�����ز�׽
} FTM_Input_cfg;

#define FTM_IRQ_EN(FTMn,CHn)        FTM_CnSC_REG(FTMN[FTMn],CHn) |= FTM_CnSC_CHIE_MASK       //���� FTMn_CHn �ж�
#define FTM_IRQ_DIS(FTMn,CHn)       FTM_CnSC_REG(FTMN[FTMn],CHn) &= ~FTM_CnSC_CHIE_MASK      //�ر� FTMn_CHn �ж�
/*********************** PWM���ܺ��� **************************/
void FTM_PWM_Init(FTM_Type * ftmn, FTM_CHn_e ch, u16 mod, u16 cv);
void FTM_PWM_Duty(FTM_Type * ftmn, FTM_CHn_e ch, u16 duty);

/*********************** ���벶׽���жϹ��ܺ��� **************************/
void FTM_Input_init(FTM_Type * ftmn, FTM_CHn_e ch, FTM_Input_cfg cfg);
void FTM0_interrupt(void);
void FTM1_interrupt(void);
void FTM2_interrupt(void);
/*********************** �������빦�ܺ��� **************************/
void FTM_AB_Init(FTM_Type * ftmn);         //��ʼ��FTM ���������� ����
s16  FTM_AB_Get(FTM_Type * ftmn);          //��ȡFTM �������� ��������(������ʾ������)


#endif



