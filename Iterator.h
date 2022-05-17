#pragma once
#include "DoublyLinkedLIst.h"
class Iterator {
private:
	const DoublyLinkedList& dList;
	NodeType * pCurPointer;
public:
	Iterator(const DoublyLinkedList& list):dList(list)
	{ pCurPointer = dList.GetFirst();
	};
	~Iterator() {};
	const DoublyLinkedList& GetDList();
	NodeType* GetpCurPointer();
	void SetpCurPo(NodeType* _pCurPointer);
	bool NotNull();
	bool NextNotNull();
	bool PrevNotNull();
	ItemType First();
	ItemType Next();
	ItemType Prev();
	NodeType GetCurrentNode();

};