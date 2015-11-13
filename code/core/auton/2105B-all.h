void autonFunc(){
	startTask( FwControlTask );
	while(true){
		Auton_Launch();
		sleep(3000);
		Auton_Throw(63, 0, 20);
	}
}

void Auton_Progskills(){
	startTask( FwControlTask );
	FwVelocitySet( &flywheel, 2325, 0.7 ); //2500 norm
}
