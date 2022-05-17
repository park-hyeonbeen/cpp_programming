#include "ItemType.h"



ItemType::ItemType() {
	id = -1;
	name = "";
};
ItemType::ItemType(const int& _id) {
	id = _id;
	name = "";
};
ItemType::ItemType(const int& _id, const std::string& _name) {
	id = _id;
	name = _name;
};
ItemType::ItemType(const std::string& _name) {
	id = -1;
	name = _name;
};
ItemType::ItemType(const ItemType& IT) {
	id = IT.getid();
	name = IT.getname();
};


int ItemType::getid() const { 
	return id; }
;
std::string ItemType::getname() const {
	return name;
} ;
void ItemType::setid(const int& _id) {
	id = _id;
};
void ItemType::setname(const std::string& _name) {
	name = _name;
};

bool ItemType::operator>(const ItemType& IT)  const {
	if (id > IT.getid())
		return true;
	else
		return false;
};

bool ItemType::operator<(const ItemType& IT)  const {
	if (id < IT.getid())
		return true;
	else
		return false;
};

bool ItemType::operator==(const ItemType& IT) const {
	if (id == IT.getid())
		return true;
	else
		return false;
};

bool ItemType::operator=(const ItemType& IT) {
	id = IT.getid();
	name = IT.getname();
	return true;
};