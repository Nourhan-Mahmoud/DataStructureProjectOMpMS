#include <string>
#include <iostream>
#include<fstream>
#include <list>
#include <sstream>
#include <algorithm>
//#include"Cart.cpp"
#include "Seller.cpp"
#include "Cart.cpp"

using namespace std;

struct prdt
{
	int id;
	string name;
	float price;
	string category;
	int sellerId;
	int quantity;
};

static Seller seller;
static Customer customer;

static list<prdt>listOfproducts;

class Products {

public:

	
	int productId = 0;

	void searchBycategory() {
		string cate;
		list <prdt> ::iterator it1;
		cin >> cate;
		for ( it1 = listOfproducts.begin(); it1 != listOfproducts.end(); ++it1) {
			if (it1->category == cate) {
				cout << "Product id: " << it1->id << endl <<
					"Product name: " << it1->name << endl <<
					"Product price: " << it1->price << " $ " << endl <<
					"Product category : " << it1->category << endl <<
					"product seller id: " << it1->sellerId << endl <<
					"Quantity : " << it1->quantity << endl;
			}
		}
	}

	prdt searchById() {
		int idid;
		prdt pp;
		cin >> idid;
		list <prdt> ::iterator it2;
		for ( it2 = listOfproducts.begin(); it2 != listOfproducts.end(); ++it2) {
			if (it2->id == idid) {
				pp.id = it2->id;
				pp.name = it2->name;
				pp.category = it2->category;
				pp.price = it2->price;
				pp.quantity = it2->quantity;//decrease the quatity when add to card //pp.quantity--;
				pp.sellerId = it2->sellerId;
				return pp;
			}

		}
	}

	void searchByname() {
		string name;
		cout << "Enter the name of product : ";
		cin >> name;
		list <prdt> ::iterator it3;
		for ( it3 = listOfproducts.begin(); it3 != listOfproducts.end(); ++it3) {

			for_each(name.begin(), name.end(), [](char& name) {
				name = ::tolower(name);
				});
			string itname = it3->name;
			for_each(itname.begin(), itname.end(), [](char& itname) {
				itname = ::tolower(itname);
				});

			if (itname == name) {
				cout << "Product id: " << it3->id << endl <<
					"Product name: " << it3->name << endl <<
					"Product price: " << it3->price << " $ " << endl <<
					"Product category : " << it3->category << endl <<
					"product seller id: " << it3->sellerId << endl <<
					"Quantity : " << it3->quantity << endl;
			}
		}
	}




	void addProduct() {
		int numOfpro = 1;
		cout << "Enter number of products you want to add : ";
		cin >> numOfpro;
		cout << endl << "***************************************************" << endl;
		for (int i = 0; i < numOfpro; i++) {
			prdt pp;
			pp.id = ++productId;
			cout << "Enter product name: ";
			cin >> pp.name;
			cout << "Enter product price: ";
			cin >> pp.price;
			cout << "Enter product category : ";
			cin >> pp.category;
			cout << "Enter product seller id: ";
			cin >> pp.sellerId;
			cout << "Enter product quantity: ";
			cin >> pp.quantity;
			cout << "***************************************************" << endl;
			listOfproducts.push_back(pp);
		}

	}

	void printAllProducts() {
		list <prdt> ::iterator it4;
		cout << "*****************************************************" << endl;
		for (  it4 = listOfproducts.begin(); it4 != listOfproducts.end(); ++it4) {
			cout << "Product id: " << it4->id << endl <<
				"Product name: " << it4->name << endl <<
				"Product price: " << it4->price << " $ " << endl <<
				"Product category : " << it4->category << endl <<
				"product seller id: " << it4->sellerId << endl <<
				"Quantity : " << it4->quantity << endl;
			cout << "*****************************************************" << endl;

		}
	}

	void returnAllinfoOfCart() {
		int total = 0;
		cout << "****************************** RECEIPT ********************************" << endl;
		for (auto displayCardit = listOfIds.begin(); displayCardit != listOfIds.end(); ++displayCardit) {
			for (auto pp = listOfproducts.begin(); pp != listOfproducts.end(); ++pp) {
				if (displayCardit == listOfIds.begin() && pp == listOfproducts.begin()) {
					cout << "Receipt id :  " << ++rec_id << endl;
					cout << "Customer id :  " << customer.returnCurrentCus() << endl;
				}
				if (displayCardit->id == pp->id) {
					cout << "Product Name :" << pp->name << "  ";
					cout << "Product price : " << pp->price << "  ";
					cout << "Product quanity :" << displayCardit->quantity << endl;
					pp->quantity -= displayCardit->quantity;
					total += (pp->price * displayCardit->quantity);
				}
			}

		}
		total += 30;
		cout << "Total Price For All Products :" << total;
	}

	void readFromFile() {
		ifstream file("productsFile.txt", ios::in);
		if (file.fail()) {
			file.open("productsFile.txt");
			return;
		}
		while (!file.eof())
		{
			prdt p;
			file >> p.id >> p.name >> p.price >> p.category >> p.sellerId >> p.quantity;
			listOfproducts.push_back(p);
		}

		file.close();
	}
	void writeInFile() {
		ofstream file;
		file.open("productsFile.txt", ios::out);
		int flag = 0;
		list <prdt> ::iterator it5;
		for ( it5 = listOfproducts.begin(); it5 != listOfproducts.end(); ++it5) {
			file << it5->id << endl << it5->name << endl << it5->price 
				<< endl << it5->category << endl << it5->sellerId << endl << it5->quantity;
			if (flag < listOfproducts.size() - 1) {
				file << endl;
			}flag++;
		}
		file.close();
	}

	list<prdt> returnTheList() {
		return listOfproducts;
	}

/*	void returnAllinfoOfCart() {
		int total = 0;
		cout << "****************************** RECEIPT ********************************" << endl;
		for (auto displayCardit = listOfIds.begin(); displayCardit != listOfIds.end(); ++displayCardit) {
			for (auto pp = listOfproducts.begin(); pp != listOfproducts.end(); ++pp) {
				if (displayCardit == listOfIds.begin() && pp == listOfproducts.begin()) {
					cout << "Receipt id :  " << ++rec_id << endl;
					cout << "Customer id :  " << customer.returnCurrentCus() << endl;
				}
				if (displayCardit->id == pp->id) {
					cout << "Product Name :" << pp->name << "  ";
					cout << "Product price : " << pp->price << "  ";
					cout << "Product quanity :" << displayCardit->quantity << endl;
					pp->quantity -= displayCardit->quantity;
					total += (pp->price * displayCardit->quantity);
				}
			}

		}
		total += 30;
		cout << "Total Price For All Products :" << total;
	}
	*/
};
