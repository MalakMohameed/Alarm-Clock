////Hellooo KAKA
#include <iostream>
#include <iomanip>
#include <SFML/System.hpp>

#include "ClockModule.h"
#include "ActivatableClock.h"
#include "AlarmClock.h"
#include "TimerClock.h"

////Alarm Now Almost Fully Functional minus the need to overload the function isTimeToTing() not to check seconds.
///Timer needs to be fixed as the ringtone only plays if the userTime_tm is the exact same as the systemTime_tm sec by sec,
///Which makes it ring for just a sec and then nothing 



int main()
{
	AlarmClock clock;
	TimerClock timer;
	
	std::cout << clock.getSystemTime_tm().tm_hour<< ":" << clock.getSystemTime_tm().tm_min << ":" << clock.getSystemTime_tm().tm_sec << std::endl;  ///%12 to convert to 12H instead of 24H
	
	timer.setRingtone("./Ringtones/Radar.ogg");
	//timer.setRingtone();

	//clock.setAlarmTime(22, 20,0);
	//clock.setDaysToRing({ 6 });

	timer.setTimer(00, 00, 05);
	std::cout << timer.getUserTime_tm().tm_hour << ":" << timer.getUserTime_tm().tm_min << ":" << timer.getUserTime_tm().tm_sec << "\n";
	//clock.activateRingtone();
	timer.activateRingtone();
	while (true)
	{	
		if (timer.isTimeToRing())
		{
			timer.activateRingtone();
		}
		else timer.stopRingtone();

	}
	
}
