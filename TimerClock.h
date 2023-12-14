#pragma once
#include "ActivatableClock.h"

class TimerClock : public ActivatableClock
{
private:

	

public:
	//TimerClock();
	void setTimer(int HH, int MM, int SS);
	
	bool isTimeToRing();

};

