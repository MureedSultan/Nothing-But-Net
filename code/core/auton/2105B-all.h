void autonFunc(){
	while(true){
		Auton_Launch();
		sleep(6000);
		Auton_Throw(63, 0, 20);
	}
}

void Auton_Progskills(){
	while(true){
		Auton_Launch();
		Auton_Collect();
	}
}
