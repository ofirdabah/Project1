#ifndef USER_H
#define USER_H
#include "Status.h"
#include "Date.h"
#include <iostream>
#include <vector>

class Fans_page;


class Userexception : public exception
{
public:
	virtual const char* what() const override { return "Data invalid!\n"; }
};

class UserNamexception : public Userexception
{
public:
	virtual const char* what() const override { return "Empty name is invalid!\n"; }
};
class UserFriendexception : public Userexception
{
public:
	virtual const char* what() const override { return "Already friends!\n"; }
};
class UserNotFriendexception : public Userexception
{
public:
	virtual const char* what() const override { return "You are not friends!\n"; }
};
class UserALreadyFollowexception : public Userexception
{
public:
	virtual const char* what() const override { return "You are already follow this page!\n"; }
};
class UserNotFollowexception : public Userexception
{
public:
	virtual const char* what() const override { return "You are not follow this page!\n"; }
};

class User {
private:

	string name;
	Date birthdate;

	vector<Status*> Status_arry;
	vector<User*> friends_arr;
	vector<Fans_page*> fan_pages_arr;

public:

	User(const User& other) = delete;

	vector<Status*> get_status_arry() { return Status_arry; }
	vector<User*> get_friends_arry() { return friends_arr; };
	const string getName() const { return name; }
	Date getdate() const { return birthdate; }

	vector<Fans_page*> get_fan_pages_arr() const { return fan_pages_arr; }
	void show_friends_status() const;
	void create_friendship(User* newfriend);
	void cancel_friendship(string friend_not_for_long);
	void add_status(Status* s);
	void print_all_status() const;
	void print_all_of_my_folowers() const;
	User(const string s, Date& date);
	~User();
	void add_fan_page(Fans_page* newpage);
	void  remove_fan_page(string page_name);
	void show_fanpage_followed_by_user()const;

	User& operator+=(User& other);
	User& operator+=(Fans_page& other);

	bool operator>(const User& other) const;
	bool operator>(const Fans_page& other) const;
};

#endif 