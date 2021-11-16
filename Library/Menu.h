#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include "Loginn.h"
#include "ListSach.cpp"
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "ListUser.cpp"
#include "ListPhieuMuon.cpp"
using namespace std;

void show_menu();

ListUser<string> getListUser() {
	ListUser<string> listUser;
	ifstream MyReadFileUser("User.txt");

	string maUser, tenUser, ngayDK;

	while (getline(MyReadFileUser, maUser) &&
		getline(MyReadFileUser, tenUser) &&
		getline(MyReadFileUser, ngayDK)) {

		User<string>* add = new User<string>(maUser, tenUser, ngayDK);
		listUser.addUser(add);

	}

	MyReadFileUser.close();
	return listUser;
}

ListSach<string> getListSach(){
	ListSach<string> l;
	ifstream MyReadFileSach("Sach.txt");

	string tenSach, tenTacGia, nhaXuatBan, ngayNhapKho;
	string giaBan;
	string maSach, namPhatHanh, soTrang, trangthai;

	while (getline(MyReadFileSach, maSach) &&
		getline(MyReadFileSach, tenSach) &&
		getline(MyReadFileSach, tenTacGia) &&
		getline(MyReadFileSach, nhaXuatBan) &&
		getline(MyReadFileSach, ngayNhapKho) &&
		getline(MyReadFileSach, giaBan) &&
		getline(MyReadFileSach, namPhatHanh) &&
		getline(MyReadFileSach, soTrang) &&
		getline(MyReadFileSach, trangthai)) {

		Sach<string>* add = new Sach<string>(maSach, tenSach, tenTacGia, nhaXuatBan, ngayNhapKho, giaBan, namPhatHanh, soTrang, trangthai);
		l.addSach(add);

	}


	MyReadFileSach.close();
	return l;
}

ListPhieuMuon<string> getListPhieuMuon() {

	ListPhieuMuon<string> l;
	ifstream MyReadFilePM("PhieuMuon.txt");

	string soPhieuMuon, maBanDoc, maSach, ngayMuon, ngayPhaiTra, tinhTrang;
	

	while (getline(MyReadFilePM, soPhieuMuon) &&
		getline(MyReadFilePM, maBanDoc) &&
		getline(MyReadFilePM, maSach) &&
		getline(MyReadFilePM, ngayMuon) &&
		getline(MyReadFilePM, ngayPhaiTra) &&
		getline(MyReadFilePM, tinhTrang)) {

		PhieuMuon<string>* add = new PhieuMuon<string>(soPhieuMuon, maBanDoc, maSach, ngayMuon, ngayPhaiTra, tinhTrang);
		l.addPM(add);

	}

	MyReadFilePM.close();
	return l;

}

string tangNgayThemBay(int ngay, int thang, int nam) {
	int kt;
	int sngay;
	if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
		kt = 1;
	else {
		kt = 0;
	}
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
		sngay = 31;
		ngay = ngay + 7;
		if (ngay > sngay) {
			ngay = ngay - sngay;
			thang = thang + 1;
			if (thang > 12) {
				nam = nam + 1;
				thang = 1;
			}
		}

		stringstream ssngay, ssthang, ssnam;

		ssngay << ngay;
		ssthang << thang;
		ssnam << nam;

		string ingay, ithang, inam;

		ssngay >> ingay;
		ssthang >> ithang;
		ssnam >> inam;

		return ingay + "/" + ithang + "/" + inam;

	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
		sngay = 30;
		ngay = ngay + 7;
		if (ngay > sngay) {
			ngay = ngay - sngay;
			thang = thang + 1;
		}
		stringstream ssngay, ssthang, ssnam;

		ssngay << ngay;
		ssthang << thang;
		ssnam << nam;

		string ingay, ithang, inam;

		ssngay >> ingay;
		ssthang >> ithang;
		ssnam >> inam;

		return ingay + "/" + ithang + "/" + inam;

	}
	else if (thang == 2) {
		if (kt == 1) {
			sngay = 29;
			ngay = ngay + 7;
			if (ngay > sngay) {
				ngay = ngay - sngay;
				thang = thang + 1;
			}
		}
		else {
			sngay = 28;
			ngay = ngay + 7;
			if (ngay > sngay) {
				ngay = ngay - sngay;
				thang = thang + 1;
			}
		}
		stringstream ssngay, ssthang, ssnam;
		ssngay << ngay;
		ssthang << thang;
		ssnam << nam;
		string ingay, ithang, inam;
		ssngay >> ingay;
		ssthang >> ithang;
		ssnam >> inam;
		return ingay + "/" + ithang + "/" + inam;
	}

}

