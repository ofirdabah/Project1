#include "StatusVideo.h"

void StatusVideo::printStatus()
{
	string str = "start ";
	str += fileName += ".MP4";
	system(str.c_str());
	Status::printStatus();
}