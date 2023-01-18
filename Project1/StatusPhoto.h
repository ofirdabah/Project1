#define _CRT_SECURE_NO_WARNINGS
#ifndef STATUSPHOTO_H
#define STATUSPHOTO_H
#include "Status.h"

class StatusPhoto: public Status
{
private:
	string fileName;

public:

	StatusPhoto(string content, string fileName) :Status(content), fileName(fileName) {}
	StatusPhoto(string content,string fTime ,string fileName) :Status(content,fTime), fileName(fileName) {}
	virtual void printStatus() override;
	virtual ~StatusPhoto() override{}
	inline const string getfileName() const { return fileName; }


	//virtual bool operator==(const StatusPhoto& other) const override;
	//virtual bool operator!=(const StatusPhoto& other) const override;


};



#endif