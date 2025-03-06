#include "ExtendedTest.h"
#include "ShortTest.h"

#include "Map.h"


#include <iostream>
using namespace std;


int main() {
    testAll();
    cout << "Short tests over." << endl;

	testAllExtended();
    cout << "All tests over." << endl;

	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


