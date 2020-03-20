#include "MultiMapIterator.h"

#include <exception>	
// nu theta(1)...
//O(m)
MultiMapIterator::MultiMapIterator(const MultiMap& _c) :
	c{ _c }
{
	//this->currentK = 0;
	this->currentV = 0;
	int i = 0;
	while (this->c.hash[i].key == MY_NULL || this->c.hash[i].key == DELETED)
		i++;
	this->currentK = i;
}


//nu theta(1)...
//O(m)
void MultiMapIterator::first()
{
	this->currentV = 0;
	int i = 0;
	while (this->c.hash[i].key == MY_NULL || this->c.hash[i].key == DELETED)
		i++;
	this->currentK = i;
}


//nu theta(1)...
//O(m)
void MultiMapIterator::next()
{
	if (!this->valid())
		throw std::exception();
	if (this->currentV == this->c.hash[this->currentK].values.getSize() - 1)
	{
		//go to next key
		this->currentK++;
		while (this->c.hash[this->currentK].key == MY_NULL || this->c.hash[this->currentK].key == DELETED)
			this->currentK++;
		this->currentV = 0;
	}
	else
	{
		//go to next value of the actual key
		this->currentV++;
	}
}


//theta(1)
bool MultiMapIterator::valid() const
{
	if (this->currentK < this->c.m)
		if (this->currentV < this->c.hash[this->currentK].values.getSize())
			return true;
	return false;
}

TElem MultiMapIterator::getCurrent() const 
{
	if (!this->valid())
		throw std::exception();
	TKey k = c.hash[this->currentK].key;
	TValue v = c.hash[this->currentK].values[this->currentV];
	TElem e(k, v);
	return e;
}


//theta(1)


