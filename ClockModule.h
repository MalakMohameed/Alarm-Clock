#pragma once

#include <iostream>
#include <chrono>
#include <string>


using namespace std;

 

class ClockModule
{
private:
	
	

public:

	 std::tm getSystemTime_tm();
	 std::chrono::system_clock::time_point getSystemTimePoint();
	
	
};

