#ifndef SCREEN_H
#define SCREEN_H
#include <string>
class Screen
{
public:
	typedef Screen& (Screen::*pmfType)();
	typedef std::string::size_type index;

	Screen(pmfType p = &Screen::home) : pmf(p){}
	void setPmf(pmfType p)
	{
		pmf = p;
	}
	char get() const;
	char get(index ht, index wd) const;

	Screen& home();
	Screen& forward();
	Screen& back();
	Screen& up();
	Screen& down();
	static pmfType Menu[];
public:
	enum Direction{ HOME, PORWARD, BACK, UP, DOWN };
	Screen& move(Direction);
private:
	std::string contents;
	index cursor;
	index height, width;
public:
	pmfType pmf;
};
Screen& Screen::move(Direction cm)
{
	(this->*Menu[cm])();
	return *this;
}
Screen::pmfType Screen::Menu[] = { &Screen::home,
&Screen::forward, &Screen::back, &Screen::up, &Screen::down };
#endif