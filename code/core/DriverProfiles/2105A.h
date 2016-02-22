task usercontrol {
	//int motorSpeed = 0;
	int buttonToggleState = 0;
	int buttonPressed = 0;
	int drivemultiplier = 1;
	int dval = 0;
	int deadband = 10;
	while(true){
		//----------------------
		//			Drive
		//----------------------

		dval = (vexRT[Ch2] - vexRT[Ch1] + (vexRT[Ch3]*0.5) - (vexRT[Ch4]*0.5) * drivemultiplier) * drivemultiplier;
		motor[DriveRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = (-vexRT[Ch2] - vexRT[Ch1] - (vexRT[Ch3]*0.5) - (vexRT[Ch4]*0.5) * drivemultiplier) * drivemultiplier;
		motor[DriveLeft]  = dval < deadband && dval > -deadband ? 0 : dval;


		//----------------------
		//			Launcher
		//----------------------

		// HAMMER
		if( vexRT[ Btn8D ] == 1 ){
			if( ! buttonPressed ){
				buttonToggleState = 1 - buttonToggleState;
				buttonPressed = 1;
			}
			}else{
			buttonPressed = 0;
		}

		if(buttonToggleState){
			motor[CT] = 127;
			motor[CM] = 127;
			motor[CB] = 127;
			}else{
			motor[CT] = 0;
			motor[CM] = 0;
			motor[CB] = 0;
		}

		// FLYWHEEL
		if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			FwVelocitySet( &flywheel, 0, motorSpeed);
			}else if(vexRT[Btn7D] == 1){
			//FwSetGain(0.00025);
			FwMaxPower(127);
			motorSpeed = 1;
			FwVelocitySet( &flywheel, 2500, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			FwMaxPower(127);
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 2100, motorSpeed);
			}else if(vexRT[Btn7U] == 1){
			FwMaxPower(82);
			motorSpeed = 0.7;
			FwVelocitySet( &flywheel, 1600, motorSpeed);
			}else if(vexRT[Btn8U] == 1){
			FwMaxPower(83);
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 1900, motorSpeed);
		}

		//----------------------
		//			Collection
		//----------------------
		if(vexRT[Btn6U] == 1){
			motor[CollectionA] = 127;
			motor[CollectionB] = 127;
			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] = -127;
			motor[CollectionB] = -127;
			}else{
			motor[CollectionB] = 0;
			if(vexRT[Btn5U] == 1){
				motor[CollectionA] =  127;
				}else if(vexRT[Btn5D] == 1){
				motor[CollectionA] =  -127;
				} else {
				motor[CollectionA] =  0;
			}
		}


	}
}
