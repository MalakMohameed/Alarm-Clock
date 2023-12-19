#include "HashAlarm.h"



HashAlarm::HashAlarm()
{
	std::cout << "HashMap Creater\n";
}


void HashAlarm::insertQuadratic(long index, AlarmClock &alarm)
{
	if (table[index].status == -1 || table[index].status == -2)
	{
		table[index].clock = alarm;
		table[index].status = index;
	}
	else
	{
		short quadSign = 1;
		while (table[index].status != -1 && table[index].status != -2)
		{
			index += (quadSign * quadSign);
			if (table[index].status == -1 && table[index].status == -2) table[index].clock = alarm;
			else
			{
				index -= (quadSign * quadSign);
				if (index < 0)
				{
					index += HASH_TABLE_SIZE;
				}
				if (table[index].status == -1 || table[index].status  == -2) table[index].clock = alarm;
			}
			quadSign++;
		}

	}
	id++;
}

void HashAlarm::removeQuadratic(long index, AlarmClock alarm)
{
	if (table[index].clock.hash() == alarm.hash())
	{
		table[index].status = -2;
		
	}
	else
	{
		short quadSign = 1;
		while (table[index].status != -1 && table[index].status != -2)
		{
			index += (quadSign * quadSign);
			if (table[index].clock.hash() == alarm.hash()) table[index].status = -2;
			else
			{
				index -= (quadSign * quadSign);
				if (index < 0)
				{
					index += HASH_TABLE_SIZE;
				}
				if (table[index].clock.hash() == alarm.hash()) table[index].status = -2;
			}
			quadSign++;
		}

	}
	id--;
}

HashAlarm::Unit& HashAlarm::getElementIterator(int index)
{
	//std::cout << index << "Last index \n";
	return table[index];
}


int HashAlarm::numberOfAlarms()
{
	return id;
}

short HashAlarm::getCapacity()
{
	return HASH_TABLE_SIZE;
}

nlohmann::json HashAlarm::to_json(const Unit objectContainer[])
{
	nlohmann::json jsonObj;
	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		if (objectContainer[i].status != -1 && objectContainer[i].status != -2)
		{
			jsonObj += Unit::to_json(objectContainer[i]);
		}
	}
	return jsonObj;
	
}

void HashAlarm::from_json(const nlohmann::json& jsonObj)
{
	for (const auto& j : jsonObj)
	{
		Unit insUnit = Unit::from_json(j);
		HashAlarm::insertQuadratic(insUnit.clock.hash() % HASH_TABLE_SIZE, insUnit.clock);
	}
}





HashAlarm::Unit::Unit()
{	
}

void HashAlarm::Unit::to_json(nlohmann::json& jsonObj, const Unit& unit)
{
	ActivatableClock unitClock = unit.clock;
	nlohmann::json unitClockJSON = ActivatableClock::to_json(unitClock);
	
	jsonObj = nlohmann::json{ {"status", unit.status}, {"Clock", unitClockJSON}};
}

void HashAlarm::Unit::from_json(const nlohmann::json& jsonObj, Unit& unit)
{
	jsonObj.at("status").get_to(unit.status);
	unit.clock = AlarmClock::from_json(jsonObj);

}

nlohmann::json HashAlarm::Unit::to_json(const Unit& unit)
{

	AlarmClock unitClock = unit.clock;
	nlohmann::json unitClockJSON = AlarmClock::to_json(unitClock);

	return  nlohmann::json{ {"status", unit.status}, {"Clock", unitClockJSON} };
}

HashAlarm::Unit HashAlarm::Unit::from_json(const nlohmann::json& jsonObj)
{
	Unit retUnit;
	jsonObj.at("status").get_to(retUnit.status);
	retUnit.clock = AlarmClock::from_json(jsonObj);
	return retUnit;
}


 