void autonFunc(){
	startTask( FwControlTask );
	FwMaxPower(127);
	FwVelocitySet( &flywheel, 2460, 1);
	wait1Msec(3500);
	Auton_Throw(100, 8);
}

void Auton_Progskills(){
	startTask( FwControlTask );
	FwMaxPower(75);
	FwVelocitySet( &flywheel, 1820, 0.8);
	wait1Msec(2800);
	Auton_Collect(127);
	wait1Msec(21000); //21000
	FwVelocitySet( &flywheel, 0, 0);
	Auton_Drive_Targeted(FORWARD, 400, 63);
	Auton_Drive_TurnTo(CLOCKWISE, -800, 45);
	Auton_Drive_Targeted(BACKWARD, 300, 63);
	wait1Msec(500);
	ResetDriveEncoders();
	Auton_Drive_Targeted(FORWARD, 1800, 70);
	wait1Msec(500);
	Auton_Drive_Targeted(FORWARD, 1050, 70);
	wait1Msec(500);
	SensorValue[Gyroscope] = 0;
	Auton_Collect(-100, 250);
	Auton_Collect(0);
	FwMaxPower(80);
	FwVelocitySet( &flywheel, 1900, 1);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 900, 63);
	wait1Msec(500);
	Auton_Drive_Targeted(BACKWARD, 150, 70);
	wait1Msec(1000);
	Auton_Collect(127);
}
