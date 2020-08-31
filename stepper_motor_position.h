#ifndef STEPPER_MOTOR_POSITION_H_
#define STEPPER_MOTOR_POSITION_H_

#include "position_table.h"
#include "avr/io.h"

extern uint8_t datapan;
extern uint16_t datatilt;


void MotorPosition(void);

#endif /* STEPPER_MOTOR_POSITION_H_ */