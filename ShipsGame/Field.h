#pragma once
class Field
{
	public: char state;
	Field()
	{
		state = '*';
	}
	bool IsFree();
	
};

