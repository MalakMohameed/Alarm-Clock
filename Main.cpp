////Hellooo KAKA
#include <iostream>
#include <iomanip>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <thread>


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

void checkForAlarms(HashAlarm &clocks)
{
	while(true) {
		for (int i = 0; i < clocks.getCapacity(); i++)
		{
			
			if (clocks.getElementIterator(i).clock.isTimeToRing() && !clocks.getElementIterator(i).clock.getringtoneActive())
			{
				
				

				clocks.getElementIterator(i).clock.activateRingtone();
			
				clocks.getElementIterator(i).setisPlaying(true);
				
				


			}
			else if(!clocks.getElementIterator(i).clock.isTimeToRing()) {
				clocks.getElementIterator(i).clock.stopRingtone();
				
			}
		}
	}

}

int main()
{
	HashAlarm ClockStorage;

	sf::RenderWindow mainWin(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "AlarmR");
	sf::RectangleShape background;
	sf::Color color; 
	color.r = 9;
	color.g = 38;
	color.b = 53;
	background.setFillColor(color);
	background.setSize(sf::Vector2f(mainWin.getSize().x, mainWin.getSize().y));

	while (mainWin.isOpen())
	{
		sf::Event mainEventHandle;
		while (mainWin.pollEvent(mainEventHandle))
		{
			if (mainEventHandle.type == sf::Event::Closed)
			{
				mainWin.close();
			}
		}


		//update
		mainWin.clear();
		////Draw Functions Go here...
		mainWin.draw(background);
		mainWin.display();

	}









	///////FOLLOWING CODE IS PRE PHASE 1 AND PRE GUI....

	AlarmClock clock;
    TimerClock timer ;
	
	
	std::cout << clock.getSystemTime_tm().tm_hour<< ":" << clock.getSystemTime_tm().tm_min << ":" << clock.getSystemTime_tm().tm_sec << std::endl;  ///%12 to convert to 12H instead of 24H
	
	clock.setRingtone("./Ringtones/goofy1.ogg");
	

	std::cout << timer.getUserTime_tm().tm_hour << ":" << timer.getUserTime_tm().tm_min << ":" << timer.getUserTime_tm().tm_sec << "\n";


	
	
	std::cout << ClockStorage.numberOfAlarms() << '\n';

	
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
		
		std::cout << timer.getUserTime_tm().tm_hour << ":" << timer.getUserTime_tm().tm_min << ":" << timer.getUserTime_tm().tm_sec << "\n";
		
		ClockStorage.insertQuadratic(clock.hash()%ClockStorage.getCapacity(), clock);


		sf::Thread clockLogicThread(checkForAlarms, ClockStorage);

		clockLogicThread.launch();
		
		
	}


	


