#pragma once
#include <iostream>
#include <vector>
class Ship
{
public:
	  int dlugosc=0;
	  bool isHorizontal = true;
	  int howMuchLive=0;
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
	  Ship(const Ship &x)
	  {
		  dlugosc = x.dlugosc;
		  isHorizontal = x.isHorizontal;
		  howMuchLive = x.howMuchLive;
		  start = x.start;
		  end = x.end;
	  }
	  bool SetPosition(std::pair<int, int> _start, std::pair<int, int> _end);
	  

	  

};

