#pragma once
#include "flower.h"
#include "string.h"
template<class t> class Compare
{
public:
	static bool equal(t a, t b)
	{
		return (a == b);
	}
};
class CompareFlower
{
public:
	static bool equal(Flower* a, Flower* b)
	{
		return ((strcmp(a->getName(),b->getName()) == 0)&(a->getSize() == b->getSize()));
	}
};