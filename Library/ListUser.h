#pragma once
#include "User.cpp"
template<class DataType>
class ListUser
{
private:
	User<DataType>* head, *tail;

public:
	ListUser();
	void addUser(User<DataType>* data);
	void display();
	bool checkID(DataType id);
};

