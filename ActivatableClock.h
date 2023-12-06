#pragma once

#include <SFML/Audio.hpp>

#include "ClockModule.h"

class ActivatableClock :public ClockModule
{
protected: 
	short setHours, setMinutes, setSeconds;
	std::string ClockLabel = "a";
	std::tm userTime_tm = {};
	sf::SoundBuffer ringtoneBuffer;
	sf::Sound ringtone;
	long ClockLabelAsLong();
	
	

public:
	ActivatableClock();
	ActivatableClock(ActivatableClock &copyClock);
	void setRingtone(std::string ringtonePath = "./Ringtones/Radar.ogg");
	void activateRingtone();
	void stopRingtone();
	void setAlarmTime(short HH, short MM, short SS = 0);
	std::chrono::system_clock::time_point getUserTimePoint();
	std::tm getUserTime_tm();
	bool ringtoneActive = false; 
	bool isTimeToRing();

	long hash();

};

