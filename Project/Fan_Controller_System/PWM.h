/*
 * PWM.h
 *
 *  Created on: Oct 2, 2022
 *      Author: Mohamed Elshaer
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/*******************************************************************************
*                                Definitions                                  *
*******************************************************************************/
#define DC_Motor_EN1_Port       PORTB_ID
#define DC_Motor_EN1_Pin       	PIN3_ID


#define DC_Motor_EN2_Port       PORTB_ID
#define DC_Motor_EN2_Pin       	PIN3_ID

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
