#pragma once
#include "MultiMap.h"
#include<utility>

using namespace std;
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

class MultiMapIterator {
	friend class MultiMap;

private:
	MultiMapIterator(const MultiMap& c);

	//reference of the container it iterates over
	const MultiMap& c;

	TElem currentElement;
	int currentPosition;

public:
	void first();

	void next();

	bool valid() const;

	TElem getCurrent() const;
};