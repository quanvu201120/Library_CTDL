#pragma once
#include "ListSach.h"
#include<fstream>
template<class DataType>
ListSach<DataType>::ListSach() {
	head = tail = NULL;
	size = 0;
}

template<class DataType>
void ListSach<DataType>::addSach(Sach<DataType>* data) {

	if (head == NULL) {
		head = tail = data;
	}
	else {
		tail->next = data;
		tail = tail->next;
	}
	size++;
}

template<class DataType>
void ListSach<DataType>::display() {

	
	for (Sach<DataType>* p = head; p != NULL; p = p->next) {
	
		p->HienThiThongTinSach();
	
	}


}

template<class DataType>
void ListSach<DataType>::getSize() {

	cout << size;

}

template<class DataType>
bool  ListSach<DataType>::checkID(DataType id) {
	Sach<DataType>* pnt = head;
	
	while (pnt != NULL) {
		DataType tmp = pnt->maSach;

		if (id == tmp) {
			return true;
		}

		pnt = pnt->next;
	}

	return false;

}

template<class DataType>
void ListSach<DataType>::Delete(Sach<DataType>* index) {

	if (head != NULL) {
		if (index == head) {

			Sach<DataType>* tmp = head;
			head = head->next;
			delete tmp;
			if (head == NULL) {
				tail = NULL;
			}
		}
		else if (index == tail) {
			Sach<DataType>* tmp = tail;
			tail = searchPre(tail);
			delete tmp;
			if (tail != NULL) {
				tail->next = NULL;
			}
			else {
				head = NULL;
			}
		}
		else {
			Sach<DataType>* truoc = searchPre(index);
			truoc->next = index->next;
			delete index;
		}
		size--;


		ofstream writeSach("Sach.txt");

		for (Sach<DataType>* p = head; p != NULL; p = p->next) {
			writeSach << p -> maSach << endl;
			writeSach << p -> tenSach << endl;
			writeSach << p-> tenTacGia << endl;
			writeSach << p->nhaXuatBan << endl;
			writeSach << p->ngayNhapKho << endl;
			writeSach << p->giaBan << endl;
			writeSach << p->namPhatHanh << endl;
			writeSach << p->soTrang << endl;
			writeSach << p->trangthai<< endl ;
		}

		writeSach.close();

	}
	
}

template<class DataType>
Sach<DataType>* ListSach<DataType>::search(DataType id) {
	Sach<DataType>* pnt = head;

	while (pnt != NULL ) {

		if(pnt->maSach == id)
			return pnt;

		pnt = pnt->next; 
	}
	return NULL;
}

template<class DataType>
Sach<DataType>* ListSach<DataType>::searchPre(Sach<DataType>*value) {
	if (value == head) return NULL;

	Sach<DataType>* pnt = head;

	while (pnt != NULL && pnt->next!=value) {
		pnt = pnt->next;
	}
	return pnt;
}

template<class DataType>
void ListSach<DataType>::update(DataType IdSach, DataType trangThaiMoi) {


	Sach<DataType>* p = head;
	while (p != NULL && p->maSach!= IdSach) {
		p = p->next;
	}

	p->setTrangThai(trangThaiMoi);

	
	ofstream writeSach("Sach.txt");

		for (Sach<DataType>* p = head; p != NULL; p = p->next) {
			writeSach << p -> maSach << endl;
			writeSach << p -> tenSach << endl;
			writeSach << p-> tenTacGia << endl;
			writeSach << p->nhaXuatBan << endl;
			writeSach << p->ngayNhapKho << endl;
			writeSach << p->giaBan << endl;
			writeSach << p->namPhatHanh << endl;
			writeSach << p->soTrang << endl;
			writeSach << p->trangthai<< endl ;
		}

		writeSach.close();
}

