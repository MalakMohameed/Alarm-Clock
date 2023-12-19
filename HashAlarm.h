#pragma once


#include "ActivatableClock.h"
#include "AlarmClock.h"
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
		AlarmClock clock;
		
		void setisPlaying(bool setValue) {
			isPlaying=setValue;
		}
		bool getIsPlaying()
		{
			return isPlaying;
		}
		Unit();
		Unit(int k , AlarmClock& loadedClock)
		{
		//	HashAlarm::id = 0;
			status = k;
			clock = loadedClock;
		}
		
		void to_json(nlohmann::json& jsonObj, const Unit& unit);
		void from_json(const nlohmann::json& jsonObj, Unit& unit);
		static nlohmann::json to_json(const Unit& unit);
		static Unit from_json(const nlohmann::json& jsonObj);

		
	};

	 
	
	

public:

	int id;
	Unit table[HASH_TABLE_SIZE];

	HashAlarm();
	void insertQuadratic(long index, AlarmClock &alarm);
	void removeQuadratic(long index, AlarmClock alarm);
	Unit& getElementIterator(int index);
	int numberOfAlarms();
	short getCapacity();
	
	nlohmann::json to_json(const Unit objectContainer[]);
	void from_json(const nlohmann::json& jsonObj);

};