task autonomous {
	if(Competition.Auton == 3) {
		Auton_Progskills();
		AutonDataDump();
		stopTask(autonomous);
	}
	switch(Competition.IsBlue) {
	case true:
		switch(Competition.Front) {
		case true:
			switch(Competition.Drive) {
				case true:
					Auton_Blue_Front_Drive();
				break;
				case false:
					Auton_Blue_Front_Stay();
				break;
			}
			break;
		case false:
			switch(Competition.Drive) {
				case true:
					Auton_Blue_Back_Drive();
				break;
				case false:
					Auton_Blue_Back_Stay();
				break;
			}
			break;
		}
		break;
	case false:
		switch(Competition.Front) {
		case true:
			switch(Competition.Drive) {
				case true:
					Auton_Red_Front_Drive();
				break;
				case false:
					Auton_Red_Front_Stay();
				break;
			}
			break;
		case false:
			switch(Competition.Drive) {
				case true:
					Auton_Red_Back_Drive();
				break;
				case false:
					Auton_Red_Back_Stay();
				break;
			}
			break;
		}
		break;
	}
	allMotorsOff();
	AutonDataDump();
}
