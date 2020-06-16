/*
 * Motor.c
 *
 *  Created on: Jun 15, 2020
 *      Author: LeoTheLegion
 */

#include "Motor.h"

void setupMotor(){
    pinMode(ENABLE, OUTPUT);
    pinMode(CONTROL1, OUTPUT);
    pinMode(CONTROL2, OUTPUT);
}

/*
 * percentage = (0-1)
 */
void forward(float percentage){
    setPowerto(percentage);

    digitalWrite(CONTROL1, HIGH);
    digitalWrite(CONTROL2, LOW);
}
/*
 * percentage = (0-1)
 */
void backward(float percentage){
    setPowerto(percentage);

    digitalWrite(CONTROL1, LOW);
    digitalWrite(CONTROL2, HIGH);
}
void brake(){
    analogWrite(ENABLE, 0);

    digitalWrite(CONTROL1, LOW);
    digitalWrite(CONTROL2, LOW);
}


/*
 * percentage = (0-1)
 */
void setPowerto(float percentage){
    analogWrite(ENABLE, MAXPOWER * percentage);
}
