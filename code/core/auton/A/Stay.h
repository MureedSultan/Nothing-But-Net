void Auton_Stay(){
	startTask( FwControlTask );
	FwMaxPower(120);
	FwVelocitySet( &flywheel, 2430, 0.8);
	wait1Msec(3600);
	while(true){
		Auton_Collect(127, 127);
		wait1Msec(350);
		Auton_Collect(0, 0);
		wait1Msec(1150);
	}
}
