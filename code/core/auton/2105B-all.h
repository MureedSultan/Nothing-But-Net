void autonFunc(){
	startTask( FwControlTask );
	while(true){
		Auton_Launch();
		sleep(3000);
		Auton_Throw(63, 0, 20);
	}
}

void Auton_Progskills(){
	Auton_Drive_Targeted(BACKWARD, -500);

	/*
	startTask( FwControlTask );
	FwSetGain(0.00030);
	FwVelocitySet( &flywheel, 2350, 0.8);
	sleep(3000);
	Auton_Collect(127);
	sleep(300);
	FwVelocitySet( &flywheel, 2000, 0.8);
	clearTimer(T2);
	while(time1[T2] < 25000){}
	FwVelocitySet( &flywheel, 0, 0);
	//*/
}
