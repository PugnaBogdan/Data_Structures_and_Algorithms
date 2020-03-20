//ADT MultiMap – using a SLLA with(key, value) pairs.
//A key can appear in multiple pairs. Pairs do not have to be ordered.

#pragma once
#include<vector>
#include<utility>

#include "MultiMapIt.h"

#define NULL_TKEY 0

using namespace std;

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

class MultiMap
{
	friend class MultiMapIterator;
private:

	struct SLLANode 
	{

		int next;
		TElem element;
	}sllNode;

	struct SLLA 
	{
		int capacity, size;
		int firstEmpty, head;
		SLLANode* elementsList;
	}slla;

	void resize();

public:

	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//descturctor
	~MultiMap();

	vector<TValue> AllValues() const;
};
