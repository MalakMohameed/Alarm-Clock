#pragma once
#include "ActivatableClock.h"

#include <vector>

class AlarmClock : public ActivatableClock
{
private:

	std::vector<int> daysToRing;
	

public:


	void setDaysToRing(std::vector<int> days);
	std::vector<int> getDaysToRing();
	bool isTodayOnList();
	bool isTimeToRing();

};

