#pragma once
#include "Money.h"
#include <string>
using namespace std;

class Account : public Money
{
private:
	string secondname;
	int no;
	double percent;
public:
	string getSecondame() const { return secondname; }
	int getNo() const { return no; }
	double getPercent() const { return percent; }

	Account();
	Account(int, double);
	Account(const Account&);

	Account& operator =(const Account&);
	operator string() const;

	friend ostream& operator <<(ostream&, const Account&);
	friend istream& operator >>(istream&, Account&);

	void setSecondname(string);
	bool setNo(int);
	bool setPercent(double);
	void setSumma();

	double Total(const Account&);

	void ChangeOwner();
	void GetMoney();
	void AddMoney();
	Account MakePercent(Account&);
	Account ToDollar(Account&);
	Account ToEuro(Account&);
	void Propys();

	Account Add(const Account&, const Account&, Account&);
	Account Subtract(const Account&, const Account&, Account&);
	Account Multiply(Account&, const double);
	Account Division(Account&, const double);
	Account DivOfSums(const Account&, const Account&, Account&);
	Account Change(int, int, Account&);
	friend bool operator < (Account x, Account y);
	friend bool operator <= (Account x, Account y);
	friend bool operator > (Account x, Account y);
	friend bool operator >=(Account x, Account y);
	friend bool operator == (Account x, Account y);
	friend bool operator != (Account x, Account y);
};

