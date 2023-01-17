#include "StatusPhoto.h"

void StatusPhoto::printStatus()
{
	string str = "start ";
	str += fileName += ".JPG";
	system(str.c_str());
	Status::printStatus();
}







