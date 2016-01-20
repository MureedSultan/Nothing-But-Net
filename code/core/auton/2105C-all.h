void autonFunc(){
	startTask( FwControlTask );
	while(true){
		FwVelocitySet(&flywheel, 2590, 1);
		sleep(5000);
		Auton_Throw(63, 0, 20);
	}
}

void Auton_Progskills(){
//*/
	startTask( FwControlTask );
	FwVelocitySet( &flywheel, 2220, 0.6);
	wait1Msec(2800);
	Auton_Collect(127);
	wait1Msec(200);
	FwVelocitySet( &flywheel, 2040, 0.6);
	wait1Msec(2000); //21000
	//*/
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
}
