
/*
int last = 0;
int current = ( abs(nMotorEncoder[RightA]) + abs(nMotorEncoder[LeftA]) ) / 2;
int diff;
int globalCurr;
while(vexRT[Btn8U] == 1){
current = ( abs(nMotorEncoder[RightA]) + abs(nMotorEncoder[LeftA]) ) / 2;
//writeDebugStreamLine("%d", current - last);
last = current;
diff = current - last;
globalCurr = diff;
delay(1000);
}
writeDebugStreamLine("%d", globalCurr);
//*/

/*	-----------------------------------------
OLD CODE
-----------------------------------------  */

int RPM_Target = 0;
bool IsControllerRunning = false;
const float Kp = 1; // 1.5
const float Ki = 1;//.0001;
const int IntegralLimit = 300; // 100
const float Kd = 1; // 0.2
//bool MinOverride = false;

int Normalize(int speed) {
	if(speed > 127) {
		return 127;
	}
	if(speed < -127) {
		return -127;
	}
	return speed;
}

void Set_RPM_Target(int Adjustment) {
	RPM_Target = ((abs(SensorValue[encoder_left]) + abs(SensorValue[encoder_right])) / 2) + Adjustment;
}

task throw{
	IsControllerRunning = true;
	//const tSensors sensor = encoder_left;
	int sensor = ((abs(SensorValue[encoder_left]) + abs(SensorValue[encoder_right])) / 2);
	int error, previous_error, speed, derivative, integral = 0;
	while(IsControllerRunning) {
		/*
		if(SensorValue[sensor] > 1000 || (SensorValue[sensor] < 100 && !MinOverride)) {
		motor[LiftLeftA] = 0;
		motor[LiftLeftB] = 0;
		continue;
		}
		//*/
		//error = (RPM_Target - SensorValue[sensor]);
		error = (RPM_Target - sensor - sensor);
		if(abs(error) < IntegralLimit) {
			integral += error;
			} else {
			integral = 0;
		}
		derivative = error - previous_error;
		previous_error = error;
		speed = Kp * error + Kd * derivative + Ki * integral;
		writeDebugStreamLine("%d", Normalize(speed));

		motor[LeftA] = Normalize(speed);
		motor[LeftB] = Normalize(speed);
		motor[RightA] = Normalize(speed);
		motor[RightB] = Normalize(speed);
		EndTimeSlice();
		clearDebugStream();

	}

}
