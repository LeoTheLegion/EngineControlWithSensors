/*
 * Motor.h
 *
 *  Created on: Jun 15, 2020
 *      Author: LeoTheLegion
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <Energia.h>

#define ENABLE 14
#define CONTROL1 6
#define CONTROL2 7
#define MAXPOWER 225

void setupMotor(void);
void forward(float percentage);
void backward(float percentage);
void brake();

#endif /* MOTOR_H_ */
