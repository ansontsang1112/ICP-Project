#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

/*Function Decleations*/
void sysadm();
void sysauth();
void shopadm();
void shopauth();
void customer();
void customerauth();
void add();
void display();
void search();
void modify();
void deleted();
void csa();
void csa2();
void emm();
void etm();

/*Globle Var*/
string shopadmpw = "admin";
int counter = 0, ret_counter = 0;

void ini() {
	cout << "\t\t\t***\tWelcome to HKUSPACE Inventory Management and Record System\t***\n" << endl;
	cout << "\t\t\t\t\t\t***    1819S1    ***\n" << endl;
	cout << "\t\t\t*** This system is developed by CCIT4020 Class No. ?L-?? Group No,?? ***\n\n" << endl;
}

void menu() {
	ini();
	char ch1;
	/*Get Username*/
	wchar_t Username[1000];
	DWORD nUsername = sizeof(Username);
	GetUserName((LPWSTR)Username, &nUsername);
	/*RSM Manu*/
	cout << " ^v^ Welcome " << (TCHAR)Username << " use our IMRS, please select the options. ^v^\n" << endl;
	cout << "~ <Please select the ROLE you are : > ~ \n" << endl;
	cout << " A: System Administrator\n" << endl;
	cout << " B: Shop Administrator\n" << endl;
	cout << " C: Customer\n" << endl;
	cout << "**>> Please remind that you have the permission to login to relavtive sections. <<**\n" << endl;
	cout << "|| Please insert your Role option <A/B/C> || : ";
	cin >> ch1;
	switch (ch1) {
	case 'A':
	case 'a':
		cout << "\nYou have selected System Administrator Role, You will be redirect to Authorization pages. Please wait for 5 seconds" << endl;
		system("timeout 5");
		sysauth();
		break;
	case 'B':
	case 'b':
		cout << "\nYou have selected Shop Administrator Role, You will be redirect to Authorization pages. Please wait for 5 seconds" << endl;
		system("timeout 5");
		shopauth();
		break;
	case 'C':
	case 'c':
		cout << "\nYou have selected Customer Role, You will be redirect to customer selection page." << endl;
		system("timeout 5");
		customerauth();
		break;
	default:
		cout << "\nOnly A / B / C are vaild options, system will return to RSM in 3 second." << endl;
		system("timeout 3");
		system("cls");
		return menu();
	}
};

void sysauth() {
	string pw;
	fstream admpwd;
	char pwd[] = "pwd.dll";
	admpwd.open(pwd);
	for (int i = 0; i < 0; i++) {
		getline(admpwd, pw);
	}
	getline(admpwd, pw);
	string sysadmpw = pw;
	string sysadmauth, failmsg;
	system("CLS");
	ini();
	cout << "***   System Administrator Authorization Page   ***\n" << endl;
	failmsg = (counter == 0) ? "System Login Center." : "Authorization Failure, Please try again.";
	cout << failmsg << endl;
	cout << "\nError Login Counter : " << counter << " times. You can try " << 6 - counter << " times\n" << endl;
	cout << "Please type in the System Administrator's Password : ";
	cin >> sysadmauth;
	if (counter == 5) {
		cout << "You have type in the max. no of wrong password, the program will auto exit in 5 seconds.\n" << endl;
		system("timeout 5");
		exit(0);
	}
	if (sysadmauth == sysadmpw) {
		cout << "\nAuthorization Sucess, You will be redirect to System Menu." << endl;
		system("timeout 5");
		system("cls");
		return sysadm();
	}
	else {
		counter = counter + 1;
		system("CLS");
		return sysauth();
	}
}

void sysadm() {
	int ch2;
	ini();
	counter = 0;
	cout << "***   Shop Administration Panel   ***\n" << endl;
	cout << " 1. Add New Item<s>" << endl;
	cout << " 2. Display Item Record<s>" << endl;
	cout << " 3. Search Item Information<s>" << endl;
	cout << " 4. Modify Item Information<s>" << endl;
	cout << " 5. Delete Item Record<s>" << endl;
	cout << "\n***   System Administration Panel   ***\n" << endl;
	cout << " 6. Change System Administrator's Password" << endl;
	cout << " 7. Change Shop Administrator's Password" << endl;
	cout << " 8. Enable Maintain Mode" << endl;
	cout << " 9. Enable Test Mode" << endl;
	cout << "\n What is your option <1-9> ? || ";
	cin >> ch2;
	switch (ch2) {
	case 1:
		ret_counter = 0;
		add();
		break;
	case 2:
		display();
		break;
	case 3:
		search();
		break;
	case 4:
		modify();
		break;
	case 5:
		deleted();
		break;
	case 6:
		csa();
		break;
	case 7:
		ret_counter = 0;
		csa2();
		break;
	case 8:
		emm();
		break;
	case 9:
		etm();
		break;
	default:
		cout << "No this option < " << ch2 << " >, < 1 - 9 > Only." << endl;
		system("timeout 5");
		return sysadm();
	}
};

