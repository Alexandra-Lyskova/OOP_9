#pragma once
#include <iostream>
#include "compare.cpp"
template<class t> class SetItem
{
	t data;
	SetItem<t> *next;
public:
	SetItem(t data);
	t getData();
	void setData(t data);
	void setNext(SetItem *si);
	SetItem<t>* getNext();
	bool isEqual(SetItem *si);
	~SetItem();
};
template<class t> SetItem<t>::SetItem(t data)
{
	this->data=data;
	this->next=NULL;
}
template<class t> t SetItem<t>::getData()
{
	return this->data;
}
template<class t> void SetItem<t>::setData(t data)
{
	this->data=data;
}
template<class t> void SetItem<t>::setNext(SetItem *si)
{
	this->next=si;
}
template<class t> SetItem<t>* SetItem<t>::getNext()
{
	return this->next;
}
template<class t> SetItem<t>::~SetItem()
{
}