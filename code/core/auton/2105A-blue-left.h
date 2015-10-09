void Auton_Blue_Left() {
	autonFunc();
	/*while(true){
		SensorValue[Brake1] = 1;
		SensorValue[Brake2] = 1;
		Auton_Launch(110);
		sleep(2900);
		playSound(soundBeepBeep);
		sleep(1500);
		while(true){
			playSound(soundFastUpwardTones);
			wait1Msec(1750);
		}

		//Wait1Msec(200);

		sleep(3100);

		int count = 0;
		SensorValue[collection_encoder] = 0;
		while(count <= 4){
			if(count < 1){
				Auton_Launch(127);
			}else{
				Auton_Launch(113);
			}
			SensorValue[collection_encoder] = 0;
			while(SensorValue[collection_encoder] < 660){
				Auton_Collect(127);
			}
			if(count > 3 && count <= 4){
				while(SensorValue[collection_encoder] < 80){
					Auton_Collect(127);
				}
			}
			Auton_Collect(0, 550);
			count++;
		}
		while(true){
			Auton_Launch(115);
			Auton_Collect(0);
		}
		allMotorsOff();

	}
	allMotorsOff();*/
}
