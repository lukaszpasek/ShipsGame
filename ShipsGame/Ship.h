#pragma once
#include <iostream>
#include <vector>
class Ship
{
public:
	  int dlugosc;
	  bool isHorizontal = true;
	  std::pair<int, int> start;
	  std::pair<int, int> end;
	  Ship(int dl)
	  {
		  dlugosc = dl;
	  }
	  bool SetPosition(std::pair<int, int> _start, std::pair<int, int> _end);
	  

	  

};

