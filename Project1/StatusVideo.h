#define _CRT_SECURE_NO_WARNINGS
#ifndef STATUSVIDEO_H
#define STATUSVIDEO_H
#include "Status.h"

class StatusVideo :public Status {

private:
	string fileName;

public:

	StatusVideo(string content, string fileName) :Status(content), fileName(fileName) {}
	virtual void printStatus() override;
	virtual ~StatusVideo() override {}

};

#endif