#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "buzzer.h"                  // Device header
#include "oled.h"
#include "button.h"
#include "dc_voltage.h"
#include "dc_current.h"

volatile int b=2;
extern int a;
int main(void){

	 //   RCC_Configuration();
	OLED_Init();
buzzer_init();
	button_init();
	DC_Voltage_Init();
	DC_Current_Init();
	zhi_shang();
	zhi_chu();
	zhi_ni();
 // buzzer();//蜂鸣器模块

//int c=0;

while(1){
//	OLED_ShowString(3,1,"he");
	int c=DC_Voltage_Measure();
	OLED_ShowNum(1,1,c,3);
	OLED_ShowNum(2,1,DC_Current_Measure(),3);
switch(a){
	//上
	case 1:	if(b<4){b++;}else{b=1;}zhi_shang();a=0; break;
	//下

	case 2:if(b<5){b++;}else{b=1;}zhi_xia();a=0;break;
	//确定	
	
	case 3:c++;Delay_ms(200);{
		zhi_mode1();
	OLED_ShowNum(2,8,DC_Voltage_Measure(),3);
	OLED_ShowNum(3,8,DC_Current_Measure(),3);
	}break;
	//取消
		
	case 4:a=0;b=0;break;
	
	default:zhi_chu();zhi_1();zhi_2();zhi_3();

}	




}
}
