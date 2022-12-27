#ifndef FANS_PAGE
#define FANS_PAGE
#include <ctime>
#include "User.h"
#include <iostream>

class User;

class Fans_page
{
	string page_name;
	vector <User*> fans_arr;
	vector<Status*> status_of_page;

public:
	Fans_page(const Fans_page& other) = delete;
	const string get_page_name() const { return page_name; }

	vector <User*> get_fans_arr() { return fans_arr; }
	vector<Status*>  get_status_of_page() { return status_of_page; }

	Fans_page(string name);
	~Fans_page();
	void add_status(Status* s);
	void print_all_status();
	void print_all_my_folowers();
	void add_fan( User* newfan);
	void remove_fan(User* newfan);
	vector<Status*> getStatus_of_page() { return status_of_page; }
    vector<Status*> getStatus_of_page() const  { return status_of_page; }  
	Fans_page& operator+=(User& other);
	bool operator>(const Fans_page& other) const;
	bool operator>(const User& other) const;
};

#endif 