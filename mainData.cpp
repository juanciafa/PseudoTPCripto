#include <iostream>

#include "data.h"

using namespace std;

int main(void)
{
	double i;
	data a1,a2,a3,a4;
	
	i = 5;
	a1 = data(i,0);
	a2 = data(3.2,1);
	cout << a1 << endl;
	cout << a2 << endl;
	a3 = data(a1,a2);
	cout << a3 << endl;
	a3.merge(a1);
	cout << a3 << endl;
	a4 = data(false,2);
	cout << data(a2,a4) << endl;

	return 0;
}
