task usercontrol {
	while(true){
		motor[DriveFrontRight] = vexRT[Ch4] - vexRT[Ch2] - vexRT[Ch1];
		motor[DriveRearRight] =  vexRT[Ch4] - vexRT[Ch2] + vexRT[Ch1];
		motor[DriveFrontLeft] = vexRT[Ch4] + vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRearLeft] =  vexRT[Ch4] + vexRT[Ch2] - vexRT[Ch1];
		if(vexRT[Btn7D] == 1){
			motor[LeftA] = 127;
			motor[LeftB] = 127;
			motor[RightA] = 127;
			motor[RightB] = 127;
			}else if(vexRT[Btn7R] == 1){
			motor[LeftA] = 0;
			motor[LeftB] = 0;
			motor[RightA] = 0;
			motor[RightB] = 0;
			}else if(vexRT[Btn7L] == 1){
			motor[LeftA] = 95;
			motor[LeftB] = 95;
			motor[RightA] = 95;
			motor[RightB] = 95;
			}else if(vexRT[Btn7U] == 1){
			motor[LeftA] = 82;
			motor[LeftB] = 82;
			motor[RightA] = 82;
			motor[RightB] = 82;
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
	}
}
