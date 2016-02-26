void Auton_Stay(){
	startTask( FwControlTask );
	FwMaxPower(82);
	FwVelocitySet( &flywheel, 2450, 1);
	wait1Msec(3000);
	while(true){
		motor[CollectionA] = 127;
		motor[CollectionB] = 127;
	}
}
