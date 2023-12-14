#include "TimerClock.h"

//TimerClock::TimerClock()
//{
//	setRingtone("./Ringtones/Radar.ogg");
//	ringtone.setLoop(true);
//	ringtone.setVolume(50);
//}

void TimerClock::setTimer(int HH, int MM, int SS) 
{
	userTime_tm.tm_hour = this->getSystemTime_tm().tm_hour + HH;
	if(this->getSystemTime_tm().tm_min + MM<60)userTime_tm.tm_min = this->getSystemTime_tm().tm_min + MM;
	else {
		HH++;
		int MMrem;
		MMrem = this->getSystemTime_tm().tm_min + MM;
		MM = MMrem-60;
		userTime_tm.tm_hour = this->getSystemTime_tm().tm_hour + HH;
		userTime_tm.tm_min = MM;
		std::cout <<"New Time After Mod  " << HH << ":" << MM << ":" << SS << "\n";
		//setTimer(HH, MM, SS);
	}
	
	if(this->getSystemTime_tm().tm_sec + SS<60)userTime_tm.tm_sec = this->getSystemTime_tm().tm_sec + SS;
	else {
		MM++;
		int SSrem;
		SSrem = this->getSystemTime_tm().tm_sec + SS;
		SS = SSrem-60;
		userTime_tm.tm_min = this->getSystemTime_tm().tm_min + MM;
		userTime_tm.tm_sec = SS;
		std::cout << "New Time After Mod  " << HH << ":" << MM << ":" << SS << "\n";
		//setTimer(HH, MM, SS);
	}
}
bool TimerClock::isTimeToRing() 
{

	if (getUserTime_tm().tm_hour == getSystemTime_tm().tm_hour && getUserTime_tm().tm_min == getSystemTime_tm().tm_min && getUserTime_tm().tm_sec >= getSystemTime_tm().tm_sec && isAlarmActive)
	{
		//if (!ringtoneActive) activateRingtone();
		//std::cout << "isTimeToRing() returns true\n";
		return true;


	}
	else if (getUserTime_tm().tm_hour <= getSystemTime_tm().tm_hour && getUserTime_tm().tm_min <= getSystemTime_tm().tm_min && getUserTime_tm().tm_sec >= getSystemTime_tm().tm_sec || !isAlarmActive)
	{

		//if (ringtoneActive) stopRingtone();
		//std::cout << "isTimeToRing() returns false\n";
		return false;

	}
	return false;


}