#pragma once
#include <string>

class ItemType {
private:
	int id;
	std::string name;
public:
	ItemType();
	ItemType(const int& _id);
	ItemType(const int& _id, const std::string& _name);
	ItemType(const std::string& _name);
	ItemType(const ItemType& IT);
	~ItemType() {};
	int getid() const;
	std::string getname() const;
	void setid(const int& _id);
	void setname(const std::string& _name);
	bool operator>(const ItemType& IT) const;
	bool operator<(const ItemType& IT) const;
	bool operator==(const ItemType& IT) const;
	bool operator=(const ItemType& IT);

};