#include "atm.hpp"

void HaveCard::inputPin(ATMMachine* atm, int pin) {
		cout << "Already logged in" << endl;
}

void HaveCard::insertCard(ATMMachine* atm) {
	cout << "Card already inserted..." << endl;
}

void HaveCard::rejectCard(ATMMachine* atm) {
	cout << "Rejecting card..." << endl;
	atm->state = atm->getNoCard();
}

void HaveCard::withdrawCash(ATMMachine* atm, int cash) {
	if (atm->cash >= cash) {
		cout << atm->cash << " cash withdrawed" << endl;
		atm
}

void HaveCard::depositCash(ATMMachine* atm, int cash) {
	cout << "Need to input pin first..." << endl;
}
