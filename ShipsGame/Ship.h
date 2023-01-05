#pragma once
#include <iostream>
#include <vector>
class Ship
{
public:
	  int dlugosc;
	  bool isHorizontal = true;
	  int howMuchLive;
	  std::pair<int, int> start={-1,-1};
	  std::pair<int, int> end={-1,-1};
	  Ship(int dl)
	  {
		  dlugosc = dl;
		  howMuchLive = dl;
	  }
	  Ship()
	  {
		  ;
	  }
	  bool SetPosition(std::pair<int, int> _start, std::pair<int, int> _end);
	  

	  

};

