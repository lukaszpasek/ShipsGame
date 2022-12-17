#include "Field.h"

bool Field::IsFree()
{
	if (state == '*') return true;
	return false;
}