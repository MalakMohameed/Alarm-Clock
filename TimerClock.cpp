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
		MM = 0;
		userTime_tm.tm_hour = this->getSystemTime_tm().tm_hour + HH;
		std::cout <<"New Time After Mod  " << HH << ":" << MM << ":" << SS << "\n";
		//setTimer(HH, MM, SS);
	}
	
	if(this->getSystemTime_tm().tm_sec + SS<60)userTime_tm.tm_sec = this->getSystemTime_tm().tm_sec + SS;
	else {
		MM++;
		SS = 0;
		userTime_tm.tm_min = this->getSystemTime_tm().tm_min + MM;
		userTime_tm.tm_sec = 0;
		std::cout << "New Time After Mod  " << HH << ":" << MM << ":" << SS << "\n";
		//setTimer(HH, MM, SS);
	}
}
