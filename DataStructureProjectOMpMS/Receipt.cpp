
#include <iostream>
#include <iterator>
#include <list>
//#include "Customer.cpp"
#include "Products.cpp"


using namespace std;




static Products products;


class Receipt
{
public:

	struct info {
		int rece_id;
		int cust_id;
		float total_price;
		string name;
		float price;
		int quantity;
	};
	list<info>receiptInfo;
	
/*
void displayReceipt() {


		cout << "enter F ";
		//list <prdt> ::iterator it1;
		// <order> ::iterator i;
		vector <order>listOfIdsFromCart;
		vector<prdt>Productsinfo;
		cout << "enter F2";
		//listOfIdsFromCart.reserve(listOfIdsFromCart.size() + (cart.returnListInCart().size()*2));
		//Productsinfo.reserve(Productsinfo.size() +( products.returnTheList().size()*2));
		//std::copy(listOfIdsFromCart.begin(), listOfIdsFromCart.end(), std::back_inserter(cart.returnListInCart()));
		listOfIdsFromCart.insert(listOfIdsFromCart.end(), cart.returnListInCart().begin(), cart.returnListInCart().end());
		Productsinfo.insert(Productsinfo.end(), products.returnTheList().begin(), products.returnTheList().end());
		info f;
		f.rece_id = f.rece_id + 1;
		f.cust_id = customer.current_cust;

		cout << "enter";

		for (auto i = listOfIdsFromCart.begin(); i != listOfIdsFromCart.end(); ++i) {
			for (auto it1 = Productsinfo.begin(); it1 != Productsinfo.end(); ++it1)
			{
				if (i->id == it1->id) {
					f.name = it1->name;
					f.price = it1->price;
					f.quantity = i->quantity;
					f.total_price = f.total_price + (f.price * f.quantity);
					receiptInfo.push_back(f);
				}
			}

		}


		int arrId[10];
		int arrQuan[10];
		int ii = 0;
		for (i = listOfIdsFromCart.begin(); i != listOfIdsFromCart.end(); ++i) {
			arrId[ii] = i->id;
			arrQuan[ii] = i->quantity;
			ii++;
		}

		int iii = 0;
		for (it1 = Productsinfo.begin(); it1 != Productsinfo.end(); ++it1)
		{
			if (it1->id == arrId[iii]) {
				f.name = it1->name;
				f.price = it1->price;
				f.quantity = arrQuan[iii];
				f.total_price = f.total_price + (f.price * f.quantity);
				receiptInfo.push_back(f);
			}
			iii++;
		}
		
		
		cout << "****************************** RECEIPT ********************************" << endl;
		//list <info> ::iterator j;
		float total = 0;
		for (auto j = receiptInfo.begin(); j != receiptInfo.end(); ++j)
		{
			if (j == receiptInfo.begin())
			{
				cout << "Receipt id :  " << j->rece_id << endl;
				cout << "Customer id :  " << j->cust_id << endl;
			}
			cout << "Product Name :" << j->name <<"  ";
			cout << "Product price : " << j->price<< "  ";
			cout << "Product quanity :" << j->quantity << endl;
			cart.returnAllinfoOfCart();
			total = j->total_price;
		}

		cout << "Total price : " << total << endl;
		cout << "Total price with shipment : " << total + 30 << endl;
		cout << "*************************************************************************" << endl;
		
		
	}

*/




};










