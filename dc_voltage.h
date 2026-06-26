#ifndef __DC_VOLTAGE_H
#define __DC_VOLTAGE_H
//测量直流电压
#include "stm32f10x.h"

// 分压电阻参数（可修改为其他比例）
#define DC_VOLT_R1        100000.0f   // 上臂电阻 (Ω)
#define DC_VOLT_R2        10000.0f    // 下臂电阻 (Ω)
// 分压系数 = (R1+R2)/R2
#define DC_VOLT_DIV_FACTOR ((DC_VOLT_R1 + DC_VOLT_R2) / DC_VOLT_R2)

// ADC 参考电压（与电阻测量一致）
#define DC_VOLT_VREF      3.3f

// 初始化函数（如果 ADC 已初始化，可为空）
void DC_Voltage_Init(void);

// 测量函数，返回实际电压值 (V)
float DC_Voltage_Measure(void);

#endif