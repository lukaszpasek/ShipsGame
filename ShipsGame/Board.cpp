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
	std::cout << "KONIEC PLANSZY------------------------------------------->\n";
}

void Board::PrintOpponent()
{
	std::cout << "Ruch gracza:" << this->Id<<"\n";
	//std::cout << "   ";
	/*for (int i = 0; i < S.size(); i++)
	{
		std::cout << i;
	}
	std::cout << "\n";*/
	for (int i = 0; i < S.size(); i++)
	{
		//std::cout << i << ": ";
		for (int j = 0; j < S.size(); j++)
		{
			std::cout << S[i][j].state;
		}
		std::cout << "\n";
	}
	//std::cout << "KONIEC PLANSZY------------------------------------------->\n";
}

bool Board::SetShip(Ship &y)
{
	setlocale(LC_ALL, "pl_PL");
	int i = 0, j = 0;
	Ship* x = new Ship(y);
	while (x->start.first == -1 || x->start.second == -1)
	{
		std::cout << "Podaj wspolrzedne poczatku " << x->dlugosc << " masztowego statku(x, y):\n";
		std::cin >> x->start.first >> x->start.second;
		std::cout << "Czy ustawic poziomo?(1->TAK,0->NIE)\n";
		std::cin >> x->isHorizontal;
		if (x->isHorizontal && x->start.first + x->dlugosc >= F.size())
		{
			x->start.first = -1;
			std::cout << "Proba postawienia statku poza plansza!\n";
			continue;
		}
		else if(!x->isHorizontal && x->start.second + x->dlugosc >= F.size())
		{
			x->start.second = -1;
			std::cout << "Proba postawienia statku poza plansza!\n";
			continue;
		}
	}

	while (i < x->start.first)i++;
	while (j < x->start.second)j++;

	char shipType = x->dlugosc+'0';
	
	if (x->isHorizontal)
	{
		x->end.second = x->start.second + x->dlugosc-1;

		while (j <= x->end.second)
		{
			if (j >= F.size())
			{
				std::cout << "Tutaj konczy sie plansza!\n";
				while (--j >= x->start.second)
				{
					F[i][j].state = '*';
					F[i][j].shipStayed = new Ship();
					//j--;
				}
				return false;
			}
			if (F[i][j].IsFree())
			{
				F[i][j].state = shipType;
				F[i][j].shipStayed = x;
			}
			else
			{
				std::cout << "Tutaj stoi juz inny statek!\n";
				while (--j >= x->start.second)
				{
					F[i][j].state = '*';
					F[i][j].shipStayed = new Ship();
					//j--;
				}
				return false;
			}
			j++;
		}
	//F[i][j].state = shipType;
	}
	else 
		{
			x->end.first = x->start.first + x->dlugosc-1;

			while (i <= x->end.first)
			{
				if (i >= F.size())
				{
					std::cout << "Tutaj konczy sie plansza!\n";
					while (--i >= x->start.first)
					{
						F[i][j].state = '*';
						F[i][j].shipStayed = new Ship();
						//i--;
					}
					return false;
				}
				if (F[i][j].IsFree())
				{
					F[i][j].state = shipType;
					F[i][j].shipStayed = x;
				}
				else
				{
					std::cout << "Tutaj stoi juz inny statek!\n";
					while (--i >= x->start.first)
					{
						F[i][j].state = '*';
						F[i][j].shipStayed = new Ship();
						//i--;
					}
					return false;
				}
				i++;
			}
		//F[i][j].state = shipType;
		}
	return true;
}

bool Board::SetShipsAutomatically(std::vector<std::vector<Ship>> &ships)
{
	for (int j = 2; j <= 5; j++)
	{
		for (int i = 0; i < ships[j].size(); i++)
		{
			ships[j][i].start.first = rand() % rozmiarPlanszy;
			ships[j][i].start.second = rand() % rozmiarPlanszy;
			ships[j][i].isHorizontal = rand() % 2;
			while (!this->SetShip(ships[j][i]))
			{
				ships[j][i].start.first = rand() % rozmiarPlanszy;
				ships[j][i].start.second = rand() % rozmiarPlanszy;
				ships[j][i].isHorizontal = rand() % 2;
			}
		}
	}
	return true;
}

