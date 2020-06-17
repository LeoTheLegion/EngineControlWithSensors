/*
 * Engine.c
 *
 *  Created on: Jun 15, 2020
 *      Author: LeoTheLegion
 */

#include "Engine.h"

void setupEngine(){
    powerPercentage = 0;
    currentState = Brake;
    setupMotor();

    processState(currentState,powerPercentage);
}

void setEnginePower(float percentage){
    powerPercentage = percentage;
    processState(currentState,powerPercentage);
}

void setState(State newState){
    if(currentState == newState) return;

    int power = 0;
    int rate = 20;
    processState(Brake,0);

    if(currentState != Brake)
        delay(200);

    if(newState != Brake){
        //slowly transition
        while(power <= powerPercentage *100){
                float newPower = (float)power/100.0;
                processState(newState,newPower);
                power = power + 1;
                delay(rate);
            }
    }

    currentState = newState;
}

void processState(State state, float p){
    switch(state){
    case Forward:
        forward(p);
        break;
    case Backward:
        backward(p);
        break;
    case Brake:
        brake();
        break;
    }
}
