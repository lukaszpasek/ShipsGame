#include "Board.h"

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

bool Board::SetShip(std::pair<int, int> start,std::pair<int,int> end)
{
	int i = 0, j = 0;

	bool isHorizontal = true;
	if (start.first != end.first && end.second != start.second)
	{
		std::cout << "Statek ulozony po skosie!";
		return false;
	}
	else if (start.second == end.second)
	{
		isHorizontal = false;
	}

	while (i < start.first)i++;
	while (j < start.second)j++;

	char shipType = 'd';
	
	if (isHorizontal)
	{
		shipType = std::abs(start.second - end.second+1)+'0';
		//F[i][j].state = shipType;
		while (j > end.second)
		{
			if (F[i][j].IsFree())
			{
				F[i][j].state = shipType;
			}
			else
			{
				std::cout << "Tutaj stoi już inny statek!\n";
				while (j <= start.second)
				{
					F[i][j].state = '*';
					j++;
				}
				return false;
			}
			j--;
		}
		while (j < end.second)
		{
			if (F[i][j].IsFree())
			{
				F[i][j].state = shipType;
			}
			else
			{
				std::cout << "Tutaj stoi już inny statek!\n";
				while (j >= start.second)
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
			shipType = std::abs(start.first - end.first+1) + '0';
			//F[i][j].state = shipType;
			while (i > end.first)
			{
				if (F[i][j].IsFree())
				{
					F[i][j].state = shipType;
				}
				else
				{
					std::cout << "Tutaj stoi już inny statek!\n";
					while (i <= start.first)
					{
						F[i][j].state = '*';
						i++;
					}
					return false;
				}
				i--;
			}
			while (i < end.first)
			{
				if (F[i][j].IsFree())
				{
					F[i][j].state = shipType;
				}
				else
				{
					std::cout << "Tutaj stoi już inny statek!\n";
					while (i >= start.first)
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