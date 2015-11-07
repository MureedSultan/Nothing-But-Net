void autonFunc(){
	Auton_DefineLauncher(LeftB, RightB, LeftA, RightA, 0, 0);
	while(true){
		SensorValue[Brake1] = 1;
		SensorValue[Brake2] = 1;
		Auton_Launch(127);
		sleep(3000);
		int count = 0;
		SensorValue[collection_encoder] = 0;
		while(count < 4){
			if(count < 1){
				Auton_Launch(120);
			}else{
				Auton_Launch(109);
			}
			SensorValue[collection_encoder] = 0;
			while(SensorValue[collection_encoder] < 660){
				Auton_Collect(127);
			}
			if(count == 2){
				Auton_Collect(0, 850);
			}
			Auton_Collect(0, 850);
			SensorValue[collection_encoder] = 0;
			if(count <= 4){
				while(SensorValue(collection_encoder) <= 210){
					Auton_Collect(127);
				}
			}
			count++;
		}
		allMotorsOff();
	}
	allMotorsOff();
}
