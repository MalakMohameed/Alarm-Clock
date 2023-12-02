////Hellooo KAKA
#include <iostream>
#include <iomanip>
#include <SFML/System.hpp>

#include "ClockModule.h"
#include "ActivatableClock.h"
#include "AlarmClock.h"



int main()
{
	AlarmClock clock;
	
	std::cout << clock.getSystemTime_tm().tm_hour%12<< ":" << clock.getSystemTime_tm().tm_min << std::endl;  ///%12 to convert to 12H instead of 24H

	clock.setRingtone("./Ringtones/goofy1.ogg");

	clock.setAlarmTime(15, 16, 0);
	clock.setDaysToRing({ 6 });


	
	while (true)
	{	
		if (clock.isTimeToRing())
		{
			clock.activateRingtone();
		}

	}
	
}
