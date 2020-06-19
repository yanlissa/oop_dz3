#include <iostream>

#include "Linear.h"
#include "Square.h"

using namespace std;

int main()
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

	return 0;
}
