#include "Iterator.h"


const DoublyLinkedList& Iterator::GetDList() {
	return dList;
};

NodeType* Iterator::GetpCurPointer() {
	return pCurPointer;
};
void Iterator::SetpCurPo(NodeType* _pCurPointer) {
	pCurPointer = _pCurPointer;
};
bool Iterator::NotNull() {
	if (pCurPointer!= NULL)
		return true;
	else
		return false;
};
bool Iterator::NextNotNull() {
	if (pCurPointer->next != NULL)
		return true;
	else
		return false;

};
bool Iterator::PrevNotNull() {
	if (pCurPointer->prev != NULL)
		return true;
	else
		return false;
};
ItemType Iterator::First() {
	return dList.GetFirst()->data;

};
ItemType Iterator::Next() {
	pCurPointer = pCurPointer->next;
	if (NotNull())
		return pCurPointer->data;
	else
		return ItemType();
};
ItemType Iterator::Prev() {
	pCurPointer = pCurPointer->prev;
	if (NotNull())
		return pCurPointer->data;
	else
		return ItemType();
};
NodeType Iterator::GetCurrentNode() {
	return *pCurPointer;
};
