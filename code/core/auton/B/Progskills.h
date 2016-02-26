void Auton_Progskills(){
	startTask( FwControlTask );
	//*
	FwMaxPower(73);
	FwVelocitySet(&flywheel, 1825, 0.8);
	wait1Msec(2800);
	Auton_Collect(127);
	wait1Msec(21000); //21000
	//*/
	SensorValue[Gyroscope] = 0;
	FwVelocitySet( &flywheel, 0, 0);
	Auton_Drive_Targeted(FORWARD, 400, 63);
	Auton_Drive_TurnTo(CLOCKWISE, -800, 45);
	Auton_Drive_Targeted(BACKWARD, 300, 63);
	Auton_Collect(80, 110);
	wait1Msec(500);
	ResetDriveEncoders();
	Auton_Drive_Targeted(FORWARD, 2000, 70);
	wait1Msec(1000);
	Auton_Drive_Targeted(FORWARD, 1030, 70);
	wait1Msec(500);
	SensorValue[Gyroscope] = 0;
	Auton_Collect(-127, 127);
	wait1Msec(1000);
	FwMaxPower(73);
	FwVelocitySet( &flywheel, 1900, 0.8);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 850, 50);
	Auton_Drive_Targeted(BACKWARD, 200, 70);
	wait1Msec(500);
	Auton_Collect(127, 127);
}
