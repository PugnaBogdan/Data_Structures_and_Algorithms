#include "ExtendedTest.h"
#include "ShortTest.h"
#include "MultiMap.h"
#include <iostream>
int main()
{
	testAll();
	cout << "short test passed\n";
	testAllExtended();
	cout << "extended test passed\n";
	system("pause");
	/*MultiMap m;

	m.add(1, 100);
	m.add(2, 200);
	m.add(1, 500);

	vector<TValue> x = m.AllValues();
	for (int i = 0; i < x.size(); i++)
		cout << x[i] << " ";*/
	system("pause");
	return 0;
}