#pragma once
#include "ItemType.h"

struct NodeType {
	ItemType data;
	NodeType* prev;
	NodeType* next;
	NodeType(ItemType _data, NodeType* _prev, NodeType* _next) {
		data = _data;
		prev = _prev;
		next = _next;
	};
};

class DoublyLinkedList {
private:
	NodeType *pFirst;
	NodeType *pLast;
	int length;

public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& list);
	DoublyLinkedList(NodeType* _pFirst, NodeType* _pLast, int _length);
	DoublyLinkedList(int _length);
	~DoublyLinkedList() {};
	bool IsEmpty();
	void MakeEmpty();
	int GetLength() const;
	NodeType* GetFirst() const;
	NodeType* GetLast() const;
	void setLength(int _length);
	void setFirst(NodeType* _First);
	void setLast(NodeType* _Last);
	int Add(ItemType item);
	int Delete(ItemType item);
	int Replace(ItemType item);
	int Get(ItemType& item);

};
