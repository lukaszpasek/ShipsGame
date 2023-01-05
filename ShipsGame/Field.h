#pragma once
#include "Ship.h"
class Field
{
	public: 
	char state;
	Ship* shipStayed;
	Field()
	{
		state = '*';
	}
	bool IsFree();
	
};

