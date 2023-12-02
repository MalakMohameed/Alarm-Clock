////Hellooo KAKA
#include <iostream>
#include <iomanip>
#include <SFML/System.hpp>

#include "ClockModule.h"
#include "ActivatableClock.h"



int main()
{
	ActivatableClock clock;
	
	std::cout << clock.getSystemTime_tm().tm_hour%12<< ":" << clock.getSystemTime_tm().tm_min << std::endl;  ///%12 to convert to 12H instead of 24H

	clock.setRingtone("./Ringtones/goofy1.ogg");

	clock.setAlarmTime(16, 39, 0);

	while (true)
	{
		

		if (clock.getUserTime_tm().tm_hour == clock.getSystemTime_tm().tm_hour && clock.getUserTime_tm().tm_min == clock.getSystemTime_tm().tm_min)
		{
			if (!clock.ringtoneActive) clock.activateRingtone();

			std::cout << "Ringing\n";
			std::cout << clock.getSystemTime_tm().tm_hour % 12 << ":" << clock.getSystemTime_tm().tm_min << "  VS  "  << clock.getUserTime_tm().tm_hour % 12 << ":" << clock.getUserTime_tm().tm_min << std::endl;
		}
		else if (clock.getUserTime_tm().tm_hour <= clock.getSystemTime_tm().tm_hour && clock.getUserTime_tm().tm_min <= clock.getSystemTime_tm().tm_min)
		{
			std::cout << clock.getSystemTime_tm().tm_hour % 12 << ":" << clock.getSystemTime_tm().tm_min << "  VS  " << clock.getUserTime_tm().tm_hour % 12 << ":" << clock.getUserTime_tm().tm_min << std::endl;
			std::cout << "Time IS OVER\n";
			if (clock.ringtoneActive) clock.stopRingtone();

		}
		else {
			std::cout << "Time not up yet\n";
			std::cout << clock.getSystemTime_tm().tm_hour % 12 << ":" << clock.getSystemTime_tm().tm_min << "  VS  " << clock.getUserTime_tm().tm_hour % 12 << ":" << clock.getUserTime_tm().tm_min << std::endl;
		}


	}
	
	
}
