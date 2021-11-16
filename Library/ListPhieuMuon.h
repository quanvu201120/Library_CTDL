#pragma once
#include "PhieuMuon.cpp"

template<class DataType>
class ListPhieuMuon
{
private:
	PhieuMuon<DataType>* head;
	PhieuMuon<DataType>* tail;
	int id_next;
public:
	ListPhieuMuon();
	void addPM(PhieuMuon<DataType>* data);
	void update(DataType idPM);
	void display();
	int getSize();
	DataType getIdSach(DataType idPM);
	bool checkID(DataType id);
	DataType getTinhTrangPM(DataType id);
};

