#pragma once
#include "ListUser.h"
#include<iostream>

template<class DataType>
ListUser<DataType>::ListUser() {
	head = tail = NULL;
}

template<class DataType>
void ListUser<DataType>::addUser(User<DataType>* data) {
	if (head == NULL) {
		head = tail = data;
	}
	else {
		tail->next = data;
		tail = tail->next;
	}
}

template<class DataType>
void ListUser<DataType>::display() {

	User<DataType>* p = head;
	while (p != NULL) {
		p->display();
		p = p->next;
	}

}

template<class DataType>
bool ListUser<DataType>::checkID(DataType id) {

	User<DataType>* pnt = head;

	while (pnt != NULL) {
		DataType tmp = pnt->MaUser;

		if (id == tmp) {
			return true;
		}

		pnt = pnt->next;
	}

	return false;
}

