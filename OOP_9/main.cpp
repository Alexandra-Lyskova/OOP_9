#include "flower.h"
#include "set.cpp"
#include "setitem.cpp"
#include "compare.cpp"
#include <iostream>
using namespace std;
int main(int argc, char argv[])
{
	setlocale(LC_ALL,"rus");
	Set<int> s1;
	s1.add(new SetItem<int>(1));
	s1.add(new SetItem<int>(2));
	s1.add(new SetItem<int>(3));
	s1.add(new SetItem<int>(4));
	cout<<"ћножество int содержит следующие элементы:"<<endl;
	for (SetItem<int> *si=s1.getFirst(); si!=NULL; si=si->getNext())
	{
		cout<<si->getData()<<endl;
	}
	int d1=1;
	s1.dec(d1);
	cout<<"Ёлементы множества int уменьшены на "<<d1<<":"<<endl;
	for (SetItem<int> *si=s1.getFirst(); si!=NULL; si=si->getNext())
	{
		cout<<si->getData()<<endl;
	}
	Set<double> s4;
	s4.add(new SetItem<double>(2.44));
	s4.add(new SetItem<double>(3.66));
	s4.add(new SetItem<double>(4.123));
	s4.add(new SetItem<double>(5.57));
	cout<<"ћножество double содержит следующие элементы:"<<endl;
	for (SetItem<double> *si=s4.getFirst(); si!=NULL; si=si->getNext())
	{
		cout<<si->getData()<<endl;
	}
	double d2=0.55;
	s4.dec(d2);
	cout<<"Ёлементы множества double уменьшены на "<<d2<<":"<<endl;
	for (SetItem<double> *si=s4.getFirst(); si!=NULL; si=si->getNext())
	{
		cout<<si->getData()<<endl;
	}
	Set<Flower*, CompareFlower, DecrementFlower> s5;
	s5.add(new SetItem<Flower*>(new Flower("rose",2)));
	s5.add(new SetItem<Flower*>(new Flower("carnation",3)));
	s5.add(new SetItem<Flower*>(new Flower("camomile",5)));
	s5.add(new SetItem<Flower*>(new Flower("tulip",7)));
	cout<<"ћножество Flower содержит следующие элементы:"<<endl;
	Flower *f;
	for (SetItem<Flower*> *si=s5.getFirst(); si!=NULL; si=si->getNext())
	{
		f=si->getData();
		cout<<f->getName()<<", размер: "<<f->getSize()<<endl;
	}
	int d3=1;
	s5.dec(d3);
	cout<<"Ёлементы множества Flower уменьшены на "<<d3<<":"<<endl;
	for (SetItem<Flower*> *si=s5.getFirst(); si!=NULL; si=si->getNext())
	{
		f=si->getData();
		cout<<f->getName()<<", размер: "<<f->getSize()<<endl;
	}
	return 0;
	cout<<endl;
}
