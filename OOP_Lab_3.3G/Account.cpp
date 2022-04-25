#include "Account.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <math.h>
using namespace std;

void Account::setSecondname(string value)
{
	secondname = value;
}

bool Account::setNo(int value)
{
	if (value > 0)
	{
		no = value;
		return true;
	}
	else
	{
		no = 0;
		return false;
	}
}

bool Account::setPercent(double value)
{
	if (value > 0)
	{
		percent = value;
		return true;
	}
	else
	{
		percent = -value;
		return false;
	}
}

void Account::setSumma()
{
	int h500, h200, h100, h50, h20, h10, h5, h2, h1, c50, c25, c10, c5, c2, c1;
	do {
		cout << "¬еед≥ть к≥льк≥сть кожноњ купюри:" << endl;
		cout << "500 = "; cin >> h500;
		cout << "200 = "; cin >> h200;
		cout << "100 = "; cin >> h100;
		cout << "50 = "; cin >> h50;
		cout << "20 = "; cin >> h20;
		cout << "10 = "; cin >> h10;
		cout << "5 = "; cin >> h5;
		cout << "2 = "; cin >> h2;
		cout << "1 = "; cin >> h1;
		cout << "0.50 = "; cin >> c50;
		cout << "0.25 = "; cin >> c25;
		cout << "0.10 = "; cin >> c10;
		cout << "0.5 = "; cin >> c5;
		cout << "0.02 = "; cin >> c2;
		cout << "0.01 = "; cin >> c1;
	} while ((h500 || h200 || h100 || h50 || h20 || h10 || h5 || h2 ||
		h1 || c50 || c25 || c10 || c5 || c2 || c1) < 0);
	setH500(h500);
	setH200(h200);
	setH100(h100);
	setH50(h50);
	setH20(h20);
	setH10(h10);
	setH5(h5);
	setH2(h2);
	setH1(h1);
	setC50(c50);
	setC25(c25);
	setC10(c10);
	setC5(c5);
	setC2(c2);
	setC1(c1);
}

Account::Account()
{
	setNo(0);
	setPercent(0);
}
Account::Account(int no, double percent)
{
	setNo(no);
	setPercent(percent);
}
Account::Account(const Account& a)
{
	setNo(a.getNo());
	setPercent(a.getPercent());
}

ostream& operator <<(ostream& out, const Account& x)
{
	out << (string)x;
	return out;
}
istream& operator >>(istream& in, Account& x)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "¬вед≥ть номер банк≥вського рахунку: "; in >> x.no;
	cout << "¬вед≥ть пр≥звище власника: "; in >> x.secondname;

	return in;
}
Account& Account::operator =(const Account& r)
{
	secondname = r.secondname;
	percent = r.percent;
	no = r.no;
	setH500(r.getH500());
	setH200(r.getH200());
	setH100(r.getH100());
	setH50(r.getH50());
	setH20(r.getH20());
	setH10(r.getH10());
	setH5(r.getH5());
	setH2(r.getH2());
	setH1(r.getH1());
	setC50(r.getC50());
	setC25(r.getC25());
	setC10(r.getC10());
	setC5(r.getC5());
	setC2(r.getC2());
	setC1(r.getC1());
	return *this;
}
Account::operator string() const
{
	stringstream ss;
	ss << "----------------------------------------------------------------------------\n";
	ss << "|500h|200h|100h| 50h| 20h| 10h|  5h|  2h|  1h| 50c| 25c| 10c|  5c|  2c|  1c|\n";
	ss << "----------------------------------------------------------------------------\n";
	ss << "|" << setw(4) << getH500() << "|" << setw(4) << getH200() << "|" << setw(4) << getH100() << "|" <<
		setw(4) << getH50() << "|" << setw(4) << getH20() << "|" << setw(4) << getH10() << "|" << setw(4) <<
		getH5() << "|" << setw(4) << getH2() << "|" << setw(4) << getH1() << "|" << setw(4) << getC50() <<
		"|" << setw(4) << getC25() << "|" << setw(4) << getC10() << "|" << setw(4) << getC5() << "|" <<
		setw(4) << getC2() << "|" << setw(4) << getC1() << "|\n" <<
		"----------------------------------------------------------------------------\n";

	int a = getH500() * 500 + getH200() * 200 + getH100() * 100 +
		getH50() * 50 + getH20() * 20 + getH10() * 10 + getH5() * 5 + getH2() * 2 + getH1();
	int b = getC50() * 50 + getC25() * 25 + getC10() * 10 + getC5() * 5 + getC2() * 2 + getC1();
	while (b >= 100)
	{
		b -= 100;
		a += 1;
	}
	if (b < 10)
		ss << "Sum = " << a << ",0" << b << endl;
	else
		ss << "Sum = " << a << "," << b << endl;

	return ss.str();
}

