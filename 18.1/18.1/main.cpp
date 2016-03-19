#include "Vector.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	Vector<int> ivec;
	for (size_t i = 0; i != 8;++i)
	{
		ivec.push_back(i);
		cout << ivec[i] << "\t";
	}
	cout << endl;
	cout << ivec.size() << "\t" << ivec.capacity() << endl;
	ivec.reserve(50);
	cout << ivec.size() << "\t" << ivec.capacity() << endl;
	ivec.resize(20);
	for (size_t i = 0; i != 20;++i)
	{
		cout << ivec[i] << "\t";
	}
	cout << endl;
	cout << ivec.size() << "\t" << ivec.capacity() << endl;
	
	Vector<string> svec;
	string s;
	cout << "Enter some strings(ctrl+z to end): " << endl;
	while (cin >> s)
		svec.push_back(s);
	for (size_t i = 0; i != svec.size();++i)
	{
		cout << svec[i] << "\t";
	}
	cout << endl;

	cout << svec.size() << "\t" << svec.capacity() << endl;
	svec.reserve(50);
	cout << svec.size() << "\t" << svec.capacity() << endl;
	svec.resize(20);
	for (size_t i = 0; i != 20; ++i)
		cout << svec[i] << "\t";
	cout << endl;
	cout << svec.size() << "\t" << svec.capacity() << endl;
	cout << svec[2] << "\t" << svec[10] << endl;
	system("pause");
	return 0;
}