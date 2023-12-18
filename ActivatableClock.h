#pragma once

#include <SFML/Audio.hpp>
#include <nlohmann/json.hpp>

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
	bool isAlarmActive = false;
	

	
	

public:
	ActivatableClock();
	ActivatableClock(const ActivatableClock &copyClock);
	ActivatableClock(string Label, int hours, int min, int sec);
	void setRingtone(std::string ringtonePath);
	void activateRingtone();
	void stopRingtone();
	void setAlarmTime(short HH, short MM, short SS = 0);
	std::chrono::system_clock::time_point getUserTimePoint();
	std::tm getUserTime_tm();
	
	bool isTimeToRing();
	long hash();

	
	void SetStopAlarmActive();
	bool ringtoneActive;

	bool getringtoneActive();
	void setringtoneActive(bool flagValue);



	void to_json(nlohmann::json& jsonObj, const ActivatableClock& clock);
	void from_json(const nlohmann::json& jsonObj,  ActivatableClock& clock);
	static nlohmann::json to_json(const ActivatableClock& clock);

	


	

};

