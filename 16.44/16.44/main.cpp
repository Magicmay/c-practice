#include "Queue.h"
#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> lint = { 1, 2, 3, 4 };
	Queue<int> q(lint.begin(),lint.end());
	cout << q << endl;
	system("pause");
	return 0;
}