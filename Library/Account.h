#pragma once
template<class T>
class ListAccount;

template<class T>
class Account
{
	friend ListAccount<T>;
private:
	T user;
	T pass;
	Account* next;

public:

	Account(T user, T pass);
	void display();

};