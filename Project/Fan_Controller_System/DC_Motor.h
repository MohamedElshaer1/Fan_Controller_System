/*
 * DC_Motor.h
 *
 *  Created on: Oct 2, 2022
 *      Author: Mohamed Elshaer
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                      H-Bridge definitions                                   *
 *******************************************************************************/

#define DC_Motor_IN1_Port       PORTB_ID
#define DC_Motor_IN1_Pin       	PIN0_ID

#define DC_Motor_IN2_Port       PORTB_ID
#define DC_Motor_IN2_Pin        PIN1_ID

#define DC_Motor_IN3_Port       PORTB_ID
#define DC_Motor_IN3_Pin       	PIN0_ID

#define DC_Motor_IN4_Port       PORTB_ID
#define DC_Motor_IN4_Pin        PIN1_ID


typedef enum{
	STOP,CW,ACW
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DcMotor_Init(void);


void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
