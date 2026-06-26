#ifndef __ADC_H
#define __ADC_H

#include "stm32f10x.h"

// ÅäÖÃ ADC Òý½Å£¨ÀýÈç PA0£©
#define ADC_GPIO_PORT          GPIOA
#define ADC_GPIO_PIN           GPIO_Pin_0
#define ADC_GPIO_CLK           RCC_APB2Periph_GPIOA
#define ADCx                   ADC1
#define ADC_CHANNEL            ADC_Channel_0
#define ADC_CLK_ENABLE         RCC_APB2Periph_ADC1

void ADC_init(void);
uint16_t ADC_Read(void);

#endif