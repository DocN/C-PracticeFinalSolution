#pragma once
#include <vector>
class AccountDynamic {
private:
	std::vector<double> * balance;
	std::string * name;
public:
	//constructor
	AccountDynamic() {
		balance = new std::vector<double>();
		name = new std::string("value");
	}
	//destructor
	~AccountDynamic() {
		delete name;
		delete balance;
	}
	//copy constructor
	AccountDynamic(const AccountDynamic & other) {
		std::vector<double> realBalance = *other.balance;
		balance = &realBalance;
		std::string realName = *other.name;
		name = &realName;
	}

	//copy assignment
	AccountDynamic & operator=(const AccountDynamic & other) {
		delete balance;
		delete name;
		balance = new std::vector<double>();
		for (int i = 0; i < other.balance->size(); i++) {
			balance->push_back(other.balance->at(i));
		}
		std::string newName = *other.name;
		name = &newName;
		return *this;
	}

	//move constructor
	AccountDynamic(AccountDynamic && other) {
		balance = other.balance;
		other.balance = nullptr;
		name = other.name;
		other.name = nullptr;
	}

	//move assignment
	AccountDynamic & operator=(AccountDynamic && other) {
		delete balance;
		delete name;
		this->balance = other.balance;
		this->name = other.name;
		other.balance = nullptr;
		other.name = nullptr;
		return *this;
	}
};