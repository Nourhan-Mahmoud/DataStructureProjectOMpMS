#include <string>
#include <iostream>
#include<fstream>
#include <list>
#include <sstream>
#include <algorithm>
//#include "Login.cpp"
using namespace std;


class Seller {

public:
	struct sellerinfo {
		string name;
		int id;
		string e_mail;
		string address;
		string phoneNumber;
		string password;

	};
	list<sellerinfo>listofseller;

	int id__;
	string pass__;

	void EnterLoginInfoSeller() {
		cout << "******************* LOGIN **********************" << endl;
		cout << "Enter Your ID  : ";
		cin >> id__;
		cout << "Enter Your PASSWORD  : ";
		cin >> pass__;
		cout << "************************************************" << endl;
		int counterSeller = 0;

		for (auto itForLogin2 = listofseller.begin(); itForLogin2 != listofseller.end(); itForLogin2++) {
			if (itForLogin2->id == id__ && itForLogin2->password == pass__) {
				counterSeller++;
			}
		}

		if (counterSeller < 1) {
			cout << "***Invalid Id or Password***" << endl;
			EnterLoginInfoSeller();
		}
	}


	list<sellerinfo> returnSellerList() {
		return listofseller;
	}

	void sellerRigester() {

		sellerinfo s;

		cout << "*********** Custmor Registeration ************\n";
		cout << "Enter your name :-without spaces, please-" << endl;;
		cin >> s.name;
		cout << "Enter id : " << endl;
		cin >> s.id;
		cout << "Enter your email :-EX:customar_name@onlineMarket.com- " << endl;
		cin >> s.e_mail;
		cout << "Enter your adress : " << endl;
		cin >> s.address;
		cout << "Enter your phoneNumber : " << endl;
		cin >> s.phoneNumber;
		cout << "Enter a password : " << endl;
		cin >> s.password;
		listofseller.push_back(s);
		EnterLoginInfoSeller();


	}



	void readFromFile() {
		ifstream file("sellerfile.txt", ios::in);
		if (file.fail()) {
			file.open("sellerfile.txt");
			return;
		}
		while (!file.eof())
		{
			sellerinfo s;
			file >> s.name >> s.id >> s.e_mail >> s.address >> s.phoneNumber >> s.password;;
			listofseller.push_back(s);
		}

		file.close();
	}



	void writeInFile() {
		ofstream file;
		file.open("sellerfile.txt", ios::out);
		int flag = 0;
		list <sellerinfo> ::iterator it;
		for ( auto it = listofseller.begin(); it != listofseller.end(); ++it) {
			file << it->name << endl << it->id << endl << it->address << endl << it->phoneNumber
				<< endl << it->password;
			if (flag < listofseller.size() - 1) {
				file << endl;
			}flag++;
		}
		file.close();
	}


};