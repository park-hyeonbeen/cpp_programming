#include "DoublyLinkedList.h"
#include "Iterator.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {
	pFirst = NULL;
	pLast = NULL;
	length = 0;
};
DoublyLinkedList::DoublyLinkedList(NodeType* _pFirst, NodeType* _pLast, int _length) {
	pFirst = _pFirst;
	pLast = _pLast;
	length = _length;
};

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list) {
	pFirst = list.GetFirst();
	pLast = list.GetLast();
	length = list.GetLength();
};
DoublyLinkedList::DoublyLinkedList(int _length) {
	pFirst = NULL;
	pLast = NULL;
	length = _length;
};
bool DoublyLinkedList::IsEmpty() {
	if (length == 0)
		return true;
	else
		return false;
};
void DoublyLinkedList::MakeEmpty() {
	NodeType* pItem;
	Iterator itor(*this);
	while (itor.NotNull())
	{
		pItem = itor.GetpCurPointer();
		itor.Next();
		delete pItem;
	}
	this->pFirst = NULL;
	this->pLast = NULL;
	this->length = 0;
	return;
};
int DoublyLinkedList::GetLength() const{
	return length;
} ;

NodeType* DoublyLinkedList::GetFirst() const {
	return pFirst;
};
NodeType* DoublyLinkedList::GetLast() const {
	return pLast;
};
void DoublyLinkedList::setLength(int _length) {
	length = _length;
};
void DoublyLinkedList::setFirst(NodeType* _First) {
	pFirst = _First;
};
void DoublyLinkedList::setLast(NodeType* _Last) {
	pLast = _Last;
};

int DoublyLinkedList::Add(ItemType item) {
	Iterator itor(*this);
	if (length == 0) {
		NodeType* temp = new NodeType(item, NULL, NULL);
		pFirst = temp;
		pLast = temp;
		length++;
		return 1;
	}
	else if (item.getid() < pFirst->data.getid()) {
		NodeType* temp = new NodeType(item, NULL, pFirst);
		pFirst->prev =temp;
		pFirst = temp;
		length++;
		return 1;
	}
	else if (item.getid() > pLast->data.getid()) {
		NodeType* temp = new NodeType(item, pLast, NULL);
		pLast->next = temp;
		pLast = temp;
		length++;
		return 1;
	}
	else{
		while (itor.NextNotNull()) {
			if (itor.GetpCurPointer()->data.getid() < item.getid() && item.getid() < itor.Next().getid()) {
				NodeType* temp = new NodeType(item, itor.GetpCurPointer()->prev, itor.GetpCurPointer());
				itor.GetpCurPointer()->prev->next = temp;
				itor.GetpCurPointer()->prev = temp;
				length++;
				return 1;
			}
		}
		itor.SetpCurPo(pFirst);
		while (itor.NotNull()) {
			if (itor.GetpCurPointer()->data.getid() == item.getid()) {
				std::cout << "error!";
				return 0;
			}
			itor.Next();
		}
		}
};
int DoublyLinkedList::Delete(ItemType item) {
	if(!IsEmpty())
	{Iterator itor(*this);
	if (pFirst->data.getid() == item.getid()) {
		NodeType* temp = pFirst;
		length--;
		pFirst = pFirst->next;
		if (!IsEmpty())
			pFirst->prev = NULL;
		delete temp;
		return 1;
	}
	else if (pLast->data.getid() == item.getid()) {
		NodeType* temp = pLast;
		length--;
		pLast = pLast->prev;
		if (!IsEmpty())
			pLast->next = NULL;
		delete temp;
		return 1;
	}
	while (itor.NotNull()) {
		if (itor.GetCurrentNode().data.getid() == item.getid()) {
			itor.GetpCurPointer()->prev->next = itor.GetpCurPointer()->next;
			itor.GetpCurPointer()->next->prev = itor.GetpCurPointer()->prev;
			length--;
			delete itor.GetpCurPointer();
			return 1;
		}
		itor.Next();
	}
}
	return 0;
};
int DoublyLinkedList::Replace(ItemType item) {
	Iterator itor(*this);
	while(itor.NotNull()){
		if (itor.GetCurrentNode().data.getid() ==item.getid()) {
			itor.GetpCurPointer()->data = item;
			return 1;
		}
		itor.Next();
	}
	return 0;
};
int DoublyLinkedList::Get(ItemType& item) {
	Iterator itor(*this);
	while (itor.NotNull()) {
		if (itor.GetCurrentNode().data.getid() == item.getid()) {
			item = itor.GetCurrentNode().data;
			return 1;
		}
		itor.Next();
	}
	return 0;
};