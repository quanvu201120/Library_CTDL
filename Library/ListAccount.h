#pragma once
#include "Account.cpp"
template<class T>
class ListAccount
{
private:
	Account<T>* head;
	Account<T>* tail;

public:
	ListAccount();
	void addAccount(T user, T pass);
	bool search(T user, T pass);
	void display();



};

