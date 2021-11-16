#pragma once
#include "ListAccount.h"
#include<iostream>

template<class T>
ListAccount<T>::ListAccount() {
	head = tail = NULL;
}

template<class T>
void ListAccount<T>::addAccount(T user, T pass) {
	Account<T>* add = new Account<T>(user, pass);
	if (head == NULL) {
		head = tail = add;
	}
	else {
		tail->next = add;
		tail = tail->next;
	}
}

template<class T>
void ListAccount<T>::display() {
	Account<T>* p = head;
	while (p != NULL) {
		p->display();
		p = p->next;
	}
}

template<class T>
bool ListAccount<T>::search(T user, T pass) {
	Account<T>* p = head;
	while (p != NULL) {
		if (p->user == user && p->pass == pass) {
			return true;
		}
		p = p->next;
	}
	return false;
}

