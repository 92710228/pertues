#ifndef __DC_CURRENT_H
#define __DC_CURRENT_H
//测量直流电流
#include "stm32f10x.h"

// 硬件参数
#define DC_CURRENT_RSENSE     0.1f     // 采样电阻 (Ω)
#define DC_CURRENT_GAIN       33.0f    // 差分放大增益 (R4/R3)
#define DC_CURRENT_VREF       3.3f     // ADC 参考电压

// 初始化函数
void DC_Current_Init(void);

// 测量电流 (A)
float DC_Current_Measure(void);

#endif