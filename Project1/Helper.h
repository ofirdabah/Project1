#ifndef HELPER_H
#define HELPER_H
#include "Facebook.h"

class Helperxception : public exception
{
private:
	string message;

public:
	Helperxception(const string& message) : message(message) {}

	virtual const char* what() const throw()
	{
		return message.c_str();
	}
};


class Helper
{
private:

	enum class USER_OPTION {
		ADD_USER = 1, ADD_FANPAGE = 2,
		ADD_STATUS = 3, SHOW_ALL_STATUS = 4,
		SHOW_10_RECENT_STATUS = 5, CREATE_FRIENDSHIP = 6,
		CANCLE_FRIENDSHIP = 7, ADD_FUN = 8, REMOVE_FUN = 9,
		SHOW_ALL_USERS = 10, SHOW_ALL_FOLLOWERS = 11, EXIT = 12
	};

	void print_main_page();
	void manage(int num, Facebook& meta);
public:

	Helper(const Helper& other) = delete;
	Helper() {}

	void console(Facebook& meta);

	inline void cleanBuffer()
	{
		int x;
		do {
			x = getchar();
		} while (x != EOF && x != '\n');
	}

	bool checkIfOneOrZero(int num)
	{
		if (num != 1 && num != 2)
			return false;

		return true;
	}
};

#endif 
