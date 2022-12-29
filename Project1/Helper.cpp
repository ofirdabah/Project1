#include"Helper.h"
#include <iostream>  
#define NUM_OF_FUNCTION 12


void Helper::console(Facebook& meta)
{
		meta.add_user("ofir", 24, 5, 1999);
		meta.add_user("itay", 3, 2, 1996);
		meta.add_user("ori", 22, 5, 1994);
		meta.add_fanPage("Spain");
		meta.add_fanPage("Brazil");
		meta.add_fanPage("Israel");
		meta.create_friendship("ofir", "itay");
		meta.create_friendship("ofir", "ori");
		meta.add_fan_to_fanPage("Israel", "ori");
		meta.add_fan_to_fanPage("Brazil", "ori");
		meta.add_status_to_user("ofir", "hello world");
		meta.add_status_to_user("ofir", "hello world im football fan");
		meta.add_status_to_user("itay", "hello");
		meta.add_status_to_user("itay", "hello bye");
		meta.add_status_to_user("ori", "i love kayle jenner");
		meta.add_status_to_user("ori", "i love madona");
		meta.add_status_to_fan_page("Brazil", "i love madona");
		meta.add_status_to_fan_page("Brazil", "i love mardona,but pela more");
		meta.add_status_to_fan_page("Israel", "we love 1970 ");
		meta.add_status_to_fan_page("Israel", "we score");
		meta.add_status_to_fan_page("Spain", "we love omer adam and sangria");
		meta.add_status_to_fan_page("Spain", "we will win");



		int num;
		string str;

	do
	{
		try
		{
			num = 0;
			print_main_page();
			cin >> str;
			num = ValidNumber(str);
			manage(num, meta);
		}
		catch (exception& e) 
		{
			cout << e.what() << endl;
		}
	} while (num != NUM_OF_FUNCTION);
}

void Helper::print_main_page()
{
	cout << (int)USER_OPTION::ADD_USER << "  - Add new user" << endl;
	cout << (int)USER_OPTION::ADD_FANPAGE << "  - Add new fan page" << endl;
	cout << (int)USER_OPTION::ADD_STATUS << "  - Add new status" << endl;
	cout << (int)USER_OPTION::SHOW_ALL_STATUS << "  - Show all status" << endl;
	cout << (int)USER_OPTION::SHOW_10_RECENT_STATUS << "  - Show 10 recent status of all my friends" << endl;
	cout << (int)USER_OPTION::CREATE_FRIENDSHIP << "  - Create new friendship" << endl;
	cout << (int)USER_OPTION::CANCLE_FRIENDSHIP << "  - Delete friendship" << endl;
	cout << (int)USER_OPTION::ADD_FUN << "  - Subscribe to fan page" << endl;
	cout << (int)USER_OPTION::REMOVE_FUN << "  - Disubscribe a fan page" << endl;
	cout << (int)USER_OPTION::SHOW_ALL_USERS << " - Show all users and fan page" << endl;
	cout << (int)USER_OPTION::SHOW_ALL_FOLLOWERS << " - Show followers" << endl;
	cout << (int)USER_OPTION::EXIT << " - EXIT" << endl;
}

void Helper::manage(int num, Facebook& meta)
{
	int d, m, y, number;
	string name, status,name2, name_of_fan_page; 

	switch (num)
	{
	case (int)USER_OPTION::ADD_USER:
		
		cout << "Welcome new user please sign up:\n";
		cout << "Please enter name:" << endl;
		cleanBuffer();
		getline(cin, name);
		cout << "Please enter birthday (day month year(enter or space between)):" << endl;
		cin >> d >> m >> y;
		meta.add_user(name, d, m, y);
		break;
	case (int)USER_OPTION::ADD_FANPAGE:
		cout << "Please enter name:" << endl;
		cleanBuffer();
		getline(cin, name_of_fan_page);
		meta.add_fanPage(name_of_fan_page);
		break;
	case (int)USER_OPTION::ADD_STATUS:
		do
		{
			cout << "Add ststus for friend press- (1) / Add status for fan page press- (2)." << endl;
			cin >> number;
		} while ((checkIfOneOrZero(number) == false));

		cout << "Please enter the name:" << endl;
		cleanBuffer();
		getline(cin, name);
		cout << "Please enter the status:" << endl;
		getline(cin, status);
		if (number == 1)
			meta.add_status_to_user(name, status);
		else
			meta.add_status_to_fan_page(name, status);
		break;
	case (int)USER_OPTION::SHOW_ALL_STATUS:
		do
		{
			cout << "Show all status of friend press - (1) / Show all status of fan page press- (2)." << endl;
			cin >> number;
		} while ((checkIfOneOrZero(number) == false));
		cout << "Please enter the name:" << endl;
		cleanBuffer();
		getline(cin, name);
		meta.show_all_status(name, number);
		break;
	case (int)USER_OPTION::SHOW_10_RECENT_STATUS:
		cout << "Please enter the name:" << endl;
		cleanBuffer();
		getline(cin, name);
		meta.show_all_friends_status(name);
		break;
	case (int)USER_OPTION::CREATE_FRIENDSHIP:
		cout << "Please enter the name:" << endl;
		cleanBuffer();
		getline(cin, name);
		cout << "Please enter the secened name:" << endl;
		getline(cin, name2);
		meta.create_friendship(name, name2);
		break;
	case (int)USER_OPTION::CANCLE_FRIENDSHIP:
		cout << "Please enter the name:" << endl;
		cleanBuffer();
		getline(cin, name);
		cout << "Please enter the secened name:" << endl;
		getline(cin, name2);
		meta.cancel_friendsship(name, name2);
		break;
	case (int)USER_OPTION::ADD_FUN:
		cout << "Please enter the name of the page:" << endl;
		cleanBuffer();
		getline(cin, name_of_fan_page);
		cout << "Please enter the name of the friend you want to add:" << endl;
		getline(cin, name);
		meta.add_fan_to_fanPage(name_of_fan_page, name);
		break;
	case (int)USER_OPTION::REMOVE_FUN:
		cout << "Please enter the name of the friend you want to remove:" << endl;
		cleanBuffer();
		getline(cin, name);
		cout << "Please enter the name of the page:" << endl;
		getline(cin, name_of_fan_page);
		meta.remove_fan_from_page(name, name_of_fan_page);
		break;
	case (int)USER_OPTION::SHOW_ALL_USERS:
		meta.print_all_users_and_pages();
		break;

	case (int)USER_OPTION::SHOW_ALL_FOLLOWERS:
		do
		{
			cout << "Show all followers of user - (1) / Show all followres of fan page - (2)." << endl;
			cin >> number;
		} while ((checkIfOneOrZero(number) == false));
		cout << "Please enter the name:" << endl;
		cleanBuffer();
		getline(cin, name);
		cout << "\n" << name << "'s followers:\n";
		meta.print_all_followers(name, number);
		cout << "\n";
		break;
	}
}

bool Helper:: is_number(const string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

int Helper:: ValidNumber(const string number)
{
	int num;
	if (is_number(number))
	{
		num = stoi(number);
		if (num < 13 && num > 0)
			return num;
	}
	throw Helperexception();

}

bool Helper::checkIfOneOrZero(int num)
{
	if (num != 1 && num != 2)
		return false;

	return true;
}


