#pragma once


#include "ActivatableClock.h";

const short HASH_TABLE_SIZE = 41;

class HashAlarm {

private:
	
	class Unit{
	public:	
		
		short status = -1;
		ActivatableClock clock;
		Unit();
		Unit(int k , ActivatableClock& loadedClock)
		{
		//	HashAlarm::id = 0;
			status = k;
			clock = loadedClock;
		}
		
	};

	 
	Unit table[HASH_TABLE_SIZE];


public:
	 int id;

	HashAlarm();
	void insertQuadratic(long index, ActivatableClock alarm);
	void removeQuadratic(long index, ActivatableClock alarm);

	int numberOfAlarms();
	

};