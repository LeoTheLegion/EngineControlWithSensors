/*
 * Sensors.h
 *
 *  Created on: Jun 15, 2020
 *      Author: LeoTheLegion
 */

#ifndef SENSORS_H_
#define SENSORS_H_

#include <Energia.h>

typedef enum Sensors{
    Temperature = 2,
    Light = 3,
    Touch = 4
} Sensors;

void setupSensors(void);
float readSensor(Sensors sensor);


#endif /* SENSORS_H_ */
