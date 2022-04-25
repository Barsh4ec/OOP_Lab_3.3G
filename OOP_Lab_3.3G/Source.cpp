#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include "Account.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Account a, b, c, d;
	a.setSecondname("��������");
	a.setNo(1);
	a.setPercent(6.4);
	a.setSumma();
	int no;
	do {
		cout << a;
		cout << "������� �������:" << fixed << setprecision(2) << a.getSecondame() << endl;
		cout << "������� ��" << endl;
		cout << "[1] - ������ �������� �������" << endl;
		cout << "[2] - ����� ����� ���� ������ � �������" << endl;
		cout << "[3] - �������� ����� �� �������" << endl;
		cout << "[4] - ���������� �������" << endl;
		cout << "[5] - ��������� ���� � ������" << endl;
		cout << "[6] - ��������� ���� � ����" << endl;
		cout << "[7] - �������� ���� ��������" << endl;
		cout << "[8] - ��������� ���" << endl;
		cout << "[9] - �������� ���" << endl;
		cout << "[10] - ������ ���" << endl;
		cout << "[11] - ������ ���� �� ������� �����" << endl;
		cout << "[12] - �������� �� ������� �����" << endl;
		cout << "[13] - �������� ���������" << endl;
		cout << "[0] - ��������� ���������" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		{
		case 1:
			a.ChangeOwner();
			break;
		case 2:
			a.GetMoney();
			break;
		case 3:
			a.AddMoney();
			break;
		case 4:
			a.MakePercent(a);
			break;
		case 5:
			a.ToDollar(a);
			break;
		case 6:
			a.ToEuro(a);
			break;
		case 7:
			a.Propys();
			break;
		case 8:
			b.setSumma();
			cout << b;
			c.Add(a, b, c);
			cout << "�������: " << endl;
			cout << c;
			break;
		case 9:
			b.setSumma();
			cout << b;
			d.Subtract(a, b, d);
			cout << "�������: " << endl;
			cout << d;
			break;
		case 10:
			b.setSumma();
			cout << b;
			a.DivOfSums(a, b, a);
			cout << "�������: " << endl;;
			cout << a;
			break;
		case 11:
			double x;
			cout << "�� ��� ����� ���� �� ���� �������? : "; cin >> x;
			a.Division(a, x);
			cout << "�������: " << endl;
			cout << a;
			break;
		case 12:
			cout << "�� ��� ����� ���� �� ���� ���������? : "; cin >> x;
			a.Multiply(a, x);
			cout << "�������: " << endl;
			cout << a;
			break;
		case 13:
			b.setSumma();
			cout << b;
			if (a < b == true)
				cout << "����� ���� ����� �� �����" << endl;
			if (a <= b == true)
				cout << "����� ���� ����� ��� ���� �����" << endl;
			if (a > b == true)
				cout << "����� ���� ����� �� �����" << endl;
			if (a >= b == true)
				cout << "����� ���� ����� ��� ���� ������" << endl;
			if (a == b == true)
				cout << "����� � ����� ���� ����" << endl;
			if (a != b == true)
				cout << "����� � ����� ���� �� ����" << endl;
			break;
		}
		cout << endl;
	} while (no != 0);

	cout << "Money count " << Money::Count() << endl;
	cout << "Account count " << Account::Count() << endl;
	cout << "Object count " << Object::Count() << endl;

	return 0;
}
