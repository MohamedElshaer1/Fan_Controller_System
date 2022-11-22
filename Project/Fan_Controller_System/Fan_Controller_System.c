/*
 * main.c
 *
 *  Created on: Oct 2, 2022
 *      Author: Asus
 */

#include "lcd.h"
#include "ADC.h"
#include "lm35_sensor.h"
#include "DC_Motor.h"

ADC_ConfigType project ={internalVoltage,F_CPU_8_};

const ADC_ConfigType * Config_Ptr =&project;



void main(void){
	uint8 temp;

	ADC_init(Config_Ptr);
	DcMotor_Init();
	LCD_init();

	LCD_displayString("FAN IS ");
	LCD_moveCursor(1, 0);
	LCD_displayString("Temp =    C");
	while(1){
		temp=LM35_getTemperature();

		LCD_moveCursor(0,8);
		if(temp>30){
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}
		else{
			LCD_displayString("OFF");
		}
		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,7);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}


		if(temp<30){
			DcMotor_Rotate(STOP,0);
		}
		else if (temp>= 30 &&temp<60) {
			DcMotor_Rotate(CW,25);
		}
		else if (temp>= 60 &&temp<90) {
			DcMotor_Rotate(CW,50);
		}
		else if (temp>= 90 &&temp<120) {
			DcMotor_Rotate(CW,75);
		}
		else{
			DcMotor_Rotate(CW,100);
		}
	}
}

