#include <iostream>
#include <string>

#include "data.h"
#include "Array.h"
#include "segment_tree.h"
#include "sensor.h"
#include "utis.h"

using namespace std;

int main(void)
{
	Array<data> arr;
	string str;
	
	arr = Array<data>(5);
	for(size_t i=0; i<5; i++)
	{
		arr[i] = data((double)i,i);
	}
	str = "Esencia_Lucio";
	sensor sen(str,arr);
	cout << sen;
	
	
	return 0;
}
