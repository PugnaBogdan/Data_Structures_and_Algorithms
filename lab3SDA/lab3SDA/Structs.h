#pragma once
typedef int TElem;

typedef struct TComparable {
	TElem element;
	int line;
	int column;

}infoNode;

typedef struct SingleLinkedListNode {
	infoNode info;
	SingleLinkedListNode* next;
}SLLNode;

typedef struct DoubleLinkedList {
	SingleLinkedListNode* head;
	SingleLinkedListNode* tail;
} SLL;

