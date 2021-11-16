#pragma once
#include "ListPhieuMuon.h"

template<class DataType>
ListPhieuMuon<DataType>::ListPhieuMuon() {
	head = tail = NULL;
	id_next = 1;
}

template<class DataType>
void ListPhieuMuon<DataType>::addPM(PhieuMuon<DataType>* data) {
	if (head == NULL) {
		head = tail = data;
	}
	else {
		tail->next = data;
		tail = tail->next;
	}
	id_next++;
}

template<class DataType>
void ListPhieuMuon<DataType>::update(DataType idPM) {

	PhieuMuon<DataType>* pp = head;
	while (pp != NULL && pp->soPhieuMuon != idPM) {
		pp = pp->next;
	}

	pp->setTinhTrang("0");

	ofstream writePM("PhieuMuon.txt");

	for (PhieuMuon<DataType>* p = head; p != NULL; p = p->next) {
		writePM << p->soPhieuMuon << endl;
		writePM << p->maBanDoc << endl;
		writePM << p->maSach << endl;
		writePM << p->ngayMuon << endl;
		writePM << p->ngayPhaiTra << endl;
		writePM << p->tinhTrang << endl;
	}
	writePM.close();

}

template<class DataType>
void ListPhieuMuon<DataType>::display() {

	PhieuMuon<DataType>* pp = head;
	while (pp != NULL ) {
		pp->HienThiThongPhieuMuon();
		pp = pp->next;
	}
	
}

template<class DataType>
int ListPhieuMuon<DataType>::getSize() {
	return this->id_next;
}

template<class DataType>
DataType ListPhieuMuon<DataType>::getIdSach(DataType idPM) {

	PhieuMuon<DataType>* pp = head;
	while (pp != NULL && pp->soPhieuMuon != idPM) {
		pp = pp->next;
	}

	return pp->maSach;
}

template<class DataType>
bool ListPhieuMuon<DataType>::checkID(DataType id) {

	PhieuMuon<DataType>* pp = head;
	while (pp != NULL) {

		if (pp->soPhieuMuon == id) {
			return true;
		}

		pp = pp->next;
	}

	return false;

}

template<class DataType>
DataType ListPhieuMuon<DataType>::getTinhTrangPM(DataType id) {
	PhieuMuon<DataType>* pp = head;
	while (pp != NULL ) {

		if (pp->soPhieuMuon == id) {
			return pp->tinhTrang;
		}

		pp = pp->next;
	}
}