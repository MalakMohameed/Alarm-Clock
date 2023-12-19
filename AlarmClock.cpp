#include "AlarmClock.h"

void AlarmClock::setDaysToRing(int arr[])
{
	daysToRing = arr;
	for(short i = 0; i < 7; i ++)
	std::cout << "Days To Ring: " << daysToRing[i] << '\n';
}

int*  AlarmClock::getDaysToRing()
{
	return daysToRing;
}

bool AlarmClock::isTodayOnList()
{

	for (short i = 0; i < 7; i++ )
	{
		
		if (daysToRing[i] == this->getSystemTime_tm().tm_wday) return true;
	}
	return false;
}
bool AlarmClock::isTimeToRing()
{
		if (isTodayOnList() && getUserTime_tm().tm_hour == getSystemTime_tm().tm_hour && getUserTime_tm().tm_min == getSystemTime_tm().tm_min && isTodayOnList())
		{
			//if (!ringtoneActive) activateRingtone();
			return true;


		}
		else if (getUserTime_tm().tm_hour <= getSystemTime_tm().tm_hour && getUserTime_tm().tm_min <= getSystemTime_tm().tm_min)
		{

			//if (ringtoneActive) stopRingtone();
			return false;

		}
		return false;

}


void AlarmClock::to_json(nlohmann::json& jsonObj, const AlarmClock& clock)
{
	jsonObj = nlohmann::json{ {"clocklabel", ClockLabel}, {"isAlarmActive", isAlarmActive}, {"ringHH",userTime_tm.tm_hour}, {"ringMM", userTime_tm.tm_min} }; /////Add ringtone 
}

void AlarmClock::from_json(const nlohmann::json& jsonObj, AlarmClock& clock)
{
	jsonObj.at("clocklabel").get_to(clock.ClockLabel);
	jsonObj.at("isAlarmActive").get_to(clock.isAlarmActive);
	jsonObj.at("ringHH").get_to(clock.userTime_tm.tm_hour);
	jsonObj.at("ringMM").get_to(clock.userTime_tm.tm_min);


}

nlohmann::json AlarmClock::to_json(const AlarmClock& clock)
{
	return nlohmann::json{ {"clocklabel", clock.ClockLabel}, {"isAlarmActive", clock.isAlarmActive}, {"ringHH",clock.userTime_tm.tm_hour}, {"ringMM", clock.userTime_tm.tm_min} }; /////Add ringtone
}

AlarmClock AlarmClock::from_json(const nlohmann::json& jsonObj)
{
	AlarmClock actClock;

	jsonObj.at("clocklabel").get_to(actClock.ClockLabel);
	jsonObj.at("isAlarmActive").get_to(actClock.isAlarmActive);
	jsonObj.at("ringHH").get_to(actClock.userTime_tm.tm_hour);
	jsonObj.at("ringMM").get_to(actClock.userTime_tm.tm_min);
	return actClock;

}

