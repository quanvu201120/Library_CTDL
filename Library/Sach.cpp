#pragma once
#include "Sach.h"
#include<iostream>

template<class DataType>
Sach<DataType>::Sach(
    DataType imaSach,
    DataType itenSach, DataType itenTacGia,
    DataType inhaXuatBan, DataType ingayNhapKho,
    DataType igiaBan,
    DataType inamPhatHanh, DataType isoTrang, DataType itrangthai
)
{
    maSach = imaSach;
    tenSach = itenSach;
    tenTacGia = itenTacGia;
    nhaXuatBan = inhaXuatBan;
    giaBan = igiaBan;
    namPhatHanh = inamPhatHanh;
    soTrang = isoTrang;
    ngayNhapKho = ingayNhapKho;
    trangthai = itrangthai;
    next = NULL;
}


template<class DataType>
void Sach<DataType>::HienThiThongTinSach() {
    cout << "\t\t\t\t\tMa Sach: " << maSach << endl;
    cout << "\t\t\t\t\tTen Sach: " << tenSach << endl;
    cout << "\t\t\t\t\tTen Tac Gia: " << tenTacGia << endl;
    cout << "\t\t\t\t\tNha Xuat Ban: " << nhaXuatBan << endl;
    cout << "\t\t\t\t\tNgay Nhap Kho: " << ngayNhapKho << endl;
    cout << "\t\t\t\t\tGia Ban: " << giaBan << endl;
    cout << "\t\t\t\t\tNam Phat Hanh: " << namPhatHanh << endl;
    cout << "\t\t\t\t\tSo Trang: " << soTrang << endl;
    cout << "\t\t\t\t\tTrang thai: " << trangthai << endl;
    cout << "\t\t\t\t\t--------------------------------"<< endl;
}

template<class DataType>
void Sach<DataType>::setTrangThai(DataType itrangThai) {
    trangthai = itrangThai;
}
