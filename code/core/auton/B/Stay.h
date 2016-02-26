void Auton_Stay(){
startTask( FwControlTask );
	FwGain(0.0003);
	FwMaxPower(120);
	FwVelocitySet( &flywheel, 2470, 1);
	wait1Msec(3500);
	while(true){
		Auton_Collect(127, 127);
		wait1Msec(400);
		Auton_Collect(0, 0);
		wait1Msec(1150);
	}
}
