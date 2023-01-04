#pragma once
#include "Field.h"
#include "Ship.h"
#include <vector>
#include <iostream>
class Board
{
	std::vector<std::vector<Field> > F;
	public:
	Board()
	{
		F.resize(30);
		for (int i = 0; i < 30; i++) F[i].resize(30);
	}
	void Print();
	bool SetShip(Ship x);
	
};

