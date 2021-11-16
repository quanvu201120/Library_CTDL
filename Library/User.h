#pragma once
template<class DataType>
class ListUser;

template<class DataType>
class User
{
	friend ListUser<DataType>;
private:
	DataType MaUser, TenUser, NgayDK;
	User<DataType>* next;

public:
	User(DataType maUser, DataType tenUser, DataType NgayDK);
	DataType getMaUser();
	void display();
};

