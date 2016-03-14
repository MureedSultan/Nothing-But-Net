void Auton_Progskills(){
	startTask( FwControlTask );
	//*
	Auton_Launch(127);
	wait1Msec(21000); //21000
	Auton_Launch(0);
	//*/
	SensorValue[Gyroscope] = 0;
	Auton_Drive_Targeted(FORWARD, 160, 55);
	Auton_Drive_TurnTo(CLOCKWISE, -800, 45);
	Auton_Drive_Targeted(BACKWARD, 150, 63, 500);
	ResetDriveEncoders();
	Auton_Collect(70, 127);
	Auton_Drive_Targeted_PID(BACKWARD, 1245, 90);
	wait1Msec(1000);
	Auton_Drive_Targeted_PID(BACKWARD, 1125, 127);
	Auton_Collect(-70, 127);
	Auton_Drive_TurnTo_PID(CLOCKWISE, 60, 60, 5, 1000);
	Auton_Collect(0, 0);
	Auton_Drive_Targeted(BACKWARD, 150, 55);
	//*
	Auton_Launch(127);
	wait1Msec(21000);
	Auton_Launch(0);
	FwMaxPower(75);
	motorSpeed = 0.9;
	FwVelocitySet( &flywheel, 1900, motorSpeed);
	wait1Msec(3000);
	/*
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo(CLOCKWISE, 10, 60);
	*/
	Auton_Collect(127, 127);
	wait1Msec(10000);
}
