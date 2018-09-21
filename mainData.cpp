#include <iostream>

#include "data.h"

using namespace std;

int main(void)
{
	double i;
	data a1,a2,a3;
	
	i = 5;
	a1 = data(i);
	a2 = data(3.2);
	cout << a1 << endl;
	cout << a2 << endl;
	a3 = data(a1,a2);
	cout << a3 << endl;
	a3.merge(a1);
	cout << a3 << endl;

	return 0;
}
