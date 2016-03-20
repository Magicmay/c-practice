#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename Parm>
void print(const Parm &c)
{
	typename Parm::size_type index = 0;
	while (index!=c.size())
	{
		cout << c[index] << " ";
		++index;
	}
}
template <typename T>
void printf(const T &c)
{
	typename T::const_iterator iter;
	for (iter = c.begin(); iter != c.end();++iter)
	{
		cout << *iter << " ";
	}
}
template <typename T,std::size_t N>
std::size_t size(T (&arr)[N])
{
	return N;
}
template <typename Type,std::size_t N>
void printValues(Type (&arr)[N])
{
	for (std::size_t i = 0; i != N;++i)
	{
		std::cout << arr[i] << std::endl;
	}
}
template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2)
		return -1;
	if (v2 < v1)
		return 1;
	return 0;
}
int main()
{
	int ia[] = { 1, 2, 1, 4, 1, 6, 1 };
	string aa[] = { "this", "is","Mary", "test", "example" };
	vector<int> ivec(ia, ia + 7);
	vector<string> svec(aa, aa + 5);
	printf(ivec);
	cout << endl;
	printf(svec);
	cout << endl;
	print(ivec);
	cout << endl;
	print(svec);
	cout << endl;

	cout<<size(ia)<<endl;
	printValues(aa);

	short sval = 122;
	int ival = 1024;
	cout << compare(static_cast<int>(sval), ival) << endl;
	cout << compare(sval, static_cast<short>(ival)) << endl;
	cout << compare<short>(sval, ival) << endl;
	cout << compare<int>(sval, ival) << endl;

	system("pause");
	return 0;
}