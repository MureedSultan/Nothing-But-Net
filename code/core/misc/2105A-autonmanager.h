task autonomous {
	if(Competition.Auton == 3) {
		Auton_Progskills();
		AutonDataDump();
		stopTask(autonomous);
	}
	switch(Competition.IsBlue) {
	case true:
		switch(Competition.Drive){
		case true:
			switch(Competition.Front){
				case true:
					Auton_Blue_Front();
				break;
				case false:
					Auton_Blue_Back();
				break;
			}
			break;
		case false:
			Auton_Stay();
			break;
		}
		break;
	case false:
		switch(Competition.Drive){
		case true:
			switch(Competition.Front){
				case true:
					Auton_Red_Front();
				break;
				case false:
					Auton_Red_Back();
				break;
			}
			break;
		case false:
			Auton_Stay();
			break;
		}
		break;
	}
	allMotorsOff();
	AutonDataDump();
}