void Hello()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * *";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "\n\t\t\t\t\t\tHE THONG THU VIEN HCMUE\t\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

void QLS() {

	ListSach<string> l = getListSach();
	
	//
	Hello();

	cout << "\t\t\t\t\t[1] Hien thi thong tin sach" << endl;
	cout << "\t\t\t\t\t[2] Them sach" << endl;
	cout << "\t\t\t\t\t[3] Xoa sach" << endl;
	cout << "\t\t\t\t\t[0] Quay lai" << endl;
	cout << "\t\t\t\t\tNhan Esc de thoat"<<endl<<endl;
	cout << "\t\t\t\t\tMoi lua chon: ";

	string a = "";
	char ch = _getch(); 
	while (ch != 13) {
		if (ch == 27) {
			exit(0);
		}
		a.push_back(ch);
		cout << ch;
		ch = _getch();
	}
	
	//hien thi thong tin sach
	if (a == "1") {
		
		system("cls");
		Hello();
		
		l.display();

		cout << endl;
		cout << "\t\t\t\t\t[0] Quay lai" << endl;
		cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
		cout << "\t\t\t\t\tMoi lua chon: ";

		string tmpp1 = "";
		char ch1 = _getch();
		while (ch1 != 13) {
			if (ch1 == 27) {
				exit(0);
			}
			tmpp1.push_back(ch1);
			cout << ch1;
			ch1 = _getch();
		}

		if (tmpp1 == "0") {
			system("cls");
			QLS();
		}

	}
	//end hien thi thong tin sach

	//them sach
	if (a == "2") {

		system("cls");
		Hello();

		string tenSach, tenTacGia, nhaXuatBan, ngayNhapKho;
		string giaBan;
		string maSach, namPhatHanh, soTrang, trangthai = "0";

		cout << "\n\t\t\t\t\t* * Them Sach * *\n\n";

		cout << "\t\t\t\t\tMa sach: "; getline(cin, maSach);getline(cin, maSach);

		cout << "\t\t\t\t\tTen sach: "; getline(cin, tenSach);

		cout << "\t\t\t\t\tTen tac gia: "; getline(cin, tenTacGia);

		cout << "\t\t\t\t\tNha xuat ban: "; getline(cin, nhaXuatBan);

		cout << "\t\t\t\t\tNgay nhap kho (dd/mm/yyyy): "; getline(cin, ngayNhapKho);

		cout << "\t\t\t\t\tGia ban: ";  getline(cin, giaBan);

		cout << "\t\t\t\t\tNam phat hanh: ";  getline(cin, namPhatHanh);

		cout << "\t\t\t\t\tSo trang: "; getline(cin, soTrang);

		if (l.checkID(maSach)) {
			cout << "\n\n\t\t\t\t\tMa sach da ton tai";
		}
		else {

			ofstream writeSach("Sach.txt", ios::app);
			
			writeSach << maSach << endl;
			writeSach << tenSach << endl;
			writeSach << tenTacGia << endl;
			writeSach << nhaXuatBan << endl;
			writeSach << ngayNhapKho << endl;
			writeSach << giaBan << endl;
			writeSach << namPhatHanh << endl;
			writeSach << soTrang << endl;
			writeSach << trangthai<< endl;

			writeSach.close();

			Sach<string>* addi = new Sach<string>(maSach, tenSach, tenTacGia, nhaXuatBan, ngayNhapKho, giaBan, namPhatHanh, soTrang, trangthai);
			l.addSach(addi);

			cout << "\n\n\t\t\t\t\tThem sach thanh cong";

		}
		
		
		
		cout << endl;
		cout << "\t\t\t\t\t[0] Quay lai" << endl;
		cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
		cout << "\t\t\t\t\tMoi lua chon: ";

		string tmpp2 = "";
		char ch2 = _getch();
		while (ch2 != 13) {
			if (ch2 == 27) {
				exit(0);
			}
			tmpp2.push_back(ch2);
			cout << ch2;
			ch2 = _getch();
		}

		if (tmpp2 == "0") {
			system("cls");
			QLS();
		}

		
	}
	//end them sach

	//xoa sach
	if (a == "3") {
		system("cls");
		Hello(); 
		string idSach;
		cout << "\n\n\t\t\t\t\tNhap ma sach can xoa: ";
		cin >> idSach;

		Sach<string>* deleteSach = l.search(idSach);

		int luachon;
		
		if (deleteSach == NULL) {
			cout << "\n\n\t\t\t\t\tMa sach khong ton tai";
			cout << "\n\n\t\t\t\t\t[0] Quay lai" << endl;
			cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
			cout << "\t\t\t\t\tMoi lua chon: ";

			string tmpp3 = "";
			char ch3 = _getch();
			while (ch3 != 13) {
				if (ch3 == 27) {
					exit(0);
				}
				tmpp3.push_back(ch3);
				cout << ch3;
				ch3 = _getch();
			}

			if (tmpp3 == "0") {
				system("cls");
				QLS();
			}

		}
		else {
			cout << "\n\t\t\t\t\t--------------------------------" << endl;
			deleteSach->HienThiThongTinSach();

			cout << "\n\n\t\t\t\t\t[0] Quay lai" << endl;
			cout << "\t\t\t\t\t[1] Xac nhan xoa sach" << endl;
			cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
			cout << "\t\t\t\t\tMoi lua chon: ";

			string tmpp4 = "";
			char ch4 = _getch();
			while (ch4 != 13) {
				if (ch4 == 27) {
					exit(0);
				}
				tmpp4.push_back(ch4);
				cout << ch4;
				ch4 = _getch();
			}

			if (tmpp4 == "0") {
				system("cls");
				QLS();
			}
			if (tmpp4 == "1") {
				system("cls"); Hello();
				if (deleteSach -> getTrangThai() == "0") {
					l.Delete(deleteSach);

					cout << "\n\t\t\t\t\tXoa sach thanh cong";
				}
				else {
					cout << "\n\t\t\t\t\tKhong the xoa, sach dang duoc muon";
				}
				
				cout << "\n\n\t\t\t\t\t[0] Quay lai" << endl;
				cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
				cout << "\t\t\t\t\tMoi lua chon: ";

				string tmpp5 = "";
				char ch5 = _getch();
				while (ch5 != 13) {
					if (ch5 == 27) {
						exit(0);
					}
					tmpp5.push_back(ch5);
					cout << ch5;
					ch5 = _getch();
				}

				if (tmpp5 == "0") {
					system("cls");
					QLS();
				}
			}
		}

	}
	//end xoa sach

	if (a == "0") {
	
		system("cls");
		Hello();
		show_menu();
	
	}

}

