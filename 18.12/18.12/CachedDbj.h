#ifndef CACHEDDBJ_H
#define CACHEDDBJ_H

#include <cstddef>
#include <memory>
#include <stdexcept>

template <class T> class CachedDbj
{
public:
	void *operator new(std::size_t);
	void operator delete(void *, std::size_t);
	virtual ~CachedDbj()
	{

	}
protected:
	T *next;
private:
	static void add_to_freelist(T*);
	static std::allocator<T> alloc_mem;
	static T *freeStore;
	static const std::size_t chunk;
};
template <class T> std::allocator<T> CachedDbj<T>::alloc_mem;
template <class T> T *CachedDbj<T>::freeStore = 0;
template <class T> const std::size_t CachedDbj<T>::chunk = 24;
template <class T>
void *CachedDbj<T>::operator new(size_t sz)
{
	if (sz!=sizeof(T))
	{
		throw std::runtime_error
			("CachedDbj: wrong size object in operator new");
	}
	if (!freeStore)
	{
		T *array = alloc_mem.allocate(chunk);
		for (sizeof i = 0; i != chunk;++i)
		{
			add_to_freelist(&array[i]);
		}
	}
	T *p = freeStore;
	freeStore = freeStore->CachedDbj<T>::next;
	return p;
}
template <class T>
void CachedDbj<T>::operator delete(void *p, size_t)
{
	if (p != 0)
		add_to_freelist(static_cast<T*>(p));
}
template <class T>
void CachedDbj<T>::add_to_freelist(T *p)
{
	p->CachedDbj<T>::next = freeStore;
	freeStore = p;
}
#endif

