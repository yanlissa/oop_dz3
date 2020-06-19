#include <iostream>

#include "Linear.h"
#include "Square.h"

using namespace std;

int main()
{
	Root* roots[5];

	Linear l1(1, -2);
	cout << l1 << endl;
	l1.solve();
	cout << l1 << endl;

	Linear l2(0, 0);
	l2.solve();
	cout << l2 << endl;

	Linear l3(0, 1);
	l3.solve();
	cout << l3 << endl;
	return 0;
}
