#ifndef MYVECTOR_H
#define MYVECTOR_H
#pragma warning(disable:4996)
#include <memory>
#include <cstddef>
//#include <algorithm>
size_t max(size_t a, size_t b)
{
	return a > b ? a : b;
}
size_t min(size_t a, size_t b)
{
	return a > b ? b : a;
}
using namespace std;
template <class T> class Vector
{
public:
	typedef T* iterator;
public:
	Vector() : elements(0), first_free(0), end(0){}
	void push_back(const T&);
	void reserve(const size_t capa);
	void resize(const size_t n);
	void resize(const size_t n, const T& t);
	T& operator[](const size_t);
	const T& operator[](const size_t) const;
	size_t size()
	{
		return first_free - elements;
	}
	size_t capacity()
	{
		return end - elements;
	}
	iterator begin()
	{
		return elements;
	}
	iterator last()
	{
		return first_free;
	}
private:
	static std::allocator<T> alloc;
	void reallocate();
	T* elements;
	T* first_free;
	T* end;
};
template <class T> allocator<T> Vector<T>::alloc;
template <class T> void Vector<T>::push_back(const T& t)
{
	if (first_free == end)
	{
		reallocate();
	}
//	alloc.construct(first_free, t);
	new (first_free) T(t);
	++first_free;
}
template <class T> void Vector<T>::reallocate()
{
	ptrdiff_t size = first_free - elements;
	ptrdiff_t newcapacity = 2 * max(size, 1);
//	T* newelements = alloc.allocate(newcapacity);
	T* newelements = static_cast<T*>
		(operator new[](newcapacity*sizeof(T)));
	uninitialized_copy(elements, first_free, newelements);
	for (T *p = first_free; p != elements;/*empty*/)
	{
	//	alloc.destroy(--p);
		(--p)->~T();
	}
	if (elements)
	{
	//	alloc.deallocate(elements, end - elements);
		operator delete[](elements);
	}
	elements = newelements;
	first_free = elements + size;
	end = elements + newcapacity;
}
template <class T>
void Vector<T>::reserve(const size_t capa)
{
	size_t size = first_free - elements;
//	T* newelements = alloc.allocate(capa);
	T* newelements = static_cast<T*>
		(operator new[](capa*sizeof(T)));
	if (size <= capa)
	{
		uninitialized_copy(elements, first_free, newelements);
	}
	else
		uninitialized_copy(elements, elements + capa, newelements);
	for (T *p = first_free; p != elements; )
	{
	//	alloc.destroy(--p);
		(--p)->~T();
	}
	if (elements)
	{
	//	alloc.deallocate(elements, end - elements);
		operator delete[](elements);
	}
	elements = newelements;
	first_free = elements + min(size, capa);
	end = elements + capa;
}
template <class T>
void Vector<T>::resize(const size_t n)
{
	size_t size = first_free - elements;
	size_t capacity = end - elements;
	if (n>capacity)
	{
		reallocate();
		uninitialized_fill(elements + size, elements + n, T());
	}
	else if (n > size)
	{
		uninitialized_fill(elements + size, elements + n, T());
	}
	else
		for (T *p = first_free; p != elements + n; )
		{
		//	alloc.destroy(--p);
			(--p)->~T();
		}
	first_free = elements + n;
}
template <class T>
void Vector<T>::resize(const size_t n, const T& t)
{
	size_t size = first_free - elements;
	size_t capacity = end - elements;
	if (n>capacity)
	{
		reallocate();
		uninitialized_fill(elements + size, elements + n, t);
	}
	else if (n > size)
	{
		uninitialized_fill(elements + size, elements + n, t);
	}
	else
		for (T *p = first_free; p != elements + n;)
			//	alloc.destroy(--p);
			(--p)->~T();
	first_free = elements + n;
}
template <class T>
T& Vector<T>::operator[](const size_t index)
{
	return elements[index];
}
template <class T>
const T& Vector<T>::operator[](const size_t index) const
{
	return elements[index];
}
#endif;