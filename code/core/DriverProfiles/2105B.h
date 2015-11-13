task usercontrol {
	while(1){
		motor[DriveLeft] =  vexRT[Ch1] - vexRT[Ch2] ;
		motor[DriveRight] = -vexRT[Ch1] - vexRT[Ch2];
		//----------------------
		//			Launcher
		//----------------------
		if(vexRT[Btn7D] == 1){
			motorSpeed = 0.7;
			FwVelocitySet( &flywheel, 2325, motorSpeed);
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			FwVelocitySet( &flywheel, 0, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			motorSpeed = 0.8;
			FwVelocitySet( &flywheel, 1900, motorSpeed);
			}else if(vexRT[Btn7U] == 1){
			motorSpeed = 0.66;
			FwVelocitySet( &flywheel, 1650, motorSpeed);
			} else if(vexRT[Btn8D] == 1){
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 2480, motorSpeed);
		}

		if(vexRT[Btn8U] == 1) {
			motor[CollectionB] = 127;
			wait1Msec(800);
			motor[CollectionB] = 0;
			wait1Msec(1200);
		}





		//----------------------
		//			Collectionion
		//----------------------
		if(vexRT[Btn6U] == 1){
			motor[CollectionA] =  127;
			motor[CollectionB] =  127;
			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] =  -127;
			motor[CollectionB] =  -127;
			}else{
			motor[CollectionA] =  0;
			motor[CollectionB] =  0;
		}
		if(vexRT[Btn6U] == 1){
			motor[CollectionA] =  127;
			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] =  -127;
			}else{
			motor[CollectionA] =  0;
		}

		if(vexRT[Btn5U] == 1){
			motor[CollectionB] =  127;
			}else if(vexRT[Btn5D] == 1){
			motor[CollectionB] =  -127;
			}else{
			motor[CollectionB] =  0;
		}

		//----------------------
		//		Driver Skills
		//----------------------
		/*
		if(vexRT[Btn5U] == 1){
		while(true){
		Auton_Launch();
		sleep(3000);
		Auton_Throw(63, 0, 4);
		while(true){
		Auton_Collect();
		}
		}
		}
		*/
	}
}
