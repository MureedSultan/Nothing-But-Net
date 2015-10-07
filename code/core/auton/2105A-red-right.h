void Auton_Red_Right() {
	clearTimer(T1);
	while(time1[T1] <= 15){
		SensorValue[Brake1] = 1;
		SensorValue[Brake2] = 1;
		Auton_Launch(127);
		sleep(3000);
		int count = 0;
		SensorValue[collection_encoder] = 0;
		while(count < 4){
			if(count < 1){
				Auton_Launch(127);
			}else{
				Auton_Launch(113);
			}
			SensorValue[collection_encoder] = 0;
			while(SensorValue[collection_encoder] < 660){
				Auton_Collect(127);
			}
			Auton_Collect(0, 650);
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
