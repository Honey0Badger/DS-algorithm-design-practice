#include<stdlib>

#include "atm.hpp"

ATMMachine::ATMMachine():correctPin(false), 
						 cash(10000), // initial cash in the atm
						 st_nocard(this),
						 st_havecard(this),
						 st_correctpin(this),
						 st_notenoughcash(this)
{
	state = &st_nocard;
}

~ATMMachine::ATMMachine() {
}

void ATMMachine::inputPin(int pin) {
	state->inputPin(this, pin);
}

void ATMMachine::insertCard() {
	state->insertCard(this, pin);
}

void ATMMachine::rejectCard() {
	state->rejectCard(this, pin);
}

void ATMMachine::withdrawCash(int cash) {
	state->withdrawCash(this, cash);
}

void ATMMachine::depositCash(int cash) {
	state->depositCash(this, cash);
}

AtmState* ATMMachine::getNoCard() const {
	return &st_nocard;
}

AtmState* ATMMachine::getHaveCard() const {
	return &st_havecard;
}

AtmState* ATMMachine::getCorrectPin() const {
	return &st_correctpin;
}

AtmState* ATMMachine::getNotEnoughCash() const {
	return &st_notenoughcash;
}
		
int getCash() const {
	return cash;
}

void setNoCard() {
	state = &st_nocard;
}

void setHaveCard() {
	state = &st_havecard;
}

void setCorrectPin() {
	state = &st_correctpin;
}

void setNotEnoughCash() {
	state = &st_notenoughcash;
}

void setCash(int money) {
 	cash = money;
}

void setPinstate(bool pinstate) {
	correctPin = pinstate;
}
