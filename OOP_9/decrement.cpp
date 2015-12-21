#pragma once
#include "setitem.cpp"
#include "flower.h"
template<class t> class Decrement
{
public:
	static void dec(SetItem<t> *a, double i)
	{
		a->setData(a->getData()-i);
	}
};
class DecrementFlower
{
public:
	static void dec(SetItem<Flower*> * a, int i)
	{
		Flower *f=a->getData();
		f->setSize(f->getSize()-i);
	}
};