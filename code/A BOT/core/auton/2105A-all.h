void autonFunc(){
	while(true){
		SensorValue[Brake1] = 1;
		SensorValue[Brake2] = 1;
		Auton_Launch(127);
		sleep(3000);
		int count = 0;
		SensorValue[collection_encoder] = 0;
		while(count < 4){
			Auton_Launch(125);
			SensorValue[collection_encoder] = 0;
			while(SensorValue[collection_encoder] < 660){
				Auton_Collect(127);
			}

			Auton_Collect(0, 1500);
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