void QLPM() {
	Hello();

	ListSach<string> listSach = getListSach();
	ListPhieuMuon<string> listPM = getListPhieuMuon();
	ListUser<string> listUser = getListUser();

	cout << "\t\t\t\t\t[1] Hien thi thong tin cac phieu muon" << endl;
	cout << "\t\t\t\t\t[2] Muon sach" << endl;
	cout << "\t\t\t\t\t[3] Tra sach" << endl;
	cout << "\t\t\t\t\t[0] Quay lai" << endl;
	cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
	cout << "\t\t\t\t\tMoi lua chon: ";

	string tmpp6 = "";
	char ch6 = _getch();
	while (ch6 != 13) {
		if (ch6 == 27) {
			exit(0);
		}
		tmpp6.push_back(ch6);
		cout << ch6;
		ch6 = _getch();
	}

	//Hien thi phieu muon
	if (tmpp6 == "1") {

		system("cls"); Hello();

		listPM.display();


		/************/
		cout << endl;
		cout << "\t\t\t\t\t[0] Quay lai" << endl;
		cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
		cout << "\t\t\t\t\tMoi lua chon: ";

		string tmpp1 = "";
		char ch1 = _getch();
		while (ch1 != 13) {
			if (ch1 == 27) {
				exit(0);
			}
			tmpp1.push_back(ch1);
			cout << ch1;
			ch1 = _getch();
		}

		if (tmpp1 == "0") {
			system("cls");
			QLPM();
		}

		/*********/

	}
	//End hien thi phieu muon

	//Muon sach
	if (tmpp6 == "2") {

		system("cls"); Hello();
		
		string soPhieuMuon, maBanDocs, maSachs, ngayMuon, ngayPhaiTra, tinhTrang;

		cout << "\n\t\t\t\t\t* * Muon Sach * *\n\n";

		cout << "\t\t\t\t\tMa ban doc: "; getline(cin, maBanDocs); getline(cin, maBanDocs);

		cout << "\t\t\t\t\tMa sach: "; getline(cin, maSachs);

		stringstream ss;
		ss << listPM.getSize();

		soPhieuMuon = ss.str();
		tinhTrang = "1";

		
		
		time_t baygio = time(0);


		tm* ltm = localtime(&baygio);

		int ingay = ltm->tm_mday;
		int ithang = 1 + ltm->tm_mon;
		int inam = 1900 + ltm->tm_year;

		stringstream ss1, ss2, ss3;
		ss1 << ingay;
		ss2 << ithang;
		ss3 << inam;

		string str_ngay, str_thang, str_nam;
		ss1 >> str_ngay;
		ss2 >> str_thang;
		ss3 >> str_nam;

		ngayMuon = str_ngay + "/" + str_thang + "/" + str_nam ;
		
		ngayPhaiTra = tangNgayThemBay(ingay,ithang,inam);

		
		if (listUser.checkID(maBanDocs) && listSach.checkID(maSachs) && listSach.search(maSachs)->getTrangThai() == "0") {
			ofstream writePM("PhieuMuon.txt", ios::app);

			writePM << soPhieuMuon << endl;
			writePM << maBanDocs << endl;
			writePM << maSachs << endl;
			writePM << ngayMuon << endl;
			writePM << ngayPhaiTra << endl;
			writePM << tinhTrang << endl;

			writePM.close();


			PhieuMuon<string>* add = new PhieuMuon<string>(soPhieuMuon, maBanDocs, maSachs, ngayMuon, ngayPhaiTra, tinhTrang);
			listPM.addPM(add);

			listSach.update(maSachs,soPhieuMuon);

			system("cls"); Hello();
			cout << "\n\n\t\t\t\t\tMuon sach thanh cong";

			cout << endl << endl;
			add->HienThiThongPhieuMuon();
		}
		else {
			 
			 if (!listUser.checkID(maBanDocs)) {
				cout << "\n\t\t\t\t\tMa ban doc khong ton tai\n";
			 }
			 if (!listSach.checkID(maSachs)) {
				 cout << "\n\t\t\t\t\tMa sach doc khong ton tai\n";
			 }
			 if (listSach.search(maSachs)->getTrangThai() != "0") {
				 cout << "\n\t\t\t\t\tSach da duoc nguoi khac muon\n";
			 }

		}
		

		/************/
		
		cout << "\n\n\t\t\t\t\t[0] Quay lai" << endl;
		cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
		cout << "\t\t\t\t\tMoi lua chon: ";

		string tmpp1 = "";
		char ch1 = _getch();
		while (ch1 != 13) {
			if (ch1 == 27) {
				exit(0);
			}
			tmpp1.push_back(ch1);
			cout << ch1;
			ch1 = _getch();
		}

		if (tmpp1 == "0") {
			system("cls");
			QLPM();
		}

		/*********/

	}
	//End muon sach

	//Tra sach
	if (tmpp6 == "3") {

		system("cls"); Hello();

		string maPM;
		cout << "\n\t\t\t\t\t* * Tra Sach * *\n\n";

		cout << "\t\t\t\t\tMa phieu muon: "; cin>>maPM;

		if (listPM.checkID(maPM) && listPM.getTinhTrangPM(maPM) != "0") {

			string idSach = listPM.getIdSach(maPM);
			string trangThaiSach = "0";
			listPM.update(maPM);
			listSach.update(idSach, trangThaiSach);

			cout << "\n\n\t\t\t\t\t*******************";
			cout << "\n\t\t\t\t\tTra sach thanh cong" ;
			cout << "\n\t\t\t\t\t*******************";
			
			listSach.update(idSach, trangThaiSach);
			
		}
		else {
			cout << "\n\n\t\t\t\t\t*******************" ;
			cout << "\n\t\t\t\t\tTra sach that bai" ;
			cout << "\n\t\t\t\t\t*******************" ;
		}


		/************/
		
		cout << "\n\n\t\t\t\t\t[0] Quay lai" << endl;
		cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
		cout << "\t\t\t\t\tMoi lua chon: ";

		string tmpp1 = "";
		char ch1 = _getch();
		while (ch1 != 13) {
			if (ch1 == 27) {
				exit(0);
			}
			tmpp1.push_back(ch1);
			cout << ch1;
			ch1 = _getch();
		}

		if (tmpp1 == "0") {
			system("cls");
			QLPM();
		}

		/*********/
	}
	//End tra sach


	if (tmpp6 == "0") {

		system("cls");
		Hello();
		show_menu();

	}

}

