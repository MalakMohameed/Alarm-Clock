#include "ActivatableClock.h"

ActivatableClock::ActivatableClock()
{
	userTime_tm.tm_hour = setHours;
	userTime_tm.tm_min = setMinutes;
	userTime_tm.tm_sec = setSeconds;
	
}

void ActivatableClock::setRingtone(std::string ringtonePath)
{
	///Error Hndle

	if (!ringtone.openFromFile(ringtonePath))
	{
		cerr << "Error!!!" << ringtonePath << "\n";
	}
	ringtone.setVolume(50);
	ringtone.setLoop(true);
	std::cout << "Ringtone Loaded Succesfully!\n";
}

void ActivatableClock::activateRingtone()
{
	
	std::cout << "---->Playing\n";
	ringtone.play();
	ringtoneActive = true;
}

void ActivatableClock::stopRingtone()
{
	
	ringtone.stop();
	ringtoneActive = false;
}

void ActivatableClock::setAlarmTime(short HH, short MM, short SS)
{
	userTime_tm.tm_hour = HH;
	userTime_tm.tm_min = MM;
	userTime_tm.tm_sec = SS;
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



