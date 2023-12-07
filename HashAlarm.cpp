#include "HashAlarm.h"



HashAlarm::HashAlarm()
{
	std::cout << "HashMap Creater\n";
}

void HashAlarm::insertQuadratic(long index, ActivatableClock alarm)
{
	if (table[index].status == -1 || -2)
	{
		table[index].clock = alarm;
		table[index].status = index;
	}
	else
	{
		short quadSign = 1;
		while (table[index].status != -1 || -2)
		{
			index += (quadSign * quadSign);
			if (table[index].status == -1 || -2) table[index].clock = alarm;
			else
			{
				index -= (quadSign * quadSign);
				if (index < 0)
				{
					index += HASH_TABLE_SIZE;
				}
				if (table[index].status == -1 || -2) table[index].clock = alarm;
			}
			quadSign++;
		}

	}
	id++;
}

void HashAlarm::removeQuadratic(long index, ActivatableClock alarm)
{
	if (table[index].clock.hash() == alarm.hash())
	{
		table[index].status = -2;
		
	}
	else
	{
		short quadSign = 1;
		while (table[index].status != -1 || -2)
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

HashAlarm::Unit HashAlarm::getElementIterator(int index)
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



HashAlarm::Unit::Unit()
{
}
