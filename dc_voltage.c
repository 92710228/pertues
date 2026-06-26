#include "dc_voltage.h"
#include "adc.h"  

void DC_Voltage_Init(void)
{
    //主程序：已实现ADC 
    
}

float DC_Voltage_Measure(void)
{
    uint16_t adc_val;
    float voltage_adc;

    adc_val = ADC_Read();   // 连续模式下直接读取
    voltage_adc = (adc_val * DC_VOLT_VREF) / 4095.0f;
    return voltage_adc * DC_VOLT_DIV_FACTOR;
}