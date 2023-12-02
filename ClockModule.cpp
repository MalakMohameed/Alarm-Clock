#include "ClockModule.h"

std::tm ClockModule::getSystemTime_tm()
{
	std::time_t systemTime_t = std::chrono::system_clock::to_time_t(this->getSystemTimePoint());
	std::tm systemTime_tm = {};
	localtime_s(&systemTime_tm, &systemTime_t);

	return systemTime_tm;
}

std::chrono::system_clock::time_point ClockModule::getSystemTimePoint()
{
	
	return std::chrono::system_clock::now();
}
