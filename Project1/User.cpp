#include "User.h"
#include <string>
#include "Status.h"
#include "Fans_page.h"

User::User(const string s, Date& date) : name(s), birthdate(date){}

void User::add_status(Status* s)
{
	Status_arry.push_back(s);
}

User::~User() {
	for (auto i = Status_arry.begin(); i != Status_arry.end(); ++i)
		delete* i;
}

void User::print_all_status()
{
	cout << "All the status of: " << name << endl;
	for (auto it = Status_arry.begin(); it != Status_arry.end(); ++it)
		(*it)->printStatus();
}

void User::show_friends_status()
{
	for (auto i = friends_arr.begin(); i != friends_arr.end(); ++i) {
			cout<<"\n"<<(*i)->getName() << "'s status:\n";
		for (auto j = (*i)->Status_arry.begin(); j != (*i)->Status_arry.end(); ++j)
			(*j)->printStatus();
	}
}

void User::create_friendship(User* newfriend)
{
	bool flag = false;
	for (auto it = friends_arr.begin(); it != friends_arr.end(); ++it)
	{
		if ((*it)->name == newfriend->getName())
		{
			cout << "You are already friends!" << endl;
			flag = true;
		}
	}
	if (!flag)
		friends_arr.push_back(newfriend);
}

void User::print_all_of_my_folowers()
{
	for (auto it = friends_arr.begin(); it != friends_arr.end(); ++it)
		cout<<(*it)->getName();
}

void User::cancel_friendship(string friend_not_for_long)
{
	int delete_index = 0;
	for (auto it = friends_arr.begin() ; it != friends_arr.end(); ++it)
	{
		if (name == friend_not_for_long)
			friends_arr.erase(it);
	}
}

void User::add_fan_page(Fans_page* newpage)
{
	fan_pages_arr.push_back(newpage);
}

void User::remove_fan_page(Fans_page* page)
{
	for (auto it = fan_pages_arr.begin(); it != fan_pages_arr.end(); it++)
	{
		if ((*it)->get_page_name() == page->get_page_name())
			fan_pages_arr.erase(it);
	}
}

void User::show_fanpage_followed_by_user()
{
	cout << "All fan pages followed by " << getName();
	for (auto it = fan_pages_arr.begin(); it != fan_pages_arr.end(); ++it)
	cout << ":\n " << (*it)->get_page_name();
}

User& User::operator+=(User& other) {

	this->create_friendship(&other);
	return (*this);
}

User& User::operator+=(Fans_page& other)
{
	this->add_fan_page(&other);
	return (*this);
}

bool  User::operator>(const User& other) const
{
	return(friends_arr.size() > other.friends_arr.size());
}

bool  User::operator>(const Fans_page& other) const
{
	return(friends_arr.size() > other.getStatus_of_page().size());
}

