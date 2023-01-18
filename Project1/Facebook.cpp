#define _CRT_SECURE_NO_WARNINGS
#include "Facebook.h"
#include <cstring>
#include <fstream>
#include <istream>

Facebook::Facebook() 
{
	ifstream inFile("meta.txt");
	int numOfUsers, numOfFanPage, numOfStatus, numOfEntity, day, month, year, type;
	string name, content, time,fileName;
	Status* sta;

	inFile >> numOfUsers;
	for (int i = 0; i < numOfUsers; i++)
	{
		inFile.get();// /0
		getline(inFile, name);
		inFile >> day >> month >> year;
		add_user(name, day, month, year);
	}

	inFile >> numOfFanPage;
	inFile.get();// /0
	for (int i = 0; i < numOfFanPage; i++)
	{
		getline(inFile, name);
		add_fanPage(name);
	}

	for (int j = 0; j < numOfUsers; j++)
	{
		inFile >> numOfStatus;
		inFile.get();// /0
		for (int i = 0; i < numOfStatus; i++)
		{
			getline( inFile, content);
			getline(inFile, time);

			inFile >> type;// type of status
			if (type == 2)
			{
				inFile >> fileName;
				sta = new StatusPhoto(content, time, fileName);
			}
			else if( type==3)
			{
				inFile >> fileName;
				sta = new StatusVideo(content, time, fileName);
			}
			else
			{
				sta = new Status(content, time);
			}
			
			all_users[j]->add_status(sta);
		}

		// friends
		inFile >> numOfEntity;
		inFile.get();// /0
		for (int i = 0; i < numOfEntity; i++)
		{
			getline(inFile, name);
			auto it = all_users.begin();
			for (; it != all_users.end(); ++it)
			{
				if ((*it)->getName() == name)
					break;
			}
			all_users[j]->create_friendship(*it);
		}

		// fan pages

		inFile >> numOfEntity;
		inFile.get();// /0
		for (int i = 0; i < numOfEntity; i++)
		{
			getline(inFile, name);

			auto it = all_fans_page.begin();
			for (; it != all_fans_page.end(); ++it)
			{
				if ((*it)->get_page_name() == name)
					break;
			}
			all_users[j]->add_fan_page(*it);
		}
	}
	for (int j = 0; j < numOfFanPage; j++)
	{
		inFile >> numOfStatus;
		inFile.get();// /0

		for (int i = 0; i < numOfStatus; i++)
		{
			getline(inFile, content);
			getline(inFile, time);

			inFile >> type;// type of status
			if (type == 2)
			{
				inFile >> fileName;
				sta = new StatusPhoto(content, time, fileName);
			}
			else if (type == 3)
			{
				inFile >> fileName;
				sta = new StatusVideo(content, time, fileName);
			}
			else
			{
				sta = new Status(content, time);
			}

			all_fans_page[j]->add_status(sta);
		}

		// followers
		inFile >> numOfEntity;
		inFile.get();// /0
		for (int i = 0; i < numOfEntity; i++)
		{
			getline(inFile, name);
			auto it = all_users.begin();
			for (; it != all_users.end(); ++it)
			{
				if ((*it)->getName() == name)
					break;
			}

			all_fans_page[j]->add_fan(*it);
		}
	}
}

