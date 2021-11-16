#pragma once
template<class DataType>
class ListPhieuMuon;

template<class DataType>
class PhieuMuon {
    friend ListPhieuMuon<DataType>;
private:
    DataType soPhieuMuon, maBanDoc, maSach, ngayMuon, ngayPhaiTra, tinhTrang;

    PhieuMuon<DataType>* next;

public:

    PhieuMuon(DataType isoPhieuMuon, DataType imaBanDoc, DataType imaSach, DataType ingayMuon, DataType ingayPhaiTra,
        DataType itinhTrang);

    void HienThiThongPhieuMuon();


    void setTinhTrang(DataType value);
   

};