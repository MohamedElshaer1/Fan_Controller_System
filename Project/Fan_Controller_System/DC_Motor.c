/*
 * DC_Motor.c
 *
 *  Created on: Oct 2, 2022
 *      Author: Asus
 */

#include "gpio.h"
#include "DC_Motor.h"
#include "PWM.h"

void DcMotor_Init(void){
	/*configure the output pins for the dc motor*/
	GPIO_setupPinDirection(DC_Motor_IN1_Port, DC_Motor_IN1_Pin, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_Motor_IN2_Port, DC_Motor_IN2_Pin, PIN_OUTPUT);
//	GPIO_setupPinDirection(DC_Motor_EN1_Port, DC_Motor_EN1_Pin, PIN_OUTPUT);

	/*Logic_Low to the enable bit to stop the motor at the beginning*/
	GPIO_writePin(DC_Motor_IN1_Port, DC_Motor_IN1_Pin, LOGIC_LOW);
	GPIO_writePin(DC_Motor_IN2_Port, DC_Motor_IN2_Pin, LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	/* Motor state */
#if(state!=STOP && state!=CW && state !=ACW)

#error "State should be STOP or CW 0r ANTI_CW"

#endif
	if(state==STOP){
		GPIO_writePin(DC_Motor_IN1_Port, DC_Motor_IN1_Pin, LOGIC_LOW);
		GPIO_writePin(DC_Motor_IN2_Port, DC_Motor_IN2_Pin, LOGIC_LOW);
	}
	else if (state==CW) {
		GPIO_writePin(DC_Motor_IN1_Port, DC_Motor_IN1_Pin, LOGIC_LOW);
		GPIO_writePin(DC_Motor_IN2_Port, DC_Motor_IN2_Pin, LOGIC_HIGH);
	}
	else if (state==ACW) {
		GPIO_writePin(DC_Motor_IN1_Port, DC_Motor_IN1_Pin, LOGIC_HIGH);
		GPIO_writePin(DC_Motor_IN2_Port, DC_Motor_IN2_Pin, LOGIC_LOW);
	}

	else{

	}

	/*speed*/
	PWM_Timer0_Start(speed);
}

