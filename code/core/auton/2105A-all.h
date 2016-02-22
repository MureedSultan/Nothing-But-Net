void autonFunc(){
/*---------- RED RIGHT DRIVE AUTON
	startTask( FwControlTask );
	SensorValue[Gyroscope] = 0;
	ResetDriveEncoders();
	FwMaxPower(83);
	FwVelocitySet( &flywheel, 1950, 0.9);
	wait1Msec(1500);
	Auton_Drive_Targeted_PID(FORWARD, 1200, 127);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo_PID(CLOCKWISE, 150, 70, 5, 1500);
	Auton_Collect(110, 127);
	wait1Msec(2200);
	Auton_Collect(70, 127);
	FwVelocitySet( &flywheel, 2350, 0.9);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 220, 50);
	Auton_Drive_Targeted_PID(BACKWARD, 850, 127, 5);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo(CLOCKWISE, -50, 40);
	wait1Msec(3000);
//*/

//*---------- RED RIGHT DRIVE AUTON
	startTask( FwControlTask );
	FwMaxPower(127);
	FwVelocitySet( &flywheel, 2450, 1);
	wait1Msec(3100);
	while(true){
		Auton_Collect(127, 127);
		wait1Msec(350);
		Auton_Collect(0, 0);
		wait1Msec(1100);
	}
//*/

/*
	SensorValue[Gyroscope] = 0;
	ResetDriveEncoders();
	Auton_Drive_TurnTo_PID(CLOCKWISE, -450, 80);
	//Auton_Drive_Targeted_PID(BACKWARD, 950, 60, 1);
//*/
}

void Auton_Progskills(){
	//*
	Auton_Launch(127);
	wait1Msec(23000); //21000
	Auton_Launch(0);
	//*/
	SensorValue[Gyroscope] = 0;
	Auton_Drive_Targeted(FORWARD, 160, 55);
	Auton_Drive_TurnTo(CLOCKWISE, -800, 45);
	Auton_Drive_Targeted(BACKWARD, 150, 63, 500);
	ResetDriveEncoders();
	Auton_Collect(70, 127);
	Auton_Drive_Targeted(FORWARD, 150, 45);
	Auton_Drive_Targeted(FORWARD, 400, 90);
	Auton_Drive_Targeted(FORWARD, 150, 30);
	wait1Msec(250);
	Auton_Drive_Targeted(FORWARD, 150, 30);
	Auton_Drive_Targeted(FORWARD, 950, 50, 2000, 40);
	Auton_Drive_Targeted(FORWARD, 150, 30);
	Auton_Collect(-70, 127);
	wait1Msec(250);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 23, 40);
	Auton_Collect(0, 0);
	Auton_Drive_Targeted(BACKWARD, 115, 55);
	//*
	Auton_Launch(127);
	wait1Msec(20000);
	FwMaxPower(83);
	motorSpeed = 0.9;
	FwVelocitySet( &flywheel, 1900, motorSpeed);
	wait1Msec(3000);
	Auton_Drive_TurnTo(CLOCKWISE, 0, 60);
	Auton_Collect(127, 127);
	wait1Msec(10000);

	//*/
}
