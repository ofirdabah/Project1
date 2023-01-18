#define _CRT_SECURE_NO_WARNINGS
#ifndef STATUSVIDEO_H
#define STATUSVIDEO_H
#include "Status.h"

class StatusVideo :public Status {

private:
	string fileName;

public:

	StatusVideo(string content, string fileName) :Status(content), fileName(fileName) {}
	StatusVideo(string content, string fTime, string fileName) :Status(content, fTime), fileName(fileName) {}

	virtual void printStatus() override;
	virtual ~StatusVideo() override {}
	inline const string getfileName() const { return fileName; }
	string  earsemp4() { return fileName.erase(fileName.length() - 4); }

};

#endif