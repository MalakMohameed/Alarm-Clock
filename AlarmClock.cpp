#include "AlarmClock.h"

void AlarmClock::setDaysToRing(std::vector<int> days)
{
	daysToRing = days;
}

std::vector<int> AlarmClock::getDaysToRing()
{
	return daysToRing;
}

bool AlarmClock::isTodayOnList()
{
	for (int day : daysToRing)
	{
		if (day == this->getSystemTime_tm().tm_wday) return true;
	}
	return false;
}
bool AlarmClock::isTimeToRing()
{
		if (isTodayOnList() && getUserTime_tm().tm_hour == getSystemTime_tm().tm_hour && getUserTime_tm().tm_min == getSystemTime_tm().tm_min)
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