void QLBD() {
	Hello();

	ListUser<string> listUser = getListUser();

	cout << "\t\t\t\t\t[1] Hien thi thong ban doc" << endl;
	cout << "\t\t\t\t\t[2] Them ban doc" << endl;
	cout << "\t\t\t\t\t[0] Quay lai" << endl;
	cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
	cout << "\t\t\t\t\tMoi lua chon: ";

	string a = "";
	char ch = _getch();
	while (ch != 13) {
		if (ch == 27) {
			exit(0);
		}
		a.push_back(ch);
		cout << ch;
		ch = _getch();
	}

	//Hien thi ban doc
	if (a == "1") {
		system("cls"); Hello();
		listUser.display();


		cout << endl;
		cout << "\t\t\t\t\t[0] Quay lai" << endl;
		cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
		cout << "\t\t\t\t\tMoi lua chon: ";

		string tmpp1 = "";
		char ch1 = _getch();
		while (ch1 != 13) {
			if (ch1 == 27) {
				exit(0);
			}
			tmpp1.push_back(ch1);
			cout << ch1;
			ch1 = _getch();
		}

		if (tmpp1 == "0") {
			system("cls");
			QLBD();
		}

	}
	//End hien thi ban doc

	//Them ban doc
	if (a == "2") {
		
		system("cls");
		Hello();

		string maUser, tenUser, ngayDK;

		cout << "\n\t\t\t\t\t* * Them ban doc * *\n\n";

		cout << "\t\t\t\t\tMa ban doc: "; getline(cin, maUser); getline(cin, maUser);

		cout << "\t\t\t\t\tTen ban doc: "; getline(cin, tenUser);

		
		time_t baygio = time(0);


		tm* ltm = localtime(&baygio);

		int ingay = ltm->tm_mday;
		int ithang = 1 + ltm->tm_mon;
		int inam = 1900 + ltm->tm_year;

		stringstream ss1, ss2, ss3;
		ss1 << ingay;
		ss2 << ithang;
		ss3 << inam;

		string str_ngay, str_thang, str_nam;
		ss1 >> str_ngay;
		ss2 >> str_thang;
		ss3 >> str_nam;

		ngayDK = str_ngay + "/" + str_thang + "/" + str_nam;

		

		if (listUser.checkID(maUser)) {
			cout << "\n\n\t\t\t\t\tMa ban doc da ton tai";
		}
		else {

			ofstream writeSach("User.txt", ios::app);

			writeSach << maUser << endl;
			writeSach << tenUser << endl;
			writeSach << ngayDK << endl;

			writeSach.close();

			User<string>* new_data = new User<string>(maUser, tenUser, ngayDK);
			listUser.addUser(new_data);

			cout << "\n\n\t\t\t\t\tThem ban doc thanh cong";

		}

		cout << endl;
		cout << "\t\t\t\t\t[0] Quay lai" << endl;
		cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
		cout << "\t\t\t\t\tMoi lua chon: ";

		string tmpp2 = "";
		char ch2 = _getch();
		while (ch2 != 13) {
			if (ch2 == 27) {
				exit(0);
			}
			tmpp2.push_back(ch2);
			cout << ch2;
			ch2 = _getch();
		}

		if (tmpp2 == "0") {
			system("cls");
			QLBD();
		}
	
	}
	//End them ban doc

	if (a == "0") {
		system("cls");
		Hello();
		show_menu();
	}
}

void show_menu() {


	cout << endl;
	cout << "\t\t\t\t\t[1] Quan ly sach" << endl;
	cout << "\t\t\t\t\t[2] Quan ly phieu muon" << endl;
	cout << "\t\t\t\t\t[3] Quan ly ban doc" << endl;
	cout << "\t\t\t\t\tNhan Esc de thoat" << endl << endl;
	cout << "\n\t\t\t\t\tMoi lua chon: ";


	string a = "";
	char ch = _getch();
	
	while (ch != 13) {
		if (ch == 27) {
			exit(0);
		}
		a.push_back(ch);
		cout << ch;
		ch = _getch();
	}

	//quan ly sach
	if (a == "1") {
		system("cls");
		QLS();
	}

	//quan ly phieu muon
	if (a == "2") {
		system("cls");
		QLPM();
	}

	//quan ly ban doc
	if (a == "3") {
		system("cls");
		QLBD();
	}

}