void Auton_Red_Back(){
	startTask( FwControlTask );
	SensorValue[Gyroscope] = 0;
	ResetDriveEncoders();
	FwMaxPower(79);
	FwVelocitySet( &flywheel, 1900, 0.9);
	wait1Msec(1500);
	Auton_Drive_Targeted_PID(FORWARD, 1200, 127);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo_PID(COUNTERCLOCKWISE, -80, 70, 5, 1500);
	Auton_Collect(80, 127);
	wait1Msec(3000);
	Auton_Collect(70, 127);
	FwVelocitySet( &flywheel, 2350, 0.9);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo_PID(COUNTERCLOCKWISE, -225, 70, 5, 1500);
	Auton_Drive_Targeted_PID(BACKWARD, 950, 127);
	FwMaxPower(120);
	SensorValue[Gyroscope] = 0;
	Auton_Drive_TurnTo_PID(CLOCKWISE, 150, 60);
	Auton_Collect(70, 127);
	wait1Msec(4500);
}