void shopauth() {
	string pw;
	fstream shoppwd;
	char pwd[] = "pwd.dll";
	shoppwd.open(pwd);
	for (int i = 0; i < 1; i++) {
		getline(shoppwd, pw);
	}
	getline(shoppwd, pw);
	string shopadmpw = pw;
	string shopadmauth, failmsg;
	system("CLS");
	ini();
	cout << "***   Shop Administrator Authorization Page   ***\n" << endl;
	failmsg = (counter == 0) ? "System Login Center." : "Authorization Failure, Please try again.";
	cout << failmsg << endl;
	cout << "\nError Login Counter : " << counter << " times. You can try " << 6 - counter << " times\n" << endl;
	cout << "Please type in the Shop Administrator's Password : ";
	cin >> shopadmauth;
	if (counter == 5) {
		cout << "You have type in the max. no of wrong password, the program will auto exit in 5 seconds.\n" << endl;
		system("timeout 5");
		exit(0);
	}
	if (shopadmauth == shopadmpw) {
		cout << "\nAuthorization Sucess, You will be redirect to Shop Administration Menu." << endl;
		system("timeout 5");
		system("cls");
		return shopadm();
	}
	else {
		counter = counter + 1;
		system("CLS");
		return shopauth();
	}
};

void shopadm() {
	int ch2;
	ini();
	counter = 0;
	cout << "***   Shop Administration Panel   ***\n" << endl;
	cout << " 1. Add New Item<s>" << endl;
	cout << " 2. Display Item Record<s>" << endl;
	cout << " 3. Search Item Information<s>" << endl;
	cout << " 4. Modify Item Information<s>" << endl;
	cout << " 5. Delete Item Record<s>" << endl;
	cout << "\n***   Administration Panel   ***\n" << endl;
	cout << " 6. Change Shop Administrator's Password" << endl;
	cout << "\n What is your option <1-6> ? || ";
	cin >> ch2;
	switch (ch2) {
	case 1:
		ret_counter = 1;
		add();
		break;
	case 2:
		display();
		break;
	case 3:
		search();
		break;
	case 4:
		modify();
		break;
	case 5:
		deleted();
		break;
	case 6:
		ret_counter = 1;
		csa2();
		break;
	case 7:
		csa2();
		break;
	default:
		cout << "No this option < " << ch2 << " >, < 1 - 6 > Only." << endl;
		system("timeout 5");
		return shopadm();
	}
};

void customerauth() {

};

void customer() {

};

/*Option 1 - 5 (Common Fuctions)*/

void add() {
	char data[100];
	char ch3;
	counter = 0;
	ini();
	cout << ">> Item additional Center\n" << endl;
starter:
	if (counter == 0) {
		cout << "IDF: 1> Item Name, 2> Category, 3> Quantity, 4> Weight 5> Recipient, 6> Final Destination, and 7> Delivery Ststus\n" << endl;
		cout << "Please enter : ";
		for (int i = 0; i < 7; i++) {
			cin >> data[i];
		}
		counter += 1;
		goto starter;
	}
	else {
		cout << "\nDo you want to add another item record (y/n) : ";
		cin >> ch3;
		if (ch3 == 'y' || ch3 == 'Y') {
			cout << "\nIDF: 1> Item Name, 2> Category, 3> Quantity, 4> Weight 5> Recipient, 6> Final Destination, and 7> Delivery Ststus\n" << endl;
			cout << "Please enter : ";
			for (int i = 0; i < 7; i++) {
				cin >> data[i];
			}
			counter += 1;
			goto starter;
		}
		else {
			cout << "\n You have total entered " << counter << " Item Records.\n" << endl;
		}

	}

	int length = strlen(data);

	ofstream save;
	save.open("stock.txt");
	for (int i = 0; i < length; i++) {
		if (data[i] == ' ') {
			printf("\n");
		}
		else {
			save << data[i] << endl;
			save.close();
		}
	}
};

void display() {

};

void search() {

};

void modify() {

};

void deleted() {
	/*string line, del = "3";
	ifstream fin;
	fin.open("pwd.dll");
	ofstream temp;
	temp.open("tmp.dll");
	while (getline(fin, line))
	{
		if (line != del) {
			temp << line << endl;
		}
	}
	temp.close();
	fin.close();
	remove("pwd.dll");
	rename("tmp.dll", "pwd.dll");*/
};

