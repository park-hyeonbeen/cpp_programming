#include "Application.h"
#include "Iterator.h"
#include <iostream>

Application::Application() {
	dList = new DoublyLinkedList;
	mCommand = 0;
};
void Application::Run() {
	while (1) {
		mCommand = GetCommand();
		switch (mCommand) {
		case 1:
			AddItem();
			break;
		case 2:
			DeleteItem();
			break;
		case 3:
			UpdateItem();
			break;
		case 4:
			SearchItem();
			break;
		case 5:
			DisplayAllItem();
			break;
		case 6:
			MakeEmptyList();
			break;
		default:
			std::cout << "error!";
		case 0:
                                    MakeEmptyList();
			return;
		}
	}
};
int Application::GetCommand() {
	using namespace std;
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t 1 : Add new item" << endl;
	cout << "\t 2 : Delete item" << endl;
	cout << "\t 3 : Update item" << endl;
	cout << "\t 4 : Search item by ID" << endl;
	cout << "\t 5 : Print all on screen" << endl;
	cout << "\t 6 : Make empty list" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;

};
int Application::AddItem() {
	using namespace std;
	int id;
	string name;
	std::cout << "id:";
	std::cin >> id;
	std::cout << "name:";
	std::cin >> name;
	if (dList->Add(ItemType(id, name)))
		return 1;
	return 0;
};
int Application::DeleteItem() {
	using namespace std;
	int key;
	std::cout << "id:";
	cin >> key;
	if (dList->Delete(ItemType(key)))
		return 1;
	return 0;
};
int Application::UpdateItem() {
	int key;
	std::string name;
	std::cout << "id:";
	std::cin >> key;
	std::cout << "name:";
	std::cin>> name;
	if(dList->Replace(ItemType(key,name)))
		return 1;
	return 0;
};
int Application::SearchItem() {
	int key;
	ItemType item;
	std::cout << "id: ";
	std::cin >> key;
	item.setid(key);
	if (dList->Get(item)) {
		std::cout <<"id: "<< item.getid();
		std::cout <<" name: "<< item.getname();
		return 1;
	}
	return 0;
};

void Application::DisplayAllItem() {
	Iterator itor(*dList);
	while (itor.NotNull()) {
		std::cout << " id: " << itor.GetCurrentNode().data.getid();
		std::cout << " name: " << itor.GetCurrentNode().data.getname();
		itor.Next();
	}
};
void Application::MakeEmptyList() {
	dList->MakeEmpty();
};