#pragma once
#include "MultiMap.h"
typedef int TKey;

typedef int TValue;

typedef std::pair<TKey, TValue> TElem;


class MultiMapIterator
{
	friend class MultiMap;
private:
	//Constructor receives a reference of the container.

	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

	MultiMapIterator(const MultiMap& _c);



	//contains a reference of the container it iterates over

	const MultiMap& c;



	/* representation specific for the iterator*/
	int currentK;  //index for keys
	int currentV; //index for values


public:



	//sets the iterator to the first element of the container

	void first();
	//moves the iterator to the next element

	//throws exception if the iterator is not valid

	void next();
	//checks if the iterator is valid
	bool valid() const;

	TElem getCurrent() const ;
};

