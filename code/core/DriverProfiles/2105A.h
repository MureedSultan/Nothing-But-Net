// ROBOT:  2105B
int buttonToggleState = 0;
int buttonPressed = 0;

task usercontrol {
	while(true){

		motor[DriveFrontRight] = vexRT[Ch4] - vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRearRight] =  vexRT[Ch4] - vexRT[Ch2] - vexRT[Ch1];
		motor[DriveFrontLeft] = vexRT[Ch4] + vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRearLeft] =  vexRT[Ch4] + vexRT[Ch2] - vexRT[Ch1];

		if(vexRT[Btn5U] == 1){
			motor[LiftLeftA] =  127;
			motor[LiftLeftB] =  127;
			motor[LiftRightA] =  127;
			motor[LiftRightB] =  127;
			}else{
			motor[LiftLeftA] =  0;
			motor[LiftLeftB] =  0;
			motor[LiftRightA] =  0;
			motor[LiftRightB] =  0;
		}

		if(vexRT[Btn5D] == 1){
			motor[LiftLeftA] =  -127;
			motor[LiftLeftB] =  -127;
			motor[LiftRightA] =  -127;
			motor[LiftRightB] =  -127;
			}else{
			motor[LiftLeftA] =  0;
			motor[LiftLeftB] =  0;
			motor[LiftRightA] =  0;
			motor[LiftRightB] =  0;
		}

		if( vexRT[Btn8D] == 1){
			if(! buttonPressed){
				buttonToggleState = 1 - buttonToggleState;
				buttonPressed = 1;
				}else{
				buttonPressed = 0;
			}

			if( buttonToggleState ){
				motor[LauncherLeftA] = 127;
				motor[LauncherLeftB] = 127;
				motor[LauncherRightA] = 127;
				motor[LauncherRightB] = 127;
				}else{
				motor[LauncherLeftA] = 0;
				motor[LauncherLeftB] = 0;
				motor[LauncherRightA] = 0;
				motor[LauncherRightB] = 0;}
		}

	}
}
