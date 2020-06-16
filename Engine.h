/*
 * Engine.h
 *
 *  Created on: Jun 15, 2020
 *      Author: LeoTheLegion
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include "Motor.h"

typedef enum State{
    Forward,
    Backward,
    Brake
}State;

float powerPercentage;
State currentState;

void setupEngine(void);

void setEnginePower(float percentage);

void setState(State newState);

void processState(State state, float p);

#endif /* ENGINE_H_ */