void Account::ChangeOwner()
{
	cin >> *this;
	setSumma();
	setPercent(5);
}

void Account::GetMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "—к≥льки грошей ви бажаЇте зн€ти?" << endl;
		cout << "[1] - 500 грн." << endl;
		cout << "[2] - 200 грн" << endl;
		cout << "[3] - 100 грн" << endl;
		cout << "[4] - 50 грн" << endl;
		cout << "[5] - 20 грн" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			setH500(getH500() - 1);
			cout << "¬и усп≥шно зн€ли 500 гривень" << endl;
			break;
		case 2:
			setH200(getH200() - 1);
			cout << "¬и усп≥шно зн€ли 200 гривень" << endl;
			break;
		case 3:
			setH100(getH100() - 1);
			cout << "¬и усп≥шно зн€ли 100 гривень" << endl;
			break;
		case 4:
			setH50(getH50() - 1);
			cout << "¬и усп≥шно зн€ли 50 гривень" << endl;
			break;
		case 5:
			setH20(getH20() - 1);
			cout << "¬и усп≥шно зн€ли 20 гривень" << endl;
		}
		break;
		cout << endl;
	} while (no != 6);
}

void Account::AddMoney()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int no;
	do {
		cout << "—к≥льки грошей ви бажаЇте покласти на рахунок?" << endl;
		cout << "[1] - 500 грн." << endl;
		cout << "[2] - 200 грн" << endl;
		cout << "[3] - 100 грн" << endl;
		cout << "[4] - 50 грн" << endl;
		cout << "[5] - 20 грн" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			setH500(getH500() + 1);
			cout << "¬и усп≥шно поклали 500 гривень" << endl;
			break;
		case 2:
			setH200(getH200() + 1);
			cout << "¬и усп≥шно поклали 200 гривень" << endl;
			break;
		case 3:
			setH100(getH100() + 1);
			cout << "¬и усп≥шно поклали 100 гривень" << endl;
			break;
		case 4:
			setH50(getH50() + 1);
			cout << "¬и усп≥шно поклали 50 гривень" << endl;
			break;
		case 5:
			setH20(getH20() + 1);
			cout << "¬и усп≥шно поклали 20 гривень" << endl;
		}
		break;
		cout << endl;
	} while (no != 6);
}

