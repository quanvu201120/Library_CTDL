#pragma once
#include<string.h>
#include<iostream>
using namespace std;

template<class DataType>
class ListSach;

template<class DataType>
class Sach {
    friend ListSach<DataType>;
private:
    DataType tenSach, tenTacGia, nhaXuatBan, ngayNhapKho,giaBan, maSach, namPhatHanh, soTrang, trangthai;

    Sach<DataType> *next;

public:

    Sach(DataType imaSach, DataType itenSach, DataType itenTacGia, DataType inhaXuatBan, DataType ingayNhapKho,
        DataType igiaBan, DataType inamPhatHanh, DataType isoTrang, DataType trangthai);

    void HienThiThongTinSach();
    DataType getTenSach() {
        return tenSach;
    }
    DataType getTacGia() {
        return tenTacGia;
    }
    DataType getNhaXuatBan() {
        return nhaXuatBan;
    }
    DataType getNgayNhapKho() {
        return ngayNhapKho;
    }
    DataType getGiaBan() {
        return giaBan;
    }
    DataType getMaSach() {
        return maSach;
    }
    DataType getNamPhatHanh() {
        return namPhatHanh;
    }
    DataType getSoTrang() {
        return soTrang;
    }
    DataType getTrangThai() {
        return trangthai;
    }
    void setTrangThai(DataType itrangThai);
};


