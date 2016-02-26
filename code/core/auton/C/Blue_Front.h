void Auton_Blue_Front(){
	startTask( FwControlTask );
	SensorValue[Gyroscope] = 0;
	ResetDriveEncoders();
	FwMaxPower(79);
	FwVelocitySet( &flywheel, 1930, 0.9);
	wait1Msec(1500);
	Auton_Drive_Targeted_PID(FORWARD, 1650, 127);
	Auton_Collect(90, 127);
	wait1Msec(2200);
	Auton_Collect(70, 127);
	FwMaxPower(100);
	FwVelocitySet( &flywheel, 2210, 0.9);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo(CLOCKWISE, -260, 50);
	Auton_Drive_Targeted_PID(BACKWARD, 1350, 127, 5);
	Auton_Collect(0, 127);
	Auton_Drive_Targeted_PID(FORWARD, 500, 127, 5, 1000);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo_PID(COUNTERCLOCKWISE, 320, 58);
	Auton_Collect(127, 127);
	wait1Msec(8000);
}