Account Account::MakePercent(Account& a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	sum = Money::Total();
	int no;
	do {
		cout << "¬и справд≥ бажаЇте нарахувати " << percent << "% на ваш баланс?" << endl;
		cout << "[1] - “ак" << endl;
		cout << "[2] - Ќ≥" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * (percent / 100);
			cout << "¬и усп≥шно нарахували в≥дсотки!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin, a);
	return a;
}

Account Account::ToDollar(Account& a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int no;
	do {
		cout << "¬и справд≥ бажаЇте перевести " << Money::Total() << "грн. у доллари?" << endl;
		cout << "[1] - “ак" << endl;
		cout << "[2] - Ќ≥" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * 0.033;
			cout << "¬и усп≥шно перевели грош≥ у доллари!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin, a);
	return a;
}

Account Account::ToEuro(Account& a)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double sum = 0;
	int no;
	do {
		cout << "¬и справд≥ бажаЇте перевести " << Money::Total() << "грн. у Ївро?" << endl;
		cout << "[1] - “ак" << endl;
		cout << "[2] - Ќ≥" << endl;
		cout << "¬вед≥ть значенн€: "; cin >> no;
		cout << endl;

		switch (no)
		case 1:
		{
			sum += sum * 0.030;
			cout << "¬и усп≥шно перевели грош≥ у Ївро!" << endl;
		}
		break;
		cout << endl;
	} while (no != 2);

	int hrn = (int)sum;
	int coin = (floor((sum - hrn) * 100 + 0.501));

	Change(hrn, coin, a);
	return a;
}

void Account::Propys()
{
	double x = Money::Total();
	double frac = 0;
	double integral = 0;
	frac = modf(x, &integral);
	int numb = (int)integral;

	int osn[11] = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

	string basis[11][10] = {
		{"","","","","","","","","",""},
		{"","один","два","три","чотири","п'€ть","ш≥сть","с≥м","в≥с≥м","дев€ть"},
		{"","дес€ть","двадц€ть","тридц€ть","сорок","п'€тдес€т","ш≥стдес€т","с≥мдес€т","в≥с≥мдес€т","дев'€носто"},
		{"","сто","дв≥ст≥","триста","четириста","п'€тсот","ш≥стсот","с≥мсот","в≥с≥мсот","дев'€тсот"},
		{"","одна","дв≥","три","чотири","п'€ть","ш≥сть","с≥м","в≥с≥м","дев'€ть"},
		{"","дес€ть","двадц€ть","тридц€ть","сорок","п'€тдес€т","ш≥стдес€т","с≥мдес€т","в≥с≥мдес€т","дев'€носто"},
		{"","сто","дв≥ст≥","триста","чотириста","п'€тсот","ш≥стсот","семсот","в≥с≥мсот","дев'€тсот"},
		{"","один","два","три","четире","п'€ть","ш≥сть","с≥м","в≥с≥м","дев'€ть"},
		{"","дес€ть","двадц€ть","тридц€ть","сорок","п'€тдес€т","ш≥стьдес€т","с≥мдес€т","в≥с≥мдес€т","дев'€носто"},
		{"","сто","дв≥ст≥","триста","чотириста","п'€тсот","ш≥стсот","с≥мсот","в≥с≥мсот","дев'€тсот"},
		{"","один","два","три ","чотири","п'€ть","ш≥сть","с≥м","в≥с≥м","дев'€ть"} };


	string termination[10][10] = {
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ча","","","м≥льйон","","","м≥ль€рд"},
		{"","","","тис€ч≥","","","м≥льйона","","","м≥ль€рда"},
		{"","","","тис€ч≥","","","м≥льйона","","","м≥ль€рда"},
		{"","","","тис€ч≥","","","м≥льйона","","","м≥ль€рда"},
		{"","","","тис€ч","","","м≥льйона","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"},
		{"","","","тис€ч","","","м≥льйон≥в","","","м≥ль€рд≥в"} };

	string dec[10] = { "дес€ть","одинадц€ть","дванадц€ть","тринадц€ть","чотирнадц€ть","п'€тнадц€ть","ш≥стнадц€ть","с≥мнадц€ть","в≥с≥мнадц€ть","дев'€тнадц€ть" };
	string result;

	if (!numb) {
		result = "нуль ";
	}
	int n1 = numb;
	int cnt = 0;

	//п≥драхунок к≥лькост≥ символ≥в в числ≥
	while (numb) {
		numb /= 10;
		cnt++;
	}
	int cile = 0;

	while (n1) {
		if (!((cnt + 1) % 3)) {
			if ((n1 / osn[cnt]) == 1) {
				n1 %= osn[cnt];
				--cnt;
				cile = n1 / osn[cnt];
				n1 %= osn[cnt];
				result += dec[cile];
				--cnt;
				if (!(cnt % 3))
					result += " " + termination[0][cnt] + " ";
			}
			if (!cnt) break;
		}
		cile = n1 / osn[cnt];
		n1 %= osn[cnt];
		result += basis[cnt][cile] + " ";
		--cnt;
		if (!(cnt % 3))
			result += termination[cile][cnt] + " ";
	}
	cout << "Ќа вашому рахунку " << result << "гривень " << fixed << setprecision(0) << frac * 100 << " коп≥йок";
	cout << endl;
}

double Account::Total(const Account& a) {
	int hrn, kop;
	double sum;
	hrn = a.getH500() * 500 + a.getH200() * 200 + a.getH100() * 100 +
		a.getH50() * 50 + a.getH20() * 20 + a.getH10() * 10 + a.getH5() * 5 + a.getH2() * 2 + a.getH1();
	kop = a.getC50() * 50 + a.getC25() * 25 + a.getC10() * 10 + a.getC5() * 5 + a.getC2() * 2 + a.getC1();
	sum = (double)hrn + (double)kop / 100.;
	return sum;
}

Account Account::Add(const Account& x, const Account& y, Account& a)
{
	double subt = Total(x) + Total(y);
	int hrn = (int)subt;
	int coin = (floor((subt - hrn) * 100 + 0.501));

	return Change(hrn, coin, a);
}

Account Account::Subtract(const Account& x, const Account& y, Account& a)
{
	double subt = Total(x) - Total(y);
	if (subt <= 0)
	{
		cerr << "Sum on first account is lesser than that on the latter.\n";
		return a;
	}
	else
	{
		int hrn = (int)subt;
		int coin = (floor((subt - hrn) * 100 + 0.501));

		return Change(hrn, coin, a);
	}
}

Account Account::Multiply(Account& x, const double y)
{
	if (y <= 0)
		Account(x);
	else
	{
		if (y != 1)
		{
			double sum = Total(x);
			sum *= y;
			int hrn = (int)sum;
			int coin = (floor((sum - hrn) * 100 + 0.501));

			return Change(hrn, coin, x);
		}
		else
			Account(x);
	}
	return x;
}

Account Account::Division(Account& x, const double y)
{
	if (y == 0)
		Account(x);
	else
	{
		if (y != 1)
		{
			double sum = Total(x);
			sum = sum / y;
			int hrn = (int)sum;
			int coin = (floor((sum - hrn) * 100 + 0.501));

			return Change(hrn, coin, x);
		}
		else
			Account(x);
	}
	return x;
}

Account Account::DivOfSums(const Account& x, const Account& y, Account& a)
{
	double subt = Total(x) / Total(y);
	int hrn = (int)subt;
	int coin = (floor((subt - hrn) * 100 + 0.501));

	return Change(hrn, coin, a);
}

Account Account::Change(int hrn, int coin, Account& d)
{
	d.setH500(hrn / 500);
	hrn -= d.getH500() * 500;
	d.setH200(hrn / 200);
	hrn -= d.getH200() * 200;
	d.setH100(hrn / 100);
	hrn -= d.getH100() * 100;
	d.setH50(hrn / 50);
	hrn -= d.getH50() * 50;
	d.setH20(hrn / 20);
	hrn -= d.getH20() * 20;
	d.setH10(hrn / 10);
	hrn -= d.getH10() * 10;
	d.setH5(hrn / 5);
	hrn -= d.getH5() * 5;
	d.setH2(hrn / 2);
	hrn -= d.getH2() * 2;
	d.setC50(coin / 50);
	coin -= d.getC50() * 50;
	d.setC25(coin / 25);
	coin -= d.getC25() * 25;
	d.setC10(coin / 10);
	coin -= d.getC10() * 10;
	d.setC5(coin / 5);
	coin -= d.getC5() * 5;
	d.setC2(coin / 2);
	coin -= d.getC2() * 2;

	return d;
}

bool operator < (Account a, Account b) {
	return a.Money::Total() < b.Money::Total();
}
bool operator <= (Account a, Account b) {
	return a.Money::Total() <= b.Money::Total();
}
bool operator > (Account a, Account b) {
	return a.Money::Total() > b.Money::Total();
}
bool operator >= (Account a, Account b)
{
	return a.Money::Total() >= b.Money::Total();
}
bool operator == (Account a, Account b) {
	return a.Money::Total() == b.Money::Total();
}
bool operator != (Account a, Account b) { return !operator ==(a, b); }