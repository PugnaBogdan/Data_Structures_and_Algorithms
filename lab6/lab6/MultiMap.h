#pragma once
#include "MultiMapIt.h"
#include<vector>
#include<utility>

#include <limits.h>

using namespace std;


typedef int TKey;

typedef int TValue;

#define NULL_TVALUE -1
#define INF 1000000


#define DELETED INT_MAX
#define MY_NULL INT_MIN


typedef std::pair<TKey, TValue> TElem;

struct TItem {
	TKey key;
	int len, cap;
	vector <TValue> values;
};

class MultiMap

{
	friend class MultiMapIterator;

private:

	/* representation of the MultiMap */

	TItem* hash;
	int capacity, length;
	
	//hash Functions

	int hCode(TKey k) const ;
	TKey h1(TKey k) const ;
	TKey h2(TKey k) const;
	int h(TKey k, int i) const ;

	

	//functions for finding M (the next prim number)

	void resize();
	int firstPrimeGreaterThan(int x);
	bool prim(int x);

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

	MultiMapIterator iterator();



	//descturctor

	~MultiMap();





};


