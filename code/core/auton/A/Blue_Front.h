void Auton_Blue_Front(){
	startTask( FwControlTask );
	SensorValue[Gyroscope] = 0;
	ResetDriveEncoders();
	FwMaxPower(82);
	FwVelocitySet( &flywheel, 1900, 0.9);
	wait1Msec(1500);
	Auton_Drive_Targeted_PID(FORWARD, 1150, 127);
	Auton_Collect(110, 127);
	wait1Msec(2200);
	Auton_Collect(70, 127);
	FwMaxPower(85);
	FwVelocitySet( &flywheel, 2140, 0.9);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo(CLOCKWISE, -250, 50);
	Auton_Drive_Targeted_PID(BACKWARD, 1000, 127, 5);
	wait1Msec(500);
	Auton_Collect(0, 127);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_Targeted_PID(FORWARD, 600, 127, 5, 1000);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 190, 40);
	Auton_Collect(90, 127);
	wait1Msec(8000);
}
