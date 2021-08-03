#include <string>
#include <list>
#include <iostream>
#include <fstream>
//#include "Seller.cpp"
//#include "Products.cpp"
//#include "Cart.cpp"
using namespace std;

static int current_cust = 0;

class Customer
{
public:
	

	inline  struct customarInforamtion {
		string name;
		int id;
		string e_mail;
		string address;
		string phoneNumber;
		string password;
	};
	list<customarInforamtion>cusInfo;
	customarInforamtion c;

	
	int id_;
	string pass_;

	inline  void EnterLoginInfoCustomer() {
		cout << "******************* LOGIN **********************" << endl;
		cout << "Enter Your ID  : ";
		cin >> id_;
		cout << "Enter Your PASSWORD  : ";
		cin >> pass_;
		cout << "************************************************" << endl;
		int counter = 0;
		for (auto itForLogin1 = cusInfo.begin(); itForLogin1 != cusInfo.end(); itForLogin1++) {
			if (itForLogin1->id == id_ && itForLogin1->password == pass_) {
				counter++;
			}

		}

		if (counter < 1) {
			cout << "***Invalid Id or Password***" << endl;
			EnterLoginInfoCustomer();
		}
	}
	


	void customerRegister()
	{
		//customarInforamtion c;

		cout << "*********** Custmor Registeration ************\n";
		cout << "Enter your name :-without spaces, please-" << endl;
		cin >> c.name;
		c.id = c.id++;
		//cout << "Enter your id : " << endl;
		//cin >> c.id;
		current_cust = c.id;
		cout << c.id;
		cout << "Enter your email :-EX:customar_name@onlineMarket.com- " << endl;
		cin >> c.e_mail;
		cout << "Enter your adress : " << endl;
		cin >> c.address;
		cout << "Enter your phoneNumber : " << endl;
		cin >> c.phoneNumber;
		cout << "Enter a password : " << endl;
		cin >> c.password;
		cusInfo.push_back(c);
		EnterLoginInfoCustomer();
	}

	list<customarInforamtion> returnCustList() {
		return cusInfo;
	}

	int returnCurrentCus() {
		return current_cust;
	}


	void readFromFileC() {
		ifstream file("customerRigesterFile.txt", ios::in);
		if (file.fail()) {
			file.open("customerRigesterFile.txt");
			return;
		}
		while (!file.eof())
		{
			//customarInforamtion c;
			file >> c.name >> c.id >> c.e_mail >> c.address >> c.phoneNumber >> c.password;
			cusInfo.push_back(c);
		}

		file.close();
	}

	void writeInFileC() {
		ofstream file;
		file.open("customerRigesterFile.txt", ios::out);
		int flag = 0;
		list <customarInforamtion> ::iterator it;
		for ( it = cusInfo.begin(); it != cusInfo.end(); ++it) {
			file << it->name << endl << it->id << endl << it->address << endl << it->phoneNumber
				<< endl << it->password;
			if (flag < cusInfo.size() - 1) {
				file << endl;
			}flag++;
		}
		file.close();
	}
};