bool Board::Shot()
{
	PrintOpponent();
	std::pair<int, int> point ={-1,-1};
	while (point.first == -1 || point.second == -1)
	{
		std::cout << "Podaj wspolrzedne punktu w ktory chcesz uderzyc:\n";
		std::cin >> point.first >> point.second;
		if (point.first >= F.size() || point.second>=F.size())
		{
			point.first = -1;
			point.second = -1;
			std::cout << "Proba postawienia statku poza plansza!\n";
			continue;
		}
	}
	if (F[point.first][point.second].state == '*')
	{
		std::cout << "Pudlo!\n";
		S[point.first][point.second].state = 'o';
		return false;
	}
	else
	{
		S[point.first][point.second].state = 'X';
		F[point.first][point.second].shipStayed->howMuchLive--;
		if (F[point.first][point.second].shipStayed->howMuchLive==0)
		{
			std::cout << "Trafiony zatopiony!\n";
		}
		else std::cout << "Trafiony!\n";

		return true;
	}
}

bool Board::ShotAutomatically()
{
	PrintOpponent();
	std::pair<int, int> point = { -1,-1 };
	if (nextShipIsNeighbour)
	{
		if (lastShot.top().first < rozmiarPlanszy-1 && F[lastShot.top().first + 1][lastShot.top().second].state != 'o' && F[lastShot.top().first + 1][lastShot.top().second].state != 'X') {point = lastShot.top();point.first++; }
		else if (lastShot.top().first>0 && F[lastShot.top().first -1][lastShot.top().second].state != 'o' && F[lastShot.top().first - 1][lastShot.top().second].state != 'X') {point = lastShot.top();point.first--; }
		else if (lastShot.top().second < rozmiarPlanszy-1 && F[lastShot.top().first][lastShot.top().second+1].state != 'o' && F[lastShot.top().first][lastShot.top().second+1].state != 'X') {point = lastShot.top();point.second++; }
		else if (lastShot.top().second>0 && F[lastShot.top().first][lastShot.top().second-1].state != 'o' && F[lastShot.top().first][lastShot.top().second-1].state != 'X') {point = lastShot.top();point.second--; }
		else
		{
			lastShot.pop();
			if (lastShot.empty()) nextShipIsNeighbour = false;
			point.first = rand() % rozmiarPlanszy;
			point.second = rand() % rozmiarPlanszy;
		}
	}
	else 
	{
		point.first = rand() % rozmiarPlanszy;
		point.second = rand() % rozmiarPlanszy;
	}
	while (F[point.first][point.second].state == 'o' || F[point.first][point.second].state == 'X')
	{
		point.first = rand() % rozmiarPlanszy;
		point.second = rand() % rozmiarPlanszy;
	}

	if (F[point.first][point.second].state == '*')
	{
		
		std::cout << "Pudlo!\n";
		S[point.first][point.second].state = 'o';
		F[point.first][point.second].state = 'o';
		//nextShipIsNeighbour = false;
		return false;
	}
	else
	{
		lastShot.push(point);
		S[point.first][point.second].state = 'X';
		F[point.first][point.second].state = 'X';
		F[point.first][point.second].shipStayed->howMuchLive--;
		std::cout << F[point.first][point.second].shipStayed->howMuchLive <<"\n";
		if (F[point.first][point.second].shipStayed->howMuchLive == 0)
		{
			std::cout << "Trafiony zatopiony!\n";
			nextShipIsNeighbour = false;
			this->SinkedShips++;
		}
		else std::cout << "Trafiony!\n";
		nextShipIsNeighbour = true;
		return true;
	}
}