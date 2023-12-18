#pragma once


#include "ActivatableClock.h"
#include "ClockModule.h"
#include <atomic>

const short HASH_TABLE_SIZE = 41;

class HashAlarm {

private:
	
	class Unit{
	private: 
	bool isPlaying= false ;
	public:	
		
		short status = -1;
		ActivatableClock clock;
		
		void setisPlaying(bool setValue) {
			isPlaying=setValue;
		}
		bool getIsPlaying()
		{
			return isPlaying;
		}
		Unit();
		Unit(int k , ActivatableClock& loadedClock)
		{
		//	HashAlarm::id = 0;
			status = k;
			clock = loadedClock;
		}
		
		void to_json(nlohmann::json& jsonObj, const Unit& unit);
		void from_json(const nlohmann::json& jsonObj, Unit& unit);

		
	};

	 
	Unit table[HASH_TABLE_SIZE];
	

public:

	int id;

	HashAlarm();
	void insertQuadratic(long index, ActivatableClock &alarm);
	void removeQuadratic(long index, ActivatableClock alarm);
	Unit& getElementIterator(int index);
	int numberOfAlarms();
	short getCapacity();
	
	

};