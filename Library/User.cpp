#pragma one
#include<iostream>
#include "User.h"
using namespace std;

template<class DataType>
User<DataType>::User(DataType maUser, DataType tenUser, DataType ngayDK) {
	MaUser = maUser;
	TenUser = tenUser;
	NgayDK = ngayDK;
	next = NULL;
}

template<class DataType>
DataType User<DataType>::getMaUser() {
	return MaUser;
}

template<class DataType>
void User<DataType>::display() {

	cout << "\t\t\t\t\tMa ban doc: " << MaUser << endl;
	cout << "\t\t\t\t\tTen ban doc: " << TenUser << endl;
	cout << "\t\t\t\t\tNgay dang ky: " << NgayDK << endl;
	cout << "\t\t\t\t\t--------------------------------" << endl;

}


