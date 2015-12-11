void autonFunc(){
	startTask( FwControlTask );
	while(true){
		FwVelocitySet(&flywheel, 2570, 1);
		sleep(5000);
		Auton_Throw(63, 0, 20);
	}
}

void Auton_Progskills(){

}
