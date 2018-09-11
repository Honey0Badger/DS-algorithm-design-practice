#include "atm.hpp"

void HaveCard::inputPin(ATMMachine* atm, int pin) {
	if (pin == 1234) {
		cout << "log into account..." << endl;
		atm->state = atm->getCorrectPin();
	}
	else {
		cout << "Incorrect pin..." << endl;
	}
}

void HaveCard::insertCard(ATMMachine* atm) {
	cout << "Card already inserted..." << endl;
}

void HaveCard::rejectCard(ATMMachine* atm) {
	cout << "Rejecting card..." << endl;
	atm->state = atm->getNoCard();
}

void HaveCard::withdrawCash(ATMMachine* atm, int cash) {
	cout << "Need to input pin first..." << endl;
}

void HaveCard::depositCash(ATMMachine* atm, int cash) {
	cout << "Need to input pin first..." << endl;
}
