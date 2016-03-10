void Auton_Red_Front(){
	startTask( FwControlTask );
	SensorValue[Gyroscope] = 0;
	ResetDriveEncoders();
	FwMaxPower(79);
	FwVelocitySet( &flywheel, 1800, 0.9);
	wait1Msec(1500);
	Auton_Drive_Targeted_PID(FORWARD, 1200, 127);
	Auton_Collect(110, 127);
	wait1Msec(2200);
	Auton_Collect(70, 127);
	FwMaxPower(80);
	FwVelocitySet( &flywheel, 2050, 0.9);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 250, 50);
	Auton_Drive_Targeted_PID(BACKWARD, 1000, 127, 5);
	Auton_Collect(0, 127);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_Targeted_PID(FORWARD, 600, 127, 5, 1000);
	Auton_Drive_TurnTo(CLOCKWISE, -170, 40);
	Auton_Collect(90, 127);
	wait1Msec(8000);
}
