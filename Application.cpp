#include <iostream>
#include "Application.h"
#include "Linear.h"
#include "Square.h"

using namespace std;

void Application::TestAll()
{
	Linear l{};
	cout << l << endl;
	l.solve();
	cout << l << endl;

	Square s{};
	s.solve();
	cout << s << endl;

	Linear l1(1, -2);
	Linear l2(0, 0);
	Linear l3(0, 1);

	Square s1{0, 1, 0};
	Square s2{1, 0, -1};
	Square s3{1, 0, 1};

	Root* roots[6] = {&l1, &l2, &l3, &s1, &s2, &s3};
	for (int i = 0; i < 6; i++) {
		roots[i]->solve();
		cout << *(roots[i]) << endl;
	}
}

void Application::PrintMenu()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	if (m_eq) {
		cout << *m_eq << endl;
	} else {
		cout << "Уравнение не задано" << endl;
	}
	cout << "0: Выход" << endl;
	cout << "1: Отладочный вывод" << endl;
	cout << "2: Задать линейное уравнение" << endl;
	if (m_eq) {
		cout << "4: Решить уравнение" << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Выберите пункт: ";
}

void Application::InputLinear()
{
	double a, b;
	cout << "ax + b = 0" << endl;
	cout << "Введите a и b: ";
	cin >> a >> b;
	cout << a << " " << b << endl;
	delete m_eq;
	m_eq = new Linear(a, b);
}

void Application::InputSquare()
{
	double a, b, c;
	cout << "ax² + bx + c = 0" << endl;
	cout << "Введите a, b и c: ";
	cin >> a >> b >> c;
	cout << a << " " << b << " " << c << endl;
	delete m_eq;
	m_eq = new Square(a, b, c);
}

void Application::Solve()
{
	m_eq->solve();
}

void Application::Run()
{
	bool keks = true;
	int ex;
	while (keks)
	{
		PrintMenu();
		cin >> ex;
		cout << ex << endl;
		switch (ex) {
		case 0:
			keks = false;
			break;
		case 1:
			TestAll();
			break;
		case 2:
			InputLinear();
			break;
		case 3:
			InputSquare();
			break;
		case 4:
			Solve();
			break;
		default:
			break;
		}
	}
}
