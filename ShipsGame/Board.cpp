#include "Board.h"
#include "Ship.h"

void Board::Print()
{
	for (int i = 0; i < F.size(); i++)
	{
		for (int j = 0; j < F.size(); j++)
		{
			std::cout << F[i][j].state;
		}
		std::cout << "\n";
	}
	std::cout << "KONIEC PLANSZY--------------------------------\n";
}

bool Board::SetShip(Ship x)
{
	int i = 0, j = 0;

	

	while (i < x.start.first)i++;
	while (j < x.start.second)j++;

	char shipType = x.dlugosc+'0';
	
	if (x.isHorizontal)
	{
		//F[i][j].state = shipType;
		while (j > x.end.second)
		{
			if (F[i][j].IsFree())
			{
				F[i][j].state = shipType;
			}
			else
			{
				std::cout << "Tutaj stoi już inny statek!\n";
				while (j <= x.start.second)
				{
					F[i][j].state = '*';
					j++;
				}
				return false;
			}
			j--;
		}
		while (j < x.end.second)
		{
			if (F[i][j].IsFree())
			{
				F[i][j].state = shipType;
			}
			else
			{
				std::cout << "Tutaj stoi już inny statek!\n";
				while (j >= x.start.second)
				{
					F[i][j].state = '*';
					j--;
				}
				return false;
			}
			j++;
		}
	F[i][j].state = shipType;
	}
	else 
		{
			//F[i][j].state = shipType;
			while (i > x.end.first)
			{
				if (F[i][j].IsFree())
				{
					F[i][j].state = shipType;
				}
				else
				{
					std::cout << "Tutaj stoi już inny statek!\n";
					while (i <= x.start.first)
					{
						F[i][j].state = '*';
						i++;
					}
					return false;
				}
				i--;
			}
			while (i < x.end.first)
			{
				if (F[i][j].IsFree())
				{
					F[i][j].state = shipType;
				}
				else
				{
					std::cout << "Tutaj stoi już inny statek!\n";
					while (i >= x.start.first)
					{
						F[i][j].state = '*';
						i--;
					}
					return false;
				}
				i++;
			}
		F[i][j].state = shipType;
		}
}