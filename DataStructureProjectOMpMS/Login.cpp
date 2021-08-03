
/*#include <iostream>
#include "Customer.cpp"
using namespace std;
class Login
{
public:
	struct loginInfo {
		int idForLog;
		string passwordForLog;
	};

	loginInfo logInForCS;

	void EnterLoginInfo() {
		cout << "******************* LOGIN **********************" << endl;
		cout << "Enter Your ID  : ";
		cin >> logInForCS.idForLog;
		cout << "Enter Your PASSWORD  : ";
		cin >> logInForCS.passwordForLog;
		cout << "************************************************" << endl;
	}

	void checkLoginInfoForCustomer() {
		int counter = 0;
		

		for (auto itForLogin1 = customer.returnCustList().begin(); itForLogin1 != customer.returnCustList().end(); itForLogin1++) {
			if (itForLogin1->id == logInForCS.idForLog && itForLogin1->password == logInForCS.passwordForLog) {
				counter++;
			}

		}

		if (counter < 1) {
			cout << "***Invalid Id or Password***" << endl;
			checkLoginInfoForCustomer();
		}


	}

	void checkLoginInfoForSeller() {
		int counterSeller = 0;
		
		for (auto itForLogin2 = seller.returnSellerList().begin(); itForLogin2 != seller.returnSellerList().end(); itForLogin2++) {
			if (itForLogin2->id == logInForCS.idForLog && itForLogin2->password == logInForCS.passwordForLog) {
				counterSeller++;
			}
		}

		if (counterSeller < 1) {
			cout << "***Invalid Id or Password***" << endl;
			checkLoginInfoForSeller();
		}

	}



};*/
