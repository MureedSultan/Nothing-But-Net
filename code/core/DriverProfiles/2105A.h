task usercontrol {
	while(true){
		motor[DriveFrontRight] = vexRT[Ch4] - vexRT[Ch2] - vexRT[Ch1];
		motor[DriveRearRight] =  vexRT[Ch4] - vexRT[Ch2] + vexRT[Ch1];
		motor[DriveFrontLeft] = vexRT[Ch4] + vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRearLeft] =  vexRT[Ch4] + vexRT[Ch2] - vexRT[Ch1];

		bool pressed = false;

		if(vexRT[Btn7D] == 1){
			nMotorPIDSpeedCtrl[LeftA] = mtrSpeedReg;
			nMotorPIDSpeedCtrl[RightA] = mtrSpeedReg;
			nMotorPIDSpeedCtrl[LeftB] = mtrSpeedReg;
			nMotorPIDSpeedCtrl[RightB] = mtrSpeedReg;
			slaveMotor(RightB, RightA);
			slaveMotor(LeftB, LeftA);
			motor[LeftA] = 113;
			motor[RightA] = 113;
			startTask(launchSound);
			}else if(vexRT[Btn7R] == 1){
			motor[LeftA] = 0;
			motor[LeftB] = 0;
			motor[RightA] = 0;
			motor[RightB] = 0;
			stopTask(launchSound);
			}else if(vexRT[Btn7L] == 1){
			motor[LeftA] = 98;
			motor[LeftB] = 98;
			motor[RightA] = 98;
			motor[RightB] = 98;
			startTask(launchSound);
			}else if(vexRT[Btn7U] == 1){
			motor[LeftA] = 84;
			motor[LeftB] = 84;
			motor[RightA] = 84;
			motor[RightB] = 84;
			startTask(launchSound);
		}

		if(vexRT[Btn5U] == 1){
			motor[CollectB] =  127;
			}else if(vexRT[Btn5D] == 1){
			motor[CollectB] =  -127;
			}else{
			motor[CollectB] =  0;
		}
		if(vexRT[Btn6U] == 1){
			motor[CollectA] =  127;
			}else if(vexRT[Btn6D] == 1){
			motor[CollectA] =  -127;
			}else{
			motor[CollectA] =  0;
		}
		if(vexRT[Btn8D] == 1){
			SensorValue[Brake1] = 1;
			SensorValue[Brake2] = 1;
			}else if(vexRT[Btn8R] == 1){
			SensorValue[Brake1] = 0;
			SensorValue[Brake2] = 0;
		}
		if(vexRT[Btn8L] == 1){
			clearSounds();
		}
	}
}
