#pragma once

#include <SFML/Audio.hpp>

#include "ClockModule.h"

class ActivatableClock :public ClockModule
{
private: 
	short setHours, setMinutes, setSeconds;
	std::string ClockLabel = "";
	std::tm userTime_tm = {};
	sf::Music ringtone;
	
	

public:
	ActivatableClock();
	void setRingtone(std::string ringtonePath);
	void activateRingtone();
	void stopRingtone();
	void setAlarmTime(short HH, short MM, short SS = 0);
	std::chrono::system_clock::time_point getUserTimePoint();
	std::tm getUserTime_tm();
	bool ringtoneActive = false; 

};

