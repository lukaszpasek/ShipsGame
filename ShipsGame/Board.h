#pragma once
#include "Field.h"
#include "Ship.h"
#include <vector>
#include <iostream>
class Board
{
	static const int rozmiarPlanszy = 30;
	std::vector<std::vector<Field> > F;
	std::vector<std::vector<Field> > S;
	public:
	char Id;
	Board()
	{
		F.resize(rozmiarPlanszy);
		for (int i = 0; i < rozmiarPlanszy; i++) F[i].resize(rozmiarPlanszy);
		S.resize(rozmiarPlanszy);
		for (int i = 0; i < rozmiarPlanszy; i++) S[i].resize(rozmiarPlanszy);
	}
	void Print();
	void PrintOpponent();
	bool SetShip(Ship &x);
	bool SetShipsAutomatically(std::vector<std::vector<Ship>> &ships);
	bool Shot();
};

