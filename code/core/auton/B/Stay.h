void Auton_Stay(){
	//*
	startTask( FwControlTask );
	FwSetGain(1);
	FwMaxPower(125);
	FwVelocitySet( &flywheel, 2390, 0.8);
	motor[LPT] = 127;
	motor[LPB] = 127;
	wait1Msec(1200);
	motor[LPT] = 0;
	motor[LPB] = 0;
	wait1Msec(1900);
	while(true){
		Auton_Collect(127, 127);
		wait1Msec(350);
		Auton_Collect(0, 0);
		wait1Msec(500);
	}
	//*/
}
