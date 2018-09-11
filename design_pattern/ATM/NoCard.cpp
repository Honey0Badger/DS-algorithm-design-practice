#include "atm.hpp"

NoCard::NoCard(ATMMachine* ctx) {
	atm = ctx;
}

void NoCard::inputPin(ATMMachine* atm, int pin) {
	cout << "Please insert your card first!" << endl;
}

void NoCard::insertCard(ATMMachine* atm) {
	atm->state = getHaveCard();
	cout << "Card inserted..." << endl;
}

void NoCard::rejectCard(ATMMachine* atm) {
	cout << "No card inserted" << endl;
}

void NoCard::withdrawCash(ATMMachine* atm, int cash) {
	cout << "No card inserted, can't withdraw cash" << endl;
}

void NoCard::depositCash(ATMMachine* atm, int cash) {
	cout << "No card inserted, can't deposit cash" << endl;
}