Facebook::~Facebook() {

	ofstream outFile("meta.txt", ios::trunc);

	outFile << all_users.size() << endl;
	for (auto i = all_users.begin(); i < all_users.end(); ++i)
	{
		outFile << (*i)->getName() << endl;
		outFile << (*i)->getdate() << endl;
	}

	outFile << all_fans_page.size() << endl;
	for (auto i = all_fans_page.begin(); i < all_fans_page.end(); ++i)
		outFile << (*i)->get_page_name() << endl;

	for (auto i = all_users.begin(); i < all_users.end(); ++i)
	{
	//print to file all the status
		outFile << (*i)->get_status_arry().size() << endl;
		for (auto j = (*i)->get_status_arry().begin(); j != (*i)->get_status_arry().end(); ++j)
		{
			outFile << (*j)->GetContent() << endl;
			outFile << (*j)->GetTime() << endl;

			StatusPhoto* photo = dynamic_cast<StatusPhoto*>(*j);
			StatusVideo* video = dynamic_cast<StatusVideo*>(*j);
			if (photo)
			{
				outFile << 2 << endl;
				outFile << photo->getfileName() << endl;
			}
			else if (video)
			{
				outFile << 3 << endl;
				outFile << video->getfileName() << endl;
			}
			else
			{
				outFile << 1 << endl;
			}
		}

		//print to file all the friends
		outFile << (*i)->get_friends_arry().size() << endl;
		for (auto j = (*i)->get_friends_arry().begin(); j != (*i)->get_friends_arry().end(); ++j)
		{
			outFile << (*j)->getName() << endl;
		}

		//print to file all the fan page
		outFile << (*i)->get_fan_pages_arr().size() << endl;
		for (auto j = (*i)->get_fan_pages_arr().begin(); j != (*i)->get_fan_pages_arr().end(); ++j)
		{
			outFile << (*j)->get_page_name() << endl;
		}
	}

	//print to file all the content of fan pages

	for (auto i = all_fans_page.begin(); i != all_fans_page.end(); ++i)
	{
	//print to file all the status
		outFile << (*i)->getStatus_of_page().size() << endl;
		for (auto j = (*i)->getStatus_of_page().begin(); j != (*i)->getStatus_of_page().end(); ++j)
		{
			outFile << *(*j) << endl;

			StatusPhoto* photo = dynamic_cast<StatusPhoto*>(*j);
			StatusVideo* video = dynamic_cast<StatusVideo*>(*j);
			if (photo)
			{
				outFile << photo->getfileName() << endl;
			}
			if (video)
			{
				outFile << video->getfileName() << endl;
			}
		}

		//print to file all the friends
		outFile << (*i)->get_fans_arr().size() << endl;
		for (auto j = (*i)->get_fans_arr().begin(); j != (*i)->get_fans_arr().end(); ++j)
		{
			outFile << (*j)->getName() << endl;
		}
	}
	outFile.close();

	for (auto i = all_users.begin(); i != all_users.end(); ++i)
		delete* i;
	for (auto i = all_fans_page.begin(); i != all_fans_page.end(); ++i)
		delete* i;
}

void Facebook::add_user(const string s, int d, int m, int y)
{
	Date birth = Date(d, m, y);
	if (IsUserExist(s))
		throw UserExistexception();
	User* new_user = new User(s, birth);
	all_users.push_back(new_user);

}

void Facebook::add_fanPage(const string page_name)
{
	if (IsFanPageExist(page_name))
		throw FanPageExistexception();
	Fans_page* new_fanpage = new Fans_page(page_name);
	all_fans_page.push_back(new_fanpage);
}

void Facebook::add_status_to_user(const string name, const string status , const string fileName, int num)
{
	Status* new_status = nullptr;
	if (!IsUserExist(name))
		throw UserNotExistexception(name);
	switch (num)
	{
	case 1:
	 new_status = new Status(status);
		break;
	case 2:
	 new_status = new StatusPhoto(status, fileName);
		break;
	case 3:
	 new_status = new StatusVideo(status, fileName);
		break;
	}

	for (auto it=all_users.begin(); it != all_users.end(); ++it)
	{
		if ((*it)->getName() == name)
			(*it)->add_status(new_status);
	}
}

void Facebook::add_status_to_fan_page(const string name, const string status, const string fileName, int num)
{
	Status* new_status = nullptr;
	if (!IsFanPageExist(name))
		throw FanPageNotExistexception(name);

	switch (num)
	{
	case 1:
		new_status = new Status(status);
		break;
	case 2:
		new_status = new StatusPhoto(status, fileName);
		break;
	case 3:
		new_status = new StatusVideo(status, fileName);
		break;
	}
	 
	for (auto it = all_fans_page.begin(); it != all_fans_page.end(); ++it)
	{
		if ((*it)->get_page_name() == name)
			(*it)->add_status(new_status);
	}
}

void Facebook::show_all_status(string name, int num)const 
{
	if (num == 1)
	{
		if (!IsUserExist(name))
			throw UserNotExistexception(name);
		for (auto it = all_users.begin(); it != all_users.end(); ++it)
		{
			if ((*it)->getName() == name)
				(*it)->print_all_status();
		}
	}
	else
	{
		if (!IsFanPageExist(name))
			throw FanPageNotExistexception(name);
		for (auto it = all_fans_page.begin(); it != all_fans_page.end(); ++it)
		{
			if ((*it)->get_page_name() == name)
				(*it)->print_all_status();
		}
	}
}

