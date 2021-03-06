#ifndef SALESITEM_H
#define SALESITEM_H
#include <windows.h>
#include "Handle.h"
#include "Item.h"
class Sales_item
{
public:
	Sales_item() :h(){}
	Sales_item(const Item_base &item) :h(item.clone()){}
	const Item_base* operator->() const
	{
		return h.operator->();
	}
	const Item_base& operator*() const
	{
		return *h;
	}
private:
	Handle<Item_base> h;
};
#endif