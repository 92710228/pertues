#include "adc.h"

void ADC_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    ADC_InitTypeDef ADC_InitStructure;

    RCC_APB2PeriphClockCmd(ADC_GPIO_CLK | ADC_CLK_ENABLE, ENABLE);

    // ≈‰÷√ƒ£ƒ‚ ‰»Î“˝Ω≈
    GPIO_InitStructure.GPIO_Pin = ADC_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(ADC_GPIO_PORT, &GPIO_InitStructure);

    // ADC  ±÷”≈‰÷√ (PCLK2/6 = 64M/6 °÷ 10.67MHz£¨ºŸ…Ë PCLK2=64MHz)
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);
    ADC_DeInit(ADCx);

    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADCx, &ADC_InitStructure);

    ADC_Cmd(ADCx, ENABLE);

    ADC_ResetCalibration(ADCx);
    while(ADC_GetResetCalibrationStatus(ADCx));
    ADC_StartCalibration(ADCx);
    while(ADC_GetCalibrationStatus(ADCx));
}

uint16_t ADC_Read(void)
{
    ADC_RegularChannelConfig(ADCx, ADC_CHANNEL, 1, ADC_SampleTime_55Cycles5);
    ADC_SoftwareStartConvCmd(ADCx, ENABLE);
    while(ADC_GetFlagStatus(ADCx, ADC_FLAG_EOC) == RESET);
    return ADC_GetConversionValue(ADCx);
}