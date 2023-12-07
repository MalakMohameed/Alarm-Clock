////Hellooo KAKA
#include <iostream>
#include <iomanip>
#include <SFML/System.hpp>
#include <SFML/System.hpp>


#include "ClockModule.h"
#include "ActivatableClock.h"
#include "AlarmClock.h"
#include "TimerClock.h"
#include "HashAlarm.h"

////Alarm Now Almost Fully Functional minus the need to overload the function isTimeToTing() not to check seconds.
///Timer needs to be fixed as the ringtone only plays if the userTime_tm is the exact same as the systemTime_tm sec by sec,
///Which makes it ring for just a sec and then nothing.	
/// 
/// 

void checkForAlarms(HashAlarm clocks)
{
	while (true)
	{

		for (int i = 0; i < clocks.getCapacity(); i++)
		{
			//std::cout << i << clocks.getElementIterator(i).clock.hash() << '\n';
			//std::cout << clocks.getElementIterator(i).status << "\n---------------";
			//if(clocks.getElementIterator(i).clock.hash() != -26216) std::cout << "************\n----------\n";

			if (clocks.getElementIterator(i).clock.isTimeToRing() && clocks.getElementIterator(i).isPlaying != true)
			{
				clocks.getElementIterator(i).clock.activateRingtone();
				std::cout << i << "Supposed To Ring\n";
				clocks.getElementIterator(i).setisPlaying(false);
				//continue;
			}
			else {
				clocks.getElementIterator(i).clock.stopRingtone();
				clocks.getElementIterator(i).setisPlaying(false);
		}
		}
		

	}
	

}

int main()
{
	HashAlarm ClockStorage;
	
	//clockLogicThread.launch();
	AlarmClock clock;
    TimerClock timer ;
	
	
	std::cout << clock.getSystemTime_tm().tm_hour<< ":" << clock.getSystemTime_tm().tm_min << ":" << clock.getSystemTime_tm().tm_sec << std::endl;  ///%12 to convert to 12H instead of 24H
	
	clock.setRingtone("./Ringtones/goofy1.ogg");
	//timer.setRingtone();

	clock.setAlarmTime(20, 04,0);
	clock.setDaysToRing({ 2 });

	timer.setTimer(00, 00, 05);
	std::cout << timer.getUserTime_tm().tm_hour << ":" << timer.getUserTime_tm().tm_min << ":" << timer.getUserTime_tm().tm_sec << "\n";
//	clock.activateRingtone();	
//	timer.activateRingtone();

	ClockStorage.insertQuadratic(clock.hash(), clock);
	//hashTable.insertQuadratic(timer.hash(), timer);
	std::cout << ClockStorage.numberOfAlarms() << '\n';

	
	    //AlarmClock clock;
		//TimerClock timer;
		int hours = 0;
		int min = 0;
		int sec = 0;
		int choice;
		int day = 0;
		std::vector<int> daysToRing;
		std::cout << clock.getSystemTime_tm().tm_hour << ":" << clock.getSystemTime_tm().tm_min << ":" << clock.getSystemTime_tm().tm_sec << std::endl;  ///%12 to convert to 12H instead of 24H

		timer.setRingtone("./Ringtones/Radar.ogg");
		std::cout << "Press 1 to set an alarm or 2 to set a timer\n";
		std::cin >> choice;
		switch (choice) {
		case 1:
			while (day != -1 || daysToRing.size() != 7) {
				std::cout << "Enter a number (1-7) corresponding to a day of the week and if you're done enter -1\n ";
				std::cin >> day;
				daysToRing.push_back(day);
				clock.setDaysToRing(daysToRing);
				if (day == -1) {
					break;
				}
			}
			std::cout << "Enter hours then minutes then seconds\n";
			std::cin >> hours >> min >> sec;
			clock.setAlarmTime(hours, min, sec);
			break;

		case 2:
			std::cout << "Enter hours then minutes then seconds For Timer\n";
			std::cin >> hours >> min >> sec;
			timer.setTimer(hours, min, sec);
			break;
		}
		//timer.setRingtone();

		//clock.setAlarmTime(22, 20,0);
		//clock.setDaysToRing({ 6 });

		//timer.setTimer(00, 00, 05);
		std::cout << timer.getUserTime_tm().tm_hour << ":" << timer.getUserTime_tm().tm_min << ":" << timer.getUserTime_tm().tm_sec << "\n";
		//clock.activateRingtone();
		ClockStorage.insertQuadratic(clock.hash()%ClockStorage.getCapacity(), clock);
		//timer.activateRingtone();
		 ///While Checing Condition Was Here<----
		sf::Thread clockLogicThread(checkForAlarms, ClockStorage);
		clockLogicThread.launch();
		//checkForAlarms(ClockStorage);

	}


	


