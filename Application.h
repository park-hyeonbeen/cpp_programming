#pragma once
#include "DoublyLinkedList.h"
class Application {
private:
	DoublyLinkedList* dList;
	int mCommand;
public:
	Application();
	~Application() {
		delete dList;
	};
	void Run();
	int GetCommand();
	int AddItem();
	int DeleteItem();
	int UpdateItem();
	int SearchItem();
	void DisplayAllItem();
	void MakeEmptyList();

};