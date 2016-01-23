void autonFunc(){
	startTask( FwControlTask );
	FwMaxPower(127);
	FwVelocitySet( &flywheel, 2430, 1);
	wait1Msec(3500);
	Auton_Throw(127, 8);
}

void Auton_Progskills(){
	/*/
	wait1Msec(2800);
	Auton_Collect(127);
	wait1Msec(200);
	FwVelocitySet( &flywheel, 2040, 0.6);
	wait1Msec(2000); //21000

	Auton_Drive_Targeted(FORWARD, 425);
	Auton_Drive_Targeted(BACKWARD, 200, 63);
	wait1Msec(400);
	SensorValue[Gyroscope] = 0;
	wait1Msec(400);
	Auton_Drive_TurnTo(CLOCKWISE, -800, 45);
	wait1Msec(500);
	FwVelocitySet( &flywheel, 2005, 0.9);
	Auton_Drive_Targeted(FORWARD, 1600, 80);
	wait1Msec(500);
	Auton_Collect(0);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -200, 50);
	wait1Msec(500);
	Auton_Drive_Targeted(FORWARD, 700, 63);
	Auton_Drive_Targeted(BACKWARD, 150, 63);
	wait1Msec(500);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 45, 50);
	Auton_Collect(127);
	//*/
	startTask( FwControlTask );
	FwMaxPower(75);
	FwVelocitySet( &flywheel, 1820, 0.8);
	wait1Msec(2800);
	Auton_Collect(127);
	wait1Msec(21000); //21000
	SensorValue[Gyroscope] = 0;
	FwVelocitySet( &flywheel, 0, 0);
	Auton_Drive_Targeted(FORWARD, 400, 63);
	Auton_Drive_TurnTo(CLOCKWISE, -800, 45);
	Auton_Drive_Targeted(BACKWARD, 300, 63);
	Auton_Collect(60);
	wait1Msec(500);
	ResetDriveEncoders();
	Auton_Drive_Targeted(FORWARD, 2000, 70);
	wait1Msec(500);
	Auton_Drive_Targeted(FORWARD, 1050, 70);
	Auton_Collect(0);
	wait1Msec(500);
	SensorValue[Gyroscope] = 0;
	Auton_Collect(-100, 250);
	Auton_Collect(0);
	FwMaxPower(75);
	FwVelocitySet( &flywheel, 1925, 1);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 900, 45);
	wait1Msec(500);
	Auton_Drive_Targeted(BACKWARD, 150, 70);
	wait1Msec(1000);
	Auton_Collect(127);
}
