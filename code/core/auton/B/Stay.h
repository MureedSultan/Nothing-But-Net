void Auton_Stay(){
	//Auton_Drive_TurnTo(COUNTERCLOCKWISE, 550);
	ResetDriveEncoders();
	Auton_Drive_Targeted(BACKWARD, 300);
	/*
	startTask( FwControlTask );
	FwMaxPower(125);
	FwVelocitySet( &flywheel, 2280, 0.8);
	motor[LPT] = 127;
	motor[LPB] = 127;
	wait1Msec(1200);
	motor[LPT] = 0;
	motor[LPB] = 0;
	wait1Msec(1900);
	while(true){
		if(SensorValue[collection_limit] == 1){
			motor[CollectionA] = 0;
			motor[CollectionB] = 0;
			while(abs(returnError) >= 35){
				motor[CollectionA] = 0;
				motor[CollectionB] = 0;
				wait1Msec(25);
			}
			motor[CollectionA] = 127;
			motor[CollectionB] = 127;
			while(SensorValue[collection_limit] == 1){
				motor[CollectionA] = 127;
				motor[CollectionB] = 127;
			}
			} else {
			motor[CollectionA] = 127;
			motor[CollectionB] = 127;
		}
	}
	//*/
}
