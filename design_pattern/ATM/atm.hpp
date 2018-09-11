#pragma once

class AtmState {
    public:
		virtual ~AtmState(){}
        virtual void inputPin(ATMMachine* atm, int) = 0;
        virtual void insertCard(ATMMachine* atm) = 0;
        virtual void rejectCard(ATMMachine* atm) = 0;
        virtual void withdrawCash(ATMMachine* atm, int) = 0;
		virtual void depositCash(ATMMachine* atm, int) = 0;
};

class ATMMachine {
	public:
		ATMMachine();
		~ATMMachine();
        void inputPin(int);
        void insertCard();
        void rejectCard();
        void withdrawCash(int);
		void depositCash(int);

		AtmState* getNoCard() const;
		AtmState* getHaveCard() const;
		AtmState* getCorrectPin() const;
		AtmState* getNotEnoughCash() const;
		int getCash() const;
		void setNoCard();
		void setHaveCard();
		void setCorrectPin();
		void setNotEnoughCash();
		void setCash(int);
		void setPinstate(bool);
		

	private:
		bool correctPin;
		int cash;
        AtmState* state;
		NoCard st_nocard;
		HaveCard st_havecard;
		CorrectPin st_correctpin;
		NotEnoughCash st_notenoughcash;
        
};

class NoCard {
    public:
		NoCard(ATMMachine*);
        void inputPin(ATMMachine* atm, int);
        void insertCard(ATMMachine* atm);
        void rejectCard(ATMMachine* atm);
        void withdrawCash(ATMMachine* atm, int);
		void depositCash(ATMMachine* atm, int);
	private:
		ATMMachine* atm;
};

class HaveCard {
    public:
		HaveCard(ATMMachine*);
        void inputPin(ATMMachine* atm, int);
        void insertCard(ATMMachine* atm);
        void rejectCard(ATMMachine* atm);
        void withdrawCash(ATMMachine* atm, int);
		void depositCash(ATMMachine* atm, int);
	private:
		ATMMachine* atm;
};

class CorrectPin {
    public:
		CorrectPin(ATMMachine*);
        void inputPin(ATMMachine* atm, int);
        void insertCard(ATMMachine* atm);
        void rejectCard(ATMMachine* atm);
        void withdrawCash(ATMMachine* atm, int);
		void depositCash(ATMMachine* atm, int);
	private:
		ATMMachine* atm;
};

class NotEnoughCash {
    public:
        void inputPin(ATMMachine* atm, int);
        void insertCard(ATMMachine* atm);
        void rejectCard(ATMMachine* atm);
        void withdrawCash(ATMMachine* atm, int);
		void depositCash(ATMMachine* atm, int);
	private:
		ATMMachine* atm;
};
