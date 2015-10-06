void Auton_Red_Right() {
	clearTimer(T1);
	while(time1[T1] <= 15){
		SensorValue[Brake1] = 1;
		SensorValue[Brake2] = 1;
		Auton_Launch(110);
		sleep(2500);
		int count = 0;
		SensorValue[collection_encoder] = 0;
		while(count < 5){
			Auton_Collect(127, 780);
			Auton_Collect(0, 400);
			if(count >= 4){
				Auton_Collect(50, 350);
				while(SensorValue[collection_encoder] <= 3300){
					Auton_Collect(50);
				}
			}
			count++;
		}
		while(true){
			Auton_Launch(115);
			Auton_Collect(0);
		}
		allMotorsOff();
	}
	allMotorsOff();
}
