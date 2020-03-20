#include <iostream>
#include "MultiMap.h"
using namespace std;

void MultiMap::resize()
{
	SLLANode* newElems = new SLLANode[slla.capacity * 2];
	for (int i = 0; i < this->slla.capacity; i++)
		newElems[i] = this->slla.elementsList[i];

	for (int i = this->slla.capacity; i < this->slla.capacity * 2 - 1; i++)
		newElems[i].next = i + 1;

	newElems[this->slla.capacity * 2 - 1].next = -1;
	this->slla.firstEmpty = this->slla.capacity;
	this->slla.capacity *= 2;
	this->slla.elementsList = newElems;
}

MultiMap::MultiMap() //theta(1)
{
	this->slla.capacity = 10;
	this->slla.size = 0;
	this->slla.elementsList = new SLLANode[this->slla.capacity];
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		this->slla.elementsList[i].next = i + 1;
		this->slla.elementsList[i].element.first = NULL;
		this->slla.elementsList[i].element.second = NULL;
	}
	this->slla.elementsList[i].next = -1;
	this->slla.head = -1;
	this->slla.firstEmpty = 0;
}


void MultiMap::add(TKey c, TValue v) //O(n)
{
	TElem el;
	el.first = c;
	el.second = v;

	//if first to add
	if (this->isEmpty() == true)
	{
		this->slla.elementsList[this->slla.firstEmpty].element = el; 
		this->slla.head = this->slla.firstEmpty;
		this->slla.firstEmpty = this->slla.elementsList[this->slla.firstEmpty].next;
		this->slla.elementsList[this->slla.head].next = -1;
		this->slla.size++;
		return;
	}

	//resize
	if (this->slla.size >= this->slla.capacity)
		resize();
	
	//else
	int x = this->slla.elementsList[this->slla.firstEmpty].next;
	int k = 1;
	
	int i = this->slla.elementsList[this->slla.head].next;
	int j = this->slla.head;

	//we go to the -1 position to the firstEmpty element
	while (i != -1 && k < this->slla.size)
	{	
		i = this->slla.elementsList[i].next;
		j = this->slla.elementsList[j].next;
		k++;
	}

	this->slla.elementsList[j].next = this->slla.firstEmpty; 
	this->slla.elementsList[this->slla.firstEmpty].element = el;
	this->slla.elementsList[this->slla.firstEmpty].next = -1;
	this->slla.firstEmpty = x; 
	this->slla.size++;
}

bool MultiMap::remove(TKey c, TValue v) //O(n)
{
	if (this->search(c) == vector<TValue>{} || this->isEmpty() == true)
		return false;

	//if the head is the element
	if (this->slla.elementsList[this->slla.head].element.first == c && this->slla.elementsList[this->slla.head].element.second == v)
	{
		int a = this->slla.elementsList[this->slla.head].next; 
		this->slla.elementsList[this->slla.head].element.first = NULL;
		this->slla.elementsList[this->slla.head].element.second = NULL;
		this->slla.elementsList[this->slla.head].next = this->slla.firstEmpty;
		this->slla.firstEmpty = this->slla.head;
		this->slla.head = a;
		this->slla.size--;
	}
	else
	{
		 
		int x = this->slla.head;
		int previous = this->slla.elementsList[this->slla.head].next;
		while ((this->slla.elementsList[previous].element.first != c || this->slla.elementsList[previous].element.second != v) && previous != -1)
		{

			x = previous;
			previous = this->slla.elementsList[previous].next;
		}
		if (previous == -1) return false;

		int aux = this->slla.elementsList[x].next;
		this->slla.elementsList[x].next = this->slla.elementsList[previous].next;


		this->slla.elementsList[previous].next = this->slla.firstEmpty;
		this->slla.elementsList[previous].element.first = NULL;
		this->slla.elementsList[previous].element.second = NULL;

		this->slla.firstEmpty = aux;
		this->slla.size--;
	}
	return true;
}


vector<TValue> MultiMap::search(TKey c) const //O(n) n=size
{
	vector<TValue> vector{};
	int i = this->slla.head;
	while (i != -1)
	{
		if (this->slla.elementsList[i].element.first == c)
			vector.push_back(this->slla.elementsList[i].element.second);
		i = this->slla.elementsList[i].next;
	}

	return vector;
}

int MultiMap::size() const //Theta(1)
{
	return this->slla.size;
}

bool MultiMap::isEmpty() const //theta(1)
{
	if (this->slla.size > 0)
		return false;
	return true;
}

MultiMapIterator MultiMap::iterator() const //theta(1)
{
	return MultiMapIterator(*this);
}

MultiMap::~MultiMap() //theta(1)
{
	delete this->slla.elementsList;
}

vector<TValue> MultiMap::AllValues() const
{
	vector<TValue> valueBag{};
	int i = this->slla.head;
	while (i != -1)
	{
		valueBag.push_back(this->slla.elementsList[i].element.second);
		i = this->slla.elementsList[i].next;
	}

	return valueBag;
}
