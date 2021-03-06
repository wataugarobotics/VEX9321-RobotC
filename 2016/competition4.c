#pragma config(Motor,  port1,           motorY1,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           motorX2,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           ramp1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           drop,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           ramp2,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           motorY2,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           motorX1,       tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
}


task autonomous()
{
}


task usercontrol()
{
	while (true)
	{
		//Holo Drive (simple)
		motor[motorY1] = (vexRT[Ch3] + vexRT[Ch1]);
		motor[motorY2] = (vexRT[Ch3] - vexRT[Ch1]);
		motor[motorX1] = (vexRT[Ch4] + vexRT[Ch1]);
		motor[motorX2] = (vexRT[Ch4] - vexRT[Ch1]);

		//ramp control (main)
		if (vexRT[Btn6U] == 1)
		{
			motor[ramp1] = -127;
			motor[ramp2] = -127;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[ramp1] = 127;
			motor[ramp2] = 127;
		}
		else
		{
			motor[ramp1] = 0;
			motor[ramp2] = 0;
		}

		//drop control
		if (vexRT[Btn5U] == 1)
		{
			motor[drop] = 127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[drop] = -127;
		}
		else
		{
			motor[drop] = 0;
		}
	}
}
