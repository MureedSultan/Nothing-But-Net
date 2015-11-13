task autonomous {
	if(Competition.Auton == 3) {
		Auton_Progskills();
		AutonDataDump();
		stopTask(autonomous);
	}
	switch(Competition.IsBlue) {
	case true:
		switch(Competition.Right) {
		case true:
			//Auton_Blue_Right();
			autonFunc();
			break;
		case false:
			//Auton_Blue_Left();
			autonFunc();
			break;
		}
		break;
	case false:
		switch(Competition.Right) {
		case true:
			//Auton_Red_Right();
			autonFunc();
			break;
		case false:
			//Auton_Red_Left();
		autonFunc();
			break;
		}
		break;
	}
	allMotorsOff();
	AutonDataDump();
}
