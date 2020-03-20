#include "MultiMapIt.h"
#include <exception>
#include <iostream>
#include <utility>
using namespace std;

MultiMapIterator::MultiMapIterator(const MultiMap& c) : c{ c } //theta(1)
{
	if (this->c.size() != 0)
	{
		this->currentElement.first = this->c.slla.elementsList[this->c.slla.head].element.first;
		this->currentElement.second = this->c.slla.elementsList[this->c.slla.head].element.second;
		this->currentPosition = this->c.slla.head;
	}
	else
	{
		this->currentElement.first = NULL;
		this->currentElement.second = NULL;
		this->currentPosition = -1;
	}
}

void MultiMapIterator::first() //theta(1)
{
	this->currentElement = this->c.slla.elementsList[this->c.slla.head].element;
	this->currentPosition = this->c.slla.head;
}

void MultiMapIterator::next() //theta(1)
{
	if (this->valid() == true)
	{
		this->currentPosition = this->c.slla.elementsList[this->currentPosition].next;
		this->currentElement = this->c.slla.elementsList[this->currentPosition].element;
	}
	else
		throw exception();
}

bool MultiMapIterator::valid() const //theta(1)
{
	if (this->currentPosition == -1)
		return false;
	return true;
}

TElem MultiMapIterator::getCurrent() const //theta(1)
{
	if (this->valid() == false)
		throw exception();
	return this->c.slla.elementsList[this->currentPosition].element;
}