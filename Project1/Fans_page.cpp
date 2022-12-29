#include"Fans_page.h"
#include "User.h"


Fans_page::Fans_page(string name) : page_name(name) {
	name = name;
	if (name == "")
		throw Emptynamexception();
}


void Fans_page::add_status(Status* s) {status_of_page.push_back(s);}

void Fans_page::print_all_status()
{
	for (auto it = status_of_page.begin(); it != status_of_page.end(); ++it)
		(*it)->printStatus();
}

void Fans_page::print_all_my_folowers()
{
	for (auto it = fans_arr.begin(); it != fans_arr.end(); ++it)
		cout<<(*it)->getName()<<"\n";
}

void Fans_page::add_fan(User* newfan)
{
	for (auto it = fans_arr.begin(); it != fans_arr.end(); ++it)
	{
		if ((*it)->getName() == newfan->getName())
			throw UserAlreadyfollowexception();
	}
	fans_arr.push_back(newfan);
	
}

Fans_page::~Fans_page() {
	for (auto i = status_of_page.begin(); i != status_of_page.end(); ++i)
		delete* i;
}

void Fans_page::remove_fan(string fan_name)
{
	bool flag = false;
	for (auto it = fans_arr.begin(); it != fans_arr.end(); ++it)
	{
		if ((*it)->getName() == fan_name)
		{
			flag = true;
			fans_arr.erase(it);
			break;
		}
	}
	if (!flag)
		throw UserNoExistexception();
}

Fans_page& Fans_page::operator+=(User& other) {
	this->add_fan(&other);
		return (*this);
}

bool  Fans_page::operator>(const Fans_page& other) const
{
	return(status_of_page.size() > other.status_of_page.size());
}

bool  Fans_page::operator>(const User& other) const
{
	return(status_of_page.size() > other.get_fan_pages_arr().size());
}