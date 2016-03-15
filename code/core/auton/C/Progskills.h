void Auton_Progskills(){
	startTask( FwControlTask );
	//*
	FwMaxPower(69);
	FwVelocitySet( &flywheel, 1860, 0.4);
	wait1Msec(2800);
	Auton_Collect(127);
	wait1Msec(21000); //21000
	//*/
	FwVelocitySet( &flywheel, 0, 0);
	Auton_Drive_Targeted(FORWARD, 450, 127);
	Auton_Drive_TurnTo(CLOCKWISE, -800, 80);
	Auton_Drive_Targeted(BACKWARD, 300, 127);
	wait1Msec(500);
	ResetDriveEncoders();
	Auton_Drive_Targeted(FORWARD, 1800, 70);
	wait1Msec(500);
	Auton_Drive_Targeted(FORWARD, 1400, 70);
	wait1Msec(500);
	SensorValue[Gyroscope] = 0;
	Auton_Collect(100, -100, 450);
	Auton_Collect(100, 0);
	FwMaxPower(68);
	FwVelocitySet( &flywheel, 1900, 0.4);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 845, 65);
	Auton_Collect(0,0);
	wait1Msec(500);
	Auton_Drive_Targeted(BACKWARD, 130);
	wait1Msec(1000);
	Auton_Collect();
	wait1Msec(21000); //21000
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 680);
	Auton_Drive_Targeted(FORWARD, 400, 70);
	wait1Msec(500);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo(CLOCKWISE, -480);
}
