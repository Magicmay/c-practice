#pragma once
#include "Screen.h"
/*#include <iostream>
#include <string>
template<int hi, int wid> class Screen
{
public:
	typedef std::string::size_type index;
	Screen() : contents(hi*wid, '#'), cursor(0), height(hi), width(wid){}
	Screen(const std::string &cont);
	char get() const
	{
		return contents[cursor];
	}
//	char get(index ht, index wd) const;
//	index get_cursor() const { return cursor; }
//	Screen& move(index t, index c);
//	Screen& set(char);
//	Screen& display(ostream &os);
//	const Screen& display(ostream &os) const;
private:
	std::string contents;
	index cursor;
	index height, width;
};
template<int hi, int wid> Screen<hi, wid>::Screen<hi, wid>(const
	std::string &cont) : cursor(0), height(hi), width(wid)
{
	contents.assign(hi*wid, '#');
	if (cont.size() != 0)
	{
		contents.replace(0, cont.size(), cont);
	}
}*/
int main()
{
	Screen<50, 40> sc;
	system("pause");
	return 0;
}
