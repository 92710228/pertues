#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "oled.h"
extern int b;
void buzzer_init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef gpio_init;
		gpio_init.GPIO_Mode=GPIO_Mode_Out_PP;
		gpio_init.GPIO_Pin=GPIO_Pin_6;
		gpio_init.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(GPIOA,&gpio_init);
}
void buzzer(){
int i=0;
	while(i<3){//
	GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_SET);
	Delay_ms(50);
	GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_RESET);
	Delay_ms(50);
		i++;
	}
}
void zhi_1(){
	OLED_ShowChinese16x16(2,1,10);
	OLED_ShowChinese16x16(2,2,11);
	OLED_ShowChinese16x16(2,3,12);
	OLED_ShowChinese16x16(2,4,13);
}
void zhi_2(){
	OLED_ShowChinese16x16(3,1,10);
	OLED_ShowChinese16x16(3,2,11);
	OLED_ShowChinese16x16(3,3,14);
	OLED_ShowChinese16x16(3,4,15);
}
void zhi_3(){
	OLED_ShowChinese16x16(4,1,10);
	OLED_ShowChinese16x16(4,2,11);
	OLED_ShowChinese16x16(4,3,16);
	OLED_ShowChinese16x16(4,4,17);
}
void zhi_chu(){
	OLED_ShowChinese16x16(1,1,0);
	OLED_ShowChinese16x16(1,2,1);
	OLED_ShowChinese16x16(1,3,2);
	OLED_ShowChinese16x16(1,4,3);
	OLED_ShowChinese16x16(1,5,4);
	OLED_ShowChinese16x16(1,6,5);
	OLED_ShowChinese16x16(1,7,6);
}
void zhi_ni(){
	OLED_ShowChinese16x16(2,3,7);
	OLED_ShowChinese16x16(2,4,8);
	OLED_ShowChinese16x16(2,5,9);

}
void zhi_shang(){
	while(b<4){
		OLED_Clear();
	OLED_ShowChar8x16(5-b,13,60);
	OLED_ShowChar8x16(5-b,14,60);
	OLED_ShowChar8x16(5-b,15,60);
		break;
	}
}
void zhi_xia(){
	while(b<5){
			OLED_Clear();
	OLED_ShowChar8x16(b,13,60);
	OLED_ShowChar8x16(b,14,60);
	OLED_ShowChar8x16(b,15,60);
		break;
	}
}
void zhi_mode1(){
	OLED_Clear();

	OLED_ShowChinese16x16(1,3,10);
	OLED_ShowChinese16x16(1,4,11);
	OLED_ShowChinese16x16(1,5,14);
	OLED_ShowChinese16x16(1,6,15);
	
OLED_ShowString(2,2,"MAX:");
	OLED_ShowString(3,2,"MIN:");
	OLED_ShowString(4,2,"AVG:");
}
