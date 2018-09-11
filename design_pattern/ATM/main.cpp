#include<iostream>
#include "atm.hpp"

use namespace std;

int main() {
	ATMMachine atm0;
	atm0.insertCard();
	cout << "input pin:" << endl;
	int pin=0;
	cin >> pin;
	atm0.inputPin(pin);
	atm0.withdrawCash(2000);
	atm0.depositCash(500);
	atm0.withdrawCash(4000);
	return 0;
}
