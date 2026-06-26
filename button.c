#include "button.h"
#include "stm32f10x.h"

// 定义GPIO端口和引脚
#define BUTTON_PORT GPIOB
#define BUTTON_PIN_10 GPIO_Pin_10
#define BUTTON_PIN_11 GPIO_Pin_11
#define BUTTON_PIN_12 GPIO_Pin_12
#define BUTTON_PIN_13 GPIO_Pin_13

volatile int a;
// ----------------------
// 初始化函数
// ----------------------
void button_init(void) {
    // 1. 使能GPIO和AFIO时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    // 2. 初始化GPIO端口
    GPIO_InitTypeDef gpio_init = {0};
    
    // 配置四个引脚为输入模式，内部上拉（IPU）
    gpio_init.GPIO_Mode = GPIO_Mode_IPU;
    gpio_init.GPIO_Pin = BUTTON_PIN_10 | BUTTON_PIN_11 | BUTTON_PIN_12 | BUTTON_PIN_13;
    gpio_init.GPIO_Speed = GPIO_Speed_10MHz;
    
    GPIO_Init(BUTTON_PORT, &gpio_init);
GPIO_WriteBit(GPIOB,GPIO_Pin_10,Bit_RESET);
		GPIO_WriteBit(GPIOB,BUTTON_PIN_11,Bit_RESET);
		GPIO_WriteBit(GPIOB,BUTTON_PIN_12,Bit_RESET);
		GPIO_WriteBit(GPIOB,BUTTON_PIN_13,Bit_RESET);
    // 3. 配置EXTI（外部中断）
    EXTI_InitTypeDef exti_init = {0};

    // *关键配置：将GPIOB的相应引脚配置到EXTI Line上*
    // B10 -> EXTI Line 10
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource10);
    // B11 -> EXTI Line 11
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource11);
    // B12 -> EXTI Line 12
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource12);
    // B13 -> EXTI Line 13
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource13);

    // 设置通用EXTI属性
    exti_init.EXTI_LineCmd = ENABLE;
    exti_init.EXTI_Mode = EXTI_Mode_Interrupt;
    // 按下触发（从高电平到低电平）
    exti_init.EXTI_Trigger = EXTI_Trigger_Falling; 
   
    // B10
    exti_init.EXTI_Line = EXTI_Line10;
    EXTI_Init(&exti_init);
    // B11
    exti_init.EXTI_Line = EXTI_Line11;
    EXTI_Init(&exti_init);
    // B12
    exti_init.EXTI_Line = EXTI_Line12;
    EXTI_Init(&exti_init);
    // B13
    exti_init.EXTI_Line = EXTI_Line13;
    EXTI_Init(&exti_init);

    // 4. 配置NVIC（中断向量表）
    // PB10 (EXTI10)
    NVIC_InitTypeDef nvic_init = {0};

    // PB13 (EXTI13)
    // 注意：对于STM32F103，EXTI13可能属于EXTI15_10_IRQn，但为了代码清晰和模块化，我们假设可以单独配置或使用最接近的通用函数。
    // 实际项目中需要根据芯片手册确认正确的IRQ名称。这里假设它是独立或使用通用组。
    // 为了兼容性，我们使用一个组名，如果您的芯片是F103，则使用 EXTI15_10_IRQn
    nvic_init.NVIC_IRQChannel = EXTI15_10_IRQn; // 这是一个包含10-15的常见组
    nvic_init.NVIC_IRQChannelPreemptionPriority = 1;
    nvic_init.NVIC_IRQChannelSubPriority = 1;
    nvic_init.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic_init);
}

// ----------------------
// 中断服务例程 (Interrupt Service Routines)
// ----------------------

// 注意：当多个高位EXTI线被分组时，可能需要使用组别的ISR。
// 如果你的STM32芯片将10-15线放在一起，你需要使用EXIT15_10_IRQHandler来处理B13。
// 假设B13处于这个组里，我们将其逻辑放入组ISR中。
void EXTI15_10_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line10) != RESET) {
        // 按键按下，将相应引脚置为高电平
        GPIO_WriteBit(BUTTON_PORT, BUTTON_PIN_13, Bit_SET);
        a=1;
        // 清除中断标志位
        EXTI_ClearITPendingBit(EXTI_Line10);
    }
    // 如果有其他需要处理的线，可以在这里继续添加
		  if (EXTI_GetITStatus(EXTI_Line11) != RESET) {
        // 按键按下，将相应引脚置为高电平
        GPIO_WriteBit(BUTTON_PORT, BUTTON_PIN_13, Bit_SET);
        a=2;
        // 清除中断标志位
        EXTI_ClearITPendingBit(EXTI_Line11);
    }
			  if (EXTI_GetITStatus(EXTI_Line12) != RESET) {
        // 按键按下，将相应引脚置为高电平
        GPIO_WriteBit(BUTTON_PORT, BUTTON_PIN_13, Bit_SET);
        a=3;
        // 清除中断标志位
        EXTI_ClearITPendingBit(EXTI_Line12);
    }
				  if (EXTI_GetITStatus(EXTI_Line13) != RESET) {
        // 按键按下，将相应引脚置为高电平
        GPIO_WriteBit(BUTTON_PORT, BUTTON_PIN_13, Bit_SET);
        a=4;
        // 清除中断标志位
        EXTI_ClearITPendingBit(EXTI_Line13);
    }
}
