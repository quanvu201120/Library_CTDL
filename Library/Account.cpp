#pragma once
#include "Account.h"
#include<iostream>
using namespace std;

template<class T>
Account<T>::Account(T user, T pass) {
	this->user = user;
	this->pass = pass;
	next = NULL;
}

template<class T>
void Account<T>::display() {
	cout << "Username: " << user << "  Password: " << pass << endl;
}
