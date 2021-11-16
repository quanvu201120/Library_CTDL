#pragma once
#include "Sach.cpp"

template<class DataType>
class ListSach
{
private:
	Sach<DataType> *head;
	Sach<DataType>*tail;
	int size;
public:
	ListSach();
	void addSach(Sach<DataType> *data);
	void display();
	void getSize();
	bool checkID(DataType id);
	void Delete(Sach<DataType>* index);
	Sach<DataType>* search(DataType id);
	Sach<DataType>* searchPre(Sach<DataType>* value);
	void update(DataType IdSach, DataType trangThaiMoi);
};




