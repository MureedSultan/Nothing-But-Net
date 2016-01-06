#pragma config(Motor,  port1,           left_back,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           left_front,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           right_front,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           right_back,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lift_top,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          lift_bottom,   tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true)
	{
		motor[left_back] = vexRT[Ch1] -vexRT[Ch2] - vexRT[Ch4];
		motor[left_front] = -vexRT[Ch1] -vexRT[Ch2] - vexRT[Ch4];
		motor[right_back] = vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4];
		motor[right_front] =-vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4] ;
		if(vexRT[Btn6U]==1) {
			// motor[] =
		motor[lift_bottom] = 127;
		motor[lift_top] = 127;

			} else if(vexRT[Btn6D]==1) {
			motor[lift_bottom] = -127;
		motor[lift_top] = -127;
			// motor[] =
			} else {
			motor[lift_bottom] = 0;
		motor[lift_top] = 0;
			// motor[]= 0
		}
	}

}