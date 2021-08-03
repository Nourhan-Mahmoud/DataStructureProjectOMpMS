// DataStructureProjectOMpMS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "Seller.cpp"
#include "Receipt.cpp"
//#include "Products.cpp"
//#include "Cart.cpp"
//#include "Login.cpp"
using namespace std;

static Cart cart;
int op_searchProd;
char ans;

void sellerChoice() {

	seller.sellerRigester();
	cout << "__________________________________________________" << endl;
	products.addProduct();
	cout << "__________________________________________________" << endl;
	products.printAllProducts();

}

void customerChoice(char ans) {

	customer.customerRegister();
	//customer.EnterLoginInfoCustomer();

}

void customerOp_searchProd() {
	cin >> op_searchProd;
	if (op_searchProd == 1)
	{
		products.printAllProducts();
	}
	else if (op_searchProd == 2)
	{
		products.searchByname();

	}
	else if (op_searchProd == 3)
	{
		products.searchBycategory();
	}
	if (op_searchProd != 1 && op_searchProd != 2 && op_searchProd != 3)
	{
		cout << "invalid number.. please enter 1 or 2 or 3.." << endl;
		customerOp_searchProd();
	}
}

void loginOrRedister() {
	int c;
	cin >> c;
	if (c == 2) {
		if (ans == 's' || ans == 'S') {
			
			sellerChoice();
		}
		else if (ans == 'C' || ans == 'c') {
			customerChoice(ans);
		}
	}
	else if (c == 1) {
		if (ans == 's' || ans == 'S') {
			seller.EnterLoginInfoSeller();

		}
		else if (ans == 'C' || ans == 'c') {
			customer.EnterLoginInfoCustomer();
		}
	}
	
}

void main()
{
	products.readFromFile();
	customer.readFromFileC();
	seller.readFromFile();
	

	char x;
	do {
		cout << " ARE YOU SELLER OR CUSTOMER ?" << endl;
		cout << "press 's' for seller\npress 'c' for customer \n";

		cin >> ans;
		if (ans == 's' || ans == 'S') {
			cout << "1-Login    2-Register  " << endl;
			cout << "enter selected number :";
			loginOrRedister();
			sellerChoice();

		}
		else if (ans == 'C' || ans == 'c') {
			cout << "1-Login    2-Register  " << endl;
			cout << "enter selected number :";
			loginOrRedister();

			cout << "if you want see all products enter 1" << endl;
			cout << "if you want to search about certain product by name enter 2" << endl;
			cout << "if you want search about certain category enter 3" << endl;
			customerOp_searchProd();

			int ans_cust;
			cout << "if you want to buy any product, enter 1.. " << endl;
			cout << "if you want to go to home, enter 2.. " << endl;
			cout << "if you want to log out, enter 3.. " << endl;
			cin >> ans_cust;

			if (ans_cust == 1)
			{
				int displayCart, confirmBuying;
				cart.addProductToCart();
				cout << "Are you finish? enter 1 to display your cart.." << endl;
				cin >> displayCart;
				if (displayCart == 1)
				{
					//cart
					cart.displayCart();
					cout << "Are you confirm buying? enter 1 to confirm.. " << endl;
					cin >> confirmBuying;
					if (confirmBuying == 1)
					{
						products.returnAllinfoOfCart();
					}

				}

			}

		}
		cout <<endl<< " if you want to Go to the Start -press * y *-" << endl;
		cin >> x;
	} while (x == 'y' || x == 'Y');
	

	
	
	
	products.writeInFile();
	customer.writeInFileC();
	seller.writeInFile();

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