void Facebook::show_all_friends_status(string name)const {
	
	if (!IsUserExist(name))
		throw UserNotExistexception(name);

	for (auto it = all_users.begin(); it != all_users.end(); ++it)
	{
		if ((*it)->getName() == name) {
			(*it)->show_friends_status();
			break;
		}
	}
}

void Facebook::create_friendship(string name, string name2)
{

	if (name == name2)
		throw friendofyourselfExistexception();

	if (!IsUserExist(name))
		throw UserNotExistexception(name);

	if (!IsUserExist(name2))
		throw UserNotExistexception(name2);

	auto it = all_users.begin();
	auto it2 = all_users.begin();

	for (; it != all_users.end(); ++it)
	{
		if ((*it)->getName() == name)
			break;
	}
	for (; it2 != all_users.end(); ++it2)
	{
		if ((*it2)->getName() == name2)
			break;
	}

	
	(*it)->create_friendship(*it2);
	(*it2)->create_friendship(*it);
	
	
}

void Facebook::cancel_friendsship(string name, string name2)
{
	if (!IsUserExist(name))
		throw UserNotExistexception(name);

	if (!IsUserExist(name2))
		throw UserNotExistexception(name2);

	auto it = all_users.begin();
	auto it2 = all_users.begin();

	for (; it != all_users.end(); ++it)
	{
		if ((*it)->getName() == name)
			break;
	}
	for (; it2 != all_users.end(); ++it2)
	{
		if ((*it2)->getName() == name2)
			break;
	}

	(*it)->cancel_friendship(name2);
	(*it2)->cancel_friendship(name);
}

void Facebook::add_fan_to_fanPage(string name, string name2)
{
	if (!IsUserExist(name2))
		throw UserNotExistexception(name2);

	if (!IsFanPageExist(name))
		throw FanPageNotExistexception(name);

	auto it = all_users.begin();
	auto it2 = all_fans_page.begin();

	for (; it != all_users.end(); ++it)
	{
		if ((*it)->getName() == name2)
			break;
	}
	for (; it2 != all_fans_page.end(); ++it2)
	{
		if ((*it2)->get_page_name() == name)
			break;
	}

	(*it)->add_fan_page((*it2));
	(*it2)->add_fan((*it));
	
}

void Facebook::remove_fan_from_page(string fan_name, string page_name)
{
	if (!IsUserExist(fan_name))
		throw UserNotExistexception(fan_name);

	if (!IsFanPageExist(page_name))
		throw FanPageNotExistexception(page_name);

	auto it = all_users.begin();
	auto it2 = all_fans_page.begin();

	for (; it != all_users.end(); ++it)
	{
		if ((*it)->getName() == fan_name)
			break;
	}
	for (; it2 != all_fans_page.end(); ++it2)
	{
		if ((*it2)->get_page_name() == page_name)
			break;
	}

	if (it != all_users.end() && it2 != all_fans_page.end())
	{
		(*it)->remove_fan_page(page_name);
		(*it2)->remove_fan(fan_name);
	}
}

void Facebook::print_all_users_and_pages()const
{
	cout << "Users:" << endl;
	for (auto it = all_users.begin(); it != all_users.end(); ++it)
		cout << (*it)->getName() << endl;

	cout << "Fan pages:" << endl;
	for (auto it = all_fans_page.begin(); it != all_fans_page.end(); ++it)
		cout << (*it)->get_page_name() << endl;
}

void Facebook::print_all_followers(string name, int num)const
{
	if (num == 1)
	{
		if (!IsUserExist(name))
			throw UserNotExistexception(name);
		for (auto it = all_users.begin(); it != all_users.end(); ++it)
		{
			if ((*it)->getName() == name)
				(*it)->print_all_of_my_folowers();

		}
	}
	else
	{
		if (!IsFanPageExist(name))
			throw FanPageNotExistexception(name);
		for (auto it = all_fans_page.begin(); it != all_fans_page.end(); ++it)
		{
			if ((*it)->get_page_name() == name)
				(*it)->print_all_my_folowers();
		}
	}
}

bool Facebook::IsUserExist(string u_name)const
{
	for (auto it = all_users.begin(); it != all_users.end(); ++it)
	{
		if ((*it)->getName() == u_name)
			return true;
	}
	return false;
}

bool Facebook::IsFanPageExist(string f_name)const
{
	for (auto it = all_fans_page.begin(); it != all_fans_page.end(); ++it)
	{
		if ((*it)->get_page_name() == f_name)
			return true;
	}
	return false;
}
