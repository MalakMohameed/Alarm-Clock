#pragma once
#include "ActivatableClock.h"



class AlarmClock : public ActivatableClock
{
private:

	
	int* daysToRing = new int[7];
	

public:


	int* getDaysToRing();
	void setDaysToRing(int arr[]);
	bool isTodayOnList();
	bool isTimeToRing();


	void to_json(nlohmann::json& jsonObj, const AlarmClock& clock);
	void from_json(const nlohmann::json& jsonObj, AlarmClock& clock);
	static nlohmann::json to_json(const AlarmClock& clock);
	static AlarmClock from_json(const nlohmann::json& jsonObj);
	

};

