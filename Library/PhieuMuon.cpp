#pragma once
#include "PhieuMuon.h"
#include<iostream>
using namespace std;

template<class DataType>
PhieuMuon<DataType>::PhieuMuon(
    DataType isoPhieuMuon, DataType imaBanDoc, DataType imaSach,
    DataType ingayMuon, DataType ingayPhaiTra, DataType itinhTrang)
{
    soPhieuMuon = isoPhieuMuon;
    maBanDoc = imaBanDoc;
    maSach = imaSach;
    ngayMuon = ingayMuon;
    ngayPhaiTra = ingayPhaiTra;
    tinhTrang = itinhTrang;
    next = NULL;
}


template<class DataType>
void PhieuMuon<DataType>::HienThiThongPhieuMuon() {

    cout << "\t\t\t\t\tSo Phieu Muon: " << soPhieuMuon << endl;
    cout << "\t\t\t\t\tMa Ban Doc: " << maBanDoc << endl;
    cout << "\t\t\t\t\tMa Sach: " << maSach << endl;
    cout << "\t\t\t\t\tNgay Muon: " << ngayMuon << endl;
    cout << "\t\t\t\t\tNgay Phai Tra: " << ngayPhaiTra << endl;
    cout << "\t\t\t\t\tTinh Trang: " << tinhTrang << endl;
    cout << "\t\t\t\t\t--------------------------------" << endl;

}

template<class DataType>
void PhieuMuon<DataType>::setTinhTrang(DataType value) {
    this->tinhTrang = value;
}
