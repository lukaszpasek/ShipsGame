#include "Ship.h"

bool Ship::SetPosition(std::pair<int, int> _start, std::pair<int, int> _end)
{
	isHorizontal = true;
	if (_start.first != _end.first && _end.second != _start.second)
	{
		std::cout << "Statek ulozony po skosie!";
		return false;
	}
	else if (_start.second == _end.second)
	{
		isHorizontal = false;
	}
	start = _start;
	end = _end;
	return true;
}