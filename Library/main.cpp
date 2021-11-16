#pragma once
#include<iostream>
#include "Loginn.h"
#include "Menu.h"
using namespace std;

int main() {
	
	if (Login_Admin()) {
		system("cls");
		Hello();
		show_menu();
	}
	else {
		system("cls");
		cout<<"\n\n\n\t\t\t\tDang nhap sai qua 3 lan, vui long thu lai sau\n\n\n";
	}

	return 0;
}
