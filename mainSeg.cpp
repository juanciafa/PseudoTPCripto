#include <iostream>

#include "data.h"
#include "Array.h"
#include "segment_tree.h"

using namespace std;

int main(void)
{
	Array<data> arr;
	
	arr = Array<data>(5);
	for(size_t i=0; i<5; i++)
	{
		arr[i] = data((double)i,i);
	}
	segment_tree st (arr);
	cout << st << endl;
	data t = st.search_interval(0,1);
	cout << endl << endl << t << endl;

	return 0;
}
