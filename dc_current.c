#include "dc_current.h"
#include "adc.h"   // 使用 ADC_GetValue()

void DC_Current_Init(void)
{
    // ADC 已在主程序初始化，无需重复
}

float DC_Current_Measure(void)
{
    uint16_t adc_val;
    float voltage_adc;
    float current;

    adc_val = ADC_Read();
    voltage_adc = (adc_val * DC_CURRENT_VREF) / 4095.0f;
    // V_sense = V_adc / Gain
    current = (voltage_adc / DC_CURRENT_GAIN) / DC_CURRENT_RSENSE;

    return current;
}