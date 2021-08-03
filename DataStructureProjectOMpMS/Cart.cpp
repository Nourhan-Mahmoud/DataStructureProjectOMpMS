
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
//#include "Products.cpp"
#include "Customer.cpp"
using namespace std;

 struct order {
	int id;
	int quantity;
};
static list<order>listOfIds;

//Products p;
//Customer cus;
//static Seller seller;
//static Customer customer;
//static Products products;
//
static int rec_id = 0;
class Cart
{
public:
	
	
	void addProductToCart() {
		int numOfproductsForAdd;
		cout << "Enter the number of products that you want to add to the cart : ";
		cin >> numOfproductsForAdd;
		for (int i = 0; i < numOfproductsForAdd; i++) {
			cout << "Enter product id that you want to add to cart :  ";
			order o;
			cin >> o.id;
			cout << "Enter the quantity of the product you want :  ";
			cin >> o.quantity;
			listOfIds.push_back(o);
		}
	}

	void removeProductFromCart() {
		int numOfproductsForRemove;
		cout << "Enter the number of products that you want to remove from the cart : ";
		cin >> numOfproductsForRemove;
		for (int i = 0; i < numOfproductsForRemove; i++) {
			cout << "Enter the id of the product you want to remove : ";
			int id;
			cin >> id;
			//vector <order> ::iterator it;
			for (auto it = listOfIds.begin(); it != listOfIds.end(); ++it) {
				if (id == it->id) {
					//listOfIds.remove(it);
				}
			}

		}
	}

	void displayCart() {
		//list <order> ::iterator displayCardit;
		cout << "************************************************************" << endl;
		for (auto displayCardit = listOfIds.begin(); displayCardit != listOfIds.end(); ++displayCardit) {
			cout << " ID : " << displayCardit->id << endl;
			cout << "Quantity : " << displayCardit->quantity << endl;
			cout << "_______________________________________________" << endl;
		}
	}

	list<order> returnListInCart() {
		return listOfIds;
	}

	/*void returnAllinfoOfCart() {
		int total = 0;
		cout << "****************************** RECEIPT ********************************" << endl;
		for (auto displayCardit = listOfIds.begin(); displayCardit != listOfIds.end(); ++displayCardit) {
			for (auto pp = products.returnTheList().begin(); pp != products.returnTheList().end(); ++pp) {
				if (displayCardit == listOfIds.begin() && pp == products.returnTheList().begin()) {
					cout << "Receipt id :  " << ++rec_id << endl;
					cout << "Customer id :  " << customer.returnCurrentCus() << endl;
				}
				if (displayCardit->id == pp->id) {
					cout << "Product Name :" << pp->name << "  ";
					cout << "Product price : " << pp->price << "  ";
					cout << "Product quanity :" << displayCardit->quantity << endl;
					pp->quantity -= displayCardit->quantity;
					total += (pp->price* displayCardit->quantity);
				}
			}
			
		}
		total += 30;
		cout << "Total Price For All Products :" << total;
	}*/

};


