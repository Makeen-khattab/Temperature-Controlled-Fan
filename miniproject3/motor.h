/*
 * motor.h
 *
 *  Created on: Feb 24, 2024
 *      Author: Dell
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "Std_Types.h"
#define DCMOTOR_PORTID					PORTB_ID
#define DCMOTOR_PIN1ID					PIN0_ID
#define DCMOTOR_PIN2ID					PIN1_ID


typedef enum
{
	DCMOTOR_STOP,
	DCMOTOR_ACW,
	DCMOTOR_CW

}DcMotor_State;



void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
