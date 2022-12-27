#ifndef FACEBOOK_H
#define FACEBOOK_H

#include "Fans_page.h"
#include "Status.h"
#include "User.h"


class Facebook {

	Facebook(const Facebook& other) = delete;
	vector<User*> all_users;
	vector<Fans_page*> all_fans_page;

public:

	Facebook();
	~Facebook();
	vector<User*> getarr_all_users() const { return all_users; }
	void add_user(string s, int d, int m, int y);
	void add_fanPage(const string page_name);
	void add_status_to_user(const string name, const string status);
	void add_status_to_fan_page(const string name, const string status);
	void show_all_status(string name, int num);
	void show_all_friends_status(string name);
	void create_friendship(string name, string name2);
	void cancel_friendsship(string name, string name2);
	void add_fan_to_fanPage(string fan_name, string page_name);
	void print_all_users_and_pages();
	void print_all_followers(string name, int num);
	void remove_fan_from_page(string fan_name, string page_name);
};

#endif 


