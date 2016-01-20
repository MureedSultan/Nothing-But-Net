#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    PowerExpander,  sensorAnalog)
#pragma config(Sensor, in2,    Gyroscope,      sensorGyro)
#pragma config(Sensor, dgtl1,  enc,            sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  pnu_r,          sensorDigitalOut)
#pragma config(Sensor, dgtl5,  pnu_l,          sensorDigitalOut)
#pragma config(Sensor, dgtl6,  pnu_lift1,      sensorDigitalOut)
#pragma config(Sensor, dgtl7,  pnu_lift2,      sensorDigitalOut)
#pragma config(Sensor, dgtl8,  pnu_lift3,      sensorDigitalOut)
#pragma config(Sensor, dgtl9,  light,          sensorDigitalOut)
#pragma config(Sensor, dgtl10, jumper1,        sensorTouch)
#pragma config(Sensor, dgtl11, jumper2,        sensorTouch)
#pragma config(Sensor, dgtl12, jumper3,        sensorTouch)
#pragma config(Sensor, I2C_1,  DriveEncoderLeft, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  DriveEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           LLT,           tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           LLB,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           CollectionB,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           DriveFrontLeft, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           DriveRearLeft, tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port6,           DriveFrontRight, tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,          	DriveRearRight, tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port8,           CollectionA,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LRT,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          LRB,           tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// TO CHANGE LCD THING, GO TO LCD FILE LINE: 272
// LINE 58 COMP.H
#define NoLiftLimits
#define OneLiftEncoder
#define HasGyro
//#define MultiDriveEncoders.
#if defined(_DEBUG)
const string FILE = __FILE__;
#endif

int motorSpeed;
char Robot = 'C';
#include "core/v1/pid/b.h" //same as B bot
#include "core/v1/core.h"
#include "core/DriverProfiles/2105C.h"
#include "core/auton/2105C-all.h"
#include "core/misc/2105A-autonmanager.h"

void ResetDriveEncoders() {
	nMotorEncoder[DriveEncoder] = 0;
	nMotorEncoder[DriveEncoderLeft] = 0;
	SensorValue[DriveEncoder] = 0;
	SensorValue[DriveEncoderLeft] = 0;
}

void init() {
	SensorValue[enc] = 0;
	SensorValue[Gyroscope] = 0;
}
