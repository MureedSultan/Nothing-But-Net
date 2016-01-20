task usercontrol {
	while(1){
		motor[DriveLeft] =  -vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRight] = +vexRT[Ch2] + vexRT[Ch1];

		//----------------------
		//			Launcher
		//----------------------
		if(vexRT[Btn7D] == 1){
			//FwSetGain(0.00025);
			FwMaxPower(127);
			motorSpeed = 1;
			FwVelocitySet( &flywheel, 2620, motorSpeed);
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			FwVelocitySet( &flywheel, 0, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 1760, motorSpeed);
			}else if(vexRT[Btn7U] == 1){
			motorSpeed = 0.7;
			FwVelocitySet( &flywheel, 1565, motorSpeed);
			} else if(vexRT[Btn8D] == 1){
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 2480, motorSpeed);
			}else if(vexRT[Btn8U] == 1) {
			FwMaxPower(75);
			//FwSetGain(0.00005);
			motorSpeed = 0.8;
			FwVelocitySet( &flywheel, 1820, motorSpeed);
		}
		if(vexRT[Btn8L] == 1){
			motor[CatA] = 127;
			motor[CatB] = 127;
		} else {
			motor[CatA] = 0;
			motor[CatB] = 0;
		}

		//----------------------
		//			Collection
		//----------------------
		if(vexRT[Btn6U] == 1){
			if(vexRT[Btn8R] == 1){
				motor[CollectionA] =  127 * 0.65;
				} else {
				motor[CollectionA] =  127;
			}

			motor[CollectionB] =  127;
			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] =  -127;
			motor[CollectionB] =  -127;
			}else{
			motor[CollectionA] =  0;
			motor[CollectionB] =  0;
		}

		if(vexRT[Btn5U] == 1){
			motor[CollectionB] =  127;
			}else if(vexRT[Btn5D] == 1){
			motor[CollectionB] =  -127;
			}else{
			if(vexRT[Btn6U] == 1){
				motor[CollectionB] =  127;
			}
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
