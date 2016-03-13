#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
template <typename T,typename V>
T& print(T& s, V val)
{
	s << val;
	return s;
}
int main()
{
	double dval = 0.88;
	float fval = -12.3;
	string oristr = "this is a test", desstr;
	ostringstream oss(desstr);
	ofstream outFile("result.dat");
	print(cout, -3) << endl;
	print(cout, dval) << endl;
	print(cout, fval) << endl;
	print(cout, oristr) << endl;

	print(outFile, -3)<<endl;
	print(outFile, dval)<<endl;
	print(outFile, fval)<<endl;
	print(outFile, oristr)<<endl;
	outFile.close();

	print(oss, -3)<<endl;
	print(oss, dval)<<endl;
	print(oss, fval) << endl;
	print(oss, oristr) << endl;
	
	//将stringstream中的字符串输出到cout以进行验证
	cout << oss.str() << endl;
	system("pause");
	return 0;
}