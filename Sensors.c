/*
 * Sensors.c
 *
 *  Created on: Jun 15, 2020
 *      Author: LeoTheLegion
 */

#include "Sensors.h"

void setupSensors(void){
}

float readSensor(Sensors sensor){
    return analogRead(sensor);
}
