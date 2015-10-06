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
			Auton_Blue_Right();
			break;
		case false:
			Auton_Blue_Left();
			break;
		}
		break;
	case false:
		switch(Competition.Right) {
		case true:
			Auton_Red_Right();
			break;
		case false:
			Auton_Red_Left();
			break;
		}
		break;
	}
	allMotorsOff();
	AutonDataDump();
}
