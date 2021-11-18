#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "ListAccount.cpp"
#include <windows.h>
using namespace std;

void welcomeScreen()
{		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * *";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "\n\t\t\t\t\t\tDANG NHAP HE THONG\t\t";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout<< "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

}






bool Login_Admin() {

	/*
	ofstream MyWriteFile("Admin.txt");
	MyWriteFile << "Files can be tricky, but it is fun enough!";
	MyWriteFile.close();
	*/

	string mUser, mPass; 

	ListAccount<string> l;

	ifstream MyReadFile("Admin.txt");

	while (getline(MyReadFile, mUser) && getline(MyReadFile, mPass)) {
		l.addAccount(mUser, mPass);
	}



	int count = 3;
	string UserName, PassWord = "";
	char ch;

	while (count > 0) {

		welcomeScreen();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "\n\t\t\t\t\tUserName: ";
		cin >> UserName;
		cout << "\t\t\t\t\tPassWord: ";

		ch = _getch();
		while (ch != 13) {
			PassWord.push_back(ch);
			cout << '*';
			ch = _getch();
		}

		if (l.search(UserName,PassWord)) {
			return true;
		}
		else {

			count--;
			PassWord = "";

			if (count == 0) {
				return false;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "\n\n\t\t\t\t\tUsername/Password khong chinh xac";

			cout << "\n\n\t\t\t\t\tNhan Esc de thoat";
			cout << "\n\t\t\t\t\tNhap \"yes\" de dang nhap lai: ";

			string tmp;
			char chh;
			
			chh = _getch();
			while (chh != 13) {
				if (chh == 27) {
					exit(0);
				}
				tmp.push_back(chh);
				cout << chh;
				chh = _getch();
			}

			if (tmp == "yes") {
				system("cls");
			}
			else return false;

		}

	}

	MyReadFile.close();
}