/*Option 6 - 9 (Optional Fuctions)*/

void csa() {
	ini();
	string spw, oldpw, conpw, newpw, pwcon, failmsg;

	fstream storage;
	storage.open("pwd.dll");
	getline(storage, spw);
	for (int i = 0; i < 1; i++) {
		getline(storage, spw);
	}
	getline(storage, spw);
	string spw2 = spw;
	storage.close();

	fstream admpwd;
	char pwd[] = "pwd.dll";
	admpwd.open(pwd);
	for (int i = 0; i < 0; i++) {
		getline(admpwd, oldpw);
	}
	getline(admpwd, oldpw);
	string oldsysadmpw = oldpw;
	admpwd.close();

	failmsg = (counter == 0) ? "System (SYS ADMIN) Login Center." : "Authorization Failure, Please try again.";

	cout << "Hello" << endl;
	cout << oldsysadmpw << " || " << endl;

	if (counter > 5) {
		cout << "\nError attemps lager than 5.\n" << endl;
		system("timeout 5");
		system("CLS");
		return sysadm();
	}
	system("cls");
	cout << "\n You have selected the option 6 : Change the Sys. Admin. Password.\n" << endl;
	cout << "*** Identification Authorization System ***\n" << endl;
	cout << failmsg << "\n" << endl;
	cout << "Error Counter: You still have " << 6 - counter << " chances." << endl;
	cout << "To prevent unknown edition of Sys. Admin. Password, PAUS established.\n" << endl;
	cout << "Please Enter the Old Administration Password: ";
	cin >> conpw;
	if (conpw == oldpw) {
		cout << "\n Authorization Sucess: \n" << endl;
		NEWADMPW:
		cout << "Please Enter the New Administration Password: ";
		cin >> newpw;
		cout << "\n Please Enter it again: ";
		cin >> pwcon;
		if (newpw != pwcon) {
			cout << "\nYou are required to Enter Again.\n" << endl;
			system("timeout 2");
			system("CLS");
			goto NEWADMPW;
		}
		ofstream pwd;
		pwd.open("pwd.dll");
		pwd << newpw << endl;
		pwd << spw2;
		pwd.close();
		cout << "\n Password Sucessful Changed!\n" << endl;
		system("timeout 5");
		system("CLS");
		return sysadm();
	}
	else {
		counter += 1;
		return csa();
	}
};

void csa2() {
	ini();
	string spw, oldpw, conpw, newpw, pwcon, failmsg;

	fstream storage;
	storage.open("pwd.dll");
	getline(storage, spw);
	for (int i = 0; i < 0; i++) {
		getline(storage, spw);
	}
	getline(storage, spw);
	string spw2 = spw;
	storage.close();

	fstream admpwd;
	char pwd[] = "pwd.dll";
	admpwd.open(pwd);
	for (int i = 0; i < 1; i++) {
		getline(admpwd, oldpw);
	}
	getline(admpwd, oldpw);
	string oldsysadmpw = oldpw;
	admpwd.close();

	failmsg = (counter == 0) ? "System (SHOP ADMIN) Login Center." : "Authorization Failure, Please try again.";

	cout << "Hello" << endl;
	cout << oldsysadmpw << " || " << endl;

	if (counter > 5) {
		cout << "\nError attemps lager than 5.\n" << endl;
		system("timeout 5");
		system("CLS");
		return sysadm();
	}
	system("cls");
	cout << "\n You have selected the option 6 : Change the Shop. Admin. Password.\n" << endl;
	cout << "*** Identification Authorization System ***\n" << endl;
	cout << failmsg << "\n" << endl;
	cout << "Error Counter: You still have " << 6 - counter << " chances." << endl;
	cout << "To prevent unknown edition of Sys. Admin. Password, PAUS established.\n" << endl;
	cout << "Please Enter the Old Administration Password: ";
	cin >> conpw;
	if (conpw == oldpw) {
		cout << "\n Authorization Sucess: \n" << endl;
	NEWADMPW:
		cout << "Please Enter the New Administration Password: ";
		cin >> newpw;
		cout << "\n Please Enter it again: ";
		cin >> pwcon;
		if (newpw != pwcon) {
			cout << "\nYou are required to Enter Again.\n" << endl;
			system("timeout 2");
			system("CLS");
			goto NEWADMPW;
		}
		ofstream pwd;
		pwd.open("pwd.dll");
		pwd << spw2 << endl;
		pwd << newpw;
		pwd.close();
		cout << "\n Password Sucessful Changed!\n" << endl;
		system("timeout 5");
		system("CLS");
		return sysadm();
	}
	else {
		counter += 1;
		return csa2();
	}
};

void emm() {

};

void etm() {

};

int main()
{
	add();
}
