#include "ActivatableClock.h"


long ActivatableClock::ClockLabelAsLong()
{
	return 1;
	for (char c : ClockLabel)
	{
		
	}
}

void ActivatableClock:: SetStopAlarmActive()
{
	if (this->isAlarmActive) isAlarmActive = false;
	else
		isAlarmActive = true;
}

ActivatableClock::ActivatableClock()
{
	userTime_tm.tm_hour = setHours;
	userTime_tm.tm_min = setMinutes;
	userTime_tm.tm_sec = setSeconds;
	
	
}

ActivatableClock::ActivatableClock(ActivatableClock& copyClock)
{
	this->setHours = copyClock.setHours;
	this->setMinutes = copyClock.setMinutes;
	this->setSeconds = copyClock.setSeconds;
	//this->ClockLabel = copyClock.ClockLabel;
	this->userTime_tm = copyClock.userTime_tm;
	this->ringtoneBuffer = copyClock.ringtoneBuffer;
	this->ringtone = copyClock.ringtone;
	this->ringtoneActive = copyClock.ringtoneActive;
}

void ActivatableClock::setRingtone(std::string ringtonePath)
{
	///Error Hndle
	std::cout << ringtonePath << '\n';
	if (!ringtoneBuffer.loadFromFile(ringtonePath))
	{
		cerr << "Error!!!" << ringtonePath << "\n";
	}
	ringtone.setBuffer(ringtoneBuffer);
	ringtone.setVolume(50);
	ringtone.setLoop(true);
	std::cout << "Ringtone Loaded Succesfully!\n";
}

void ActivatableClock::activateRingtone()
{
	if (!ringtoneActive) {
		ringtone.play();
		std::cout << "---->Playing\n";
		ringtoneActive = true;
	}
}

void ActivatableClock::stopRingtone()
{
	
	ringtone.stop();
	ringtoneActive = false;
}

void ActivatableClock::setAlarmTime(short HH, short MM, short SS)
{
	userTime_tm.tm_hour = HH;
	userTime_tm.tm_min =  MM;
	userTime_tm.tm_sec =  SS;
	
}

std::chrono::system_clock::time_point ActivatableClock::getUserTimePoint()
{
	std::chrono::system_clock::time_point user_time_point = std::chrono::system_clock::from_time_t(std::mktime(&userTime_tm));
	return user_time_point;
}

std::tm ActivatableClock::getUserTime_tm()
{
	
	return userTime_tm;
}

bool ActivatableClock::isTimeToRing() ////OverLoad Function to ignore seconds 
{
	
	if (getUserTime_tm().tm_hour == getSystemTime_tm().tm_hour && getUserTime_tm().tm_min == getSystemTime_tm().tm_min /*&& getUserTime_tm().tm_sec >= getSystemTime_tm().tm_sec*/)
	{
		//if (!ringtoneActive) activateRingtone();
		//std::cout << "isTimeToRing() returns true\n";
		return true;

		
	}
	else if (getUserTime_tm().tm_hour <= getSystemTime_tm().tm_hour && getUserTime_tm().tm_min <= getSystemTime_tm().tm_min)
	{
		
		//if (ringtoneActive) stopRingtone();
		//std::cout << "isTimeToRing() returns false\n";
		return false;

	}
	return false;


}

long ActivatableClock::hash()
{
	return (long)ringtone.getPitch() * (long)userTime_tm.tm_hour + (long)userTime_tm.tm_min /** stoll(ClockLabel)*/;
}

bool ActivatableClock::getringtoneActive()
{
	//std::cout << "getRingtoneActive() Called!\nringtoneActive Value: " << ringtoneActive << '\n';
	return this->ringtoneActive;
}

void ActivatableClock::setringtoneActive(bool flagValue)
{
	std::cout << "setRingtoneActive() Called!\nFlag Value: " <<flagValue << '\n';
	this->ringtoneActive = flagValue;
	std::cout << "RingtoneActive Value: " << ringtoneActive << '\n';
}

void ActivatableClock::fromJSON(nlohmann::json& jsonObj)
{
	jsonObj = nlohmann::json{ {"AlarmHH", userTime_tm.tm_hour}, {"AlarmMM", userTime_tm.tm_min}, {"AlarmSS", userTime_tm.tm_sec}, {"ClockLabel", ClockLabel} } //// Still Doesn't Contain Sound!!
}

void ActivatableClock::toJSON(nlohmann::json& jsonObj)
{
}



