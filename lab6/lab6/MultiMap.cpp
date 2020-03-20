#include "MultiMap.h"
#include "MultiMapIt.h"
#include <cmath>


MultiMap::~MultiMap()
{
}

int MultiMap::hCode(TKey k) const
{
	return abs(int(k));
}

TKey MultiMap::h1(TKey k) const
{
	return hCode(k) % this->capacity;
}

TKey MultiMap::h2(TKey k) const
{
	return 1 + (hCode(k) % (this->capacity - 1));
}

int MultiMap::h(TKey k, int i) const
{
	return (h1(k) + i * h2(k)) % this->capacity;
}

int MultiMap::firstPrimeGreaterThan(int x)
{
	x++;
	while (!prim(x))
		x++;
	return x;
}

bool MultiMap::prim(int x)
{
	if (x < 2 || x>2 && x % 2 == 0)
		return false;
	for (int d = 3; d*d <= x; d += 2)
		if (x%d == 0)
			return false;
	return true;
}


MultiMap::MultiMap()
{
	this->capacity = 13;
	this->length = 0;
	this->hash = new TItem[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		this->hash[i].key = MY_NULL;
		this->hash[i].len = 0;
		this->hash[i].cap = 100;
	}

}

void MultiMap::add(TKey c, TValue v)
{
	if (this->length == this->capacity) {
		resize();
	}
	int i = 0;
	int pos = h(c, i);

	while (i < this->capacity && this->hash[pos].key != MY_NULL && this->hash[pos].key != c)
	{
		i++;
		pos = h(c, i);
	}

	if (this->hash[pos].key == c)
	{
		this->hash[pos].values[this->hash[pos].len] = v;
		this->hash[pos].len++;
		this->length++;
	}
	else
	{
		if (i == this->capacity)       //if ((float)this->nrElems / this->m > 0.75)// ->if load factor is 0.75 => 1/(1-0.75) = 1/0.25 = 4 maximum steps (nr maxim de verificari) for unsuccesfull search and add(insert)
		{
			//if we need resize
			this->resize();
			this->add(c, v);
		}
		else
		{
			//if we do not need resize
			//we put on the position pos the key with its value
			this->hash[pos].key = c;
			this->hash[pos].values[this->hash[pos].len] = v;
			this->length++;
		}
	}
}

bool MultiMap::remove(TKey c, TValue v)
{
	int i = 0;
	int pos = this->h(c, i); //find the position of the key if it exits
	while (i < this->capacity && this->hash[pos].key != MY_NULL && this->hash[pos].key != c)
	{
		i++;
		pos = this->h(c, i);
	}
	if (this->hash[pos].key == c)

	{
		int pos_of_val;
		for (size_t i = 0; i < this->hash[pos].values.size(); i++)
			if (v == this->hash[pos].values[i]) pos_of_val = i;
		if (pos_of_val == int(this->hash[pos].values.size))
		{
			return false; //the pair is not in the map  (the value is not in the list of the key)
		}
		//the pair is in the map
		this->hash[pos].values.erase(this->hash[pos].values.begin()+pos_of_val);
		//verify if the vector of values of k remained empty and mark the position by DELETED
		if (this->hash[pos].values.size() == 0)
			this->hash[pos].key = MY_NULL;
		this->length--;
		return true;
	}
	return false; //the pair key, value was not in the multimap
}

vector<TValue> MultiMap::search(TKey c) const
{
	if (this->size == 0)
	{
		std::vector<TValue> gol;
		return gol;
	}

	int i = 0;
	int pos = h(c,i);

	while (i < this->capacity && this->hash[pos].key != MY_NULL && this->hash[pos].key != c)
	{
		i++;
		pos = h(c, i);
	}
	if (this->hash[pos].key == c)
	{
		// we have that key in the hash, return its list of values
		std::vector<TValue> vct;
		for (size_t j = 0; j < this->hash[pos].values.size(); j++)
			vct.push_back(this->hash[pos].values[j]);
		return vct;
	}
	//we do not have the element in the hash, return an empty vector
	std::vector<TValue> gol;
	return gol;
}

int MultiMap::size() const
{
	return this->size;
}

bool MultiMap::isEmpty() const
{
	return this->size == 0;
}

MultiMapIterator MultiMap::iterator()
{
	return MultiMapIterator(*this);
}


void MultiMap::resize()
{
	/* Resize operation for the hashtable that rehashes the elements. */

}