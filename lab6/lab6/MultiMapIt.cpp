#include "MultiMapIt.h"

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
	if (this->currentV == this->c.hash[this->currentK].values.size() - 1)
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
	if (this->currentK < this->c.capacity)
		if (this->currentV < int(this->c.hash[this->currentK].values.size()))
			return true;
	return false;
}


//theta(1)
TElem MultiMapIterator::getCurrent() const
{
	if (!this->valid())
		throw std::exception();
	TKey k = c.hash[this->currentK].key;
	TValue v = c.hash[this->currentK].values[this->currentV];
	TElem e{ k,v };
	return e;
}

//O(m - nr of uniqe keys)
TElem MultiMapIterator::remove()
{
	if (!this->valid())
		throw std::exception();
	TElem e = this->getCurrent();

	this->c.hash[this->currentK].values.erase(this->c.hash[this->currentK].values.begin() + this->currentV);
	this->c.length = 1;
	if (this->c.hash[this->currentK].values.size() == 0) //currV was 0
	{
		this->c.hash[this->currentK].key = MY_NULL;
		int i = this->currentK + 1;
		while ((this->c.hash[i].key == MY_NULL || this->c.hash[i].key == DELETED) && i < this->c.capacity)
			i++;
		if (i == this->c.capacity)
			throw std::exception(); //we reached the end
			//return e;
		this->currentK = i;
		this->currentV = 0;
	}


	return e;
}
