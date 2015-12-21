#pragma once
#include "setitem.cpp"
#include "compare.cpp"
#include "decrement.cpp"
#include <iostream>
template<class t, class c = Compare<t>, class d = Decrement<t> > class Set
{
	int counter;
	SetItem<t> *first;
protected:
	int size();
	SetItem<t>* remove(SetItem<t> *si);
	Set<t,c,d>* unify(Set *s);
	Set<t,c,d>* intersect(Set *s);
	bool contains(Set *s);
public:
	Set();
	bool add(SetItem<t> *si);
	SetItem<t>* getFirst();
	void dec(double i);

	operator int();
	Set<t,c,d>* operator - (SetItem<t>* si);
	Set<t,c,d>* operator * (Set* s);
	bool operator < (Set* s);
	bool operator > (Set* s);
	~Set();
};
template<class t,class c, class d> Set<t,c,d>::Set()
{
	this->counter=0;
	this->first=NULL;
}
template<class t, class c, class d> bool Set<t,c,d>::add(SetItem<t> *si)
{
	bool result=true;
	SetItem<t> *last=NULL;
	for (SetItem<t> *i=this->getFirst(); i!=NULL; i=i->getNext())
	{
		last=i;
		if (c::equal(i->getData(),si->getData()))
		{
			result=false;
			break;
		}
	}
	if (result)
	{
		if (last!=NULL)
		{
			last->setNext(si);
		} else
		{
			this->first=si;
		}
		this->counter++;
	}
	return result;
}
template<class t, class c, class d> void Set<t,c,d>::dec(double id)
{
	for (SetItem<t> *i=this->getFirst(); i!=NULL; i=i->getNext())
	{
		d::dec(i,id);
	}
}
template<class t, class c, class d> SetItem<t>* Set<t,c,d>::remove(SetItem<t> *si)
{
	SetItem<t> *result=NULL;
	SetItem<t> *found=NULL;
	SetItem<t> *prev=NULL;
	for (SetItem<t> *i=this->getFirst(); i!=NULL; i=i->getNext())
	{
		found=i;
		if (c::equal(i->getData(),si->getData()))
		{
			if (prev==NULL)
			{
				this->first=found->getNext();
			} else
			{
				prev->setNext(found->getNext());
			}
			this->counter--;
			result=found;
			break;
		}
		prev=i;
	}
	return result;
}
template<class t, class c, class d> bool Set<t,c,d>::contains(Set *s)
{
	bool result=false;
	if (this->size()>=s->size())
	{
		Set *temp = this->intersect(s);
		if (temp->size()==s->size())
		{
			result = true;
		}
		delete temp;
	}
	return result;
}
template<class t, class c, class d> SetItem<t>* Set<t,c,d>::getFirst()
{
	return this->first;
}
template<class t, class c, class d> int Set<t,c,d>::size()
{
	return this->counter;
}
template<class t, class c, class d> Set<t,c,d>* Set<t,c,d>::unify(Set *s)
{
	Set *result = new Set();
	return result;
}
template<class t, class c, class d> Set<t,c,d>* Set<t,c,d>::intersect(Set *s)
{
	Set *result = new Set();
	SetItem<t> *si;
	for (SetItem<t> *i=this->getFirst(); i!=NULL; i=i->getNext())
	{
		for (SetItem<t> *j=s->getFirst(); j!=NULL; j=j->getNext())
		{
			if (c::equal(i->getData(),j->getData()))
			{
				si=new SetItem<t>(j->getData());
				result->add(si);
			}
		}
	}
	return result;
}
template<class t, class c, class d> Set<t,c,d>::operator int()
{
	return this->size();
}
template<class t, class c, class d> Set<t,c,d>* Set<t,c,d>::operator - (SetItem<t>* si)
{
	this->remove(si);
	return this;
}
template<class t, class c, class d> Set<t,c,d>* Set<t,c,d>::operator * (Set* s)
{
	return this->intersect(s);
}
template<class t, class c, class d> bool Set<t,c,d>::operator < (Set* s)
{
	return (this->size()<s->size());
}
template<class t, class c, class d> bool Set<t,c,d>::operator > (Set* s)
{
	return (this->contains(s));
}
template<class t, class c, class d> Set<t,c,d>::~Set()
{
}