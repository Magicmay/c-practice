#pragma once
#include <iostream>
template <class Type> class List;
template <class Type> class ListItem
{
	friend class List < Type > ;
	ListItem(const Type &t) : item(t), next(0){}
	Type item;
	ListItem *next;
};
template <class Type> class List
{
	List() : front(0), end(0){}
	List(const List &l) : front(0), end(0)
	{
		copy_elems(l);
	}
	List& operator=(const List &);
	~List()
	{
		destroy();
	}
	void insert(ListItem<Type> *ptr, , const Type &value);
	void del(ListItem<Type> *ptr);
	ListItem<Type> *find(const Type &value);
	ListItem<Type> *first()
	{
		return front;
	}
	ListItem<Type> *last()
	{
		return end;
	}
	bool empty() const
	{
		return front == 0;
	}
	Type& getElem(ListItem<Type> *ptr)
	{
		return ptr->item;
	}
	template <class Iter>
	List(Iter first, Iter last) : front(first), end(last)
	{
		copy_elems(first, last);
	}
	template <class Iter>
	void assign(Iter, Iter);
private:
	ListItem<Type> *front, *end;
	void destroy();
	void copy_elems(const List &);
	template<class Iter> void copy_elems(Iter, Iter);
};
template <class Type>
void List<Type>::destroy()
{
	while (!empty())
	{
		del(front);
	}
}
template <class Type>
void List<Type>::del(ListItem<Type> *ptr)
{
	ListItem<Type> *p = front;
	while (p != ptr && p != 0 && p->next != ptr)
		p = p->next;
	if (p != 0)
	{
		if (p == ptr)
			front = ptr->next;
		else
			p->next = ptr->next;
		if (ptr == end)
			end = p->next;
		delete ptr;
	}
	else
		throw out_of_range("no such element");
}
template <class Type>
void List<Type>::insert(ListItem<Type> *ptr, const Type &val)
{
	ListItem<Type> *pt = new ListItem<Type>(val);
	if (empty())
	{
		front = pt;
	}
	else
	{
		pt->next = ptr->next;
		ptr->next = pt;
	}
	if (ptr==end)
	{
		end = pt;
	}
}
template <class Type>
List<Type>& List<Type>::copy_elems(const List &orig)
{
	for (ListItem<Type> *pt = orig.front; pt;pt=pt->next)
	{
		insert(end, pt->item);
	}
}
template <class Type>
List<Type>& List<Type>::operator=(const List &orig)
{
	front = end = 0;
	copy_elems(orig);
	return *this;
}
template <class Type>
ListItem<Type>* List<Type>::find(const Type &value)
{
	ListItem<Type> *pt = front;
	while (pt && pt->item != value)
		pt = pt->item;
	return pt;
}
template <class T> template <class Iter>
void List<T>::assign(Iter first, Iter last)
{
	destroy();
	copy_elems(first, last);
}
template <class T> template <class Iter>
void List<T>::copy_elems(Iter first, Iter last)
{
	while (first!=last)
	{
		insert(end, first->item);
		first = first->next;
	}
	insert(end, first->item);
}