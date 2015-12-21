#include "flower.h"
Flower::Flower(char *name, int size)
{
	this->name=name;
	this->size=size;
}
char* Flower::getName()
{
	return name;
}
int Flower::getSize()
{
	return size;
}
void Flower::setSize(int size)
{
	this->size=size;
}
Flower::~Flower()
{
}
