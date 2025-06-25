#include <iostream>
#include <vector>
using namespace std; 
//phoneBook class definition 
class Member {
protected:
	string name;
	string phoneNumber;
	string address;
public:
	//constructors
	Member(string name = "", string phoneNumber = "", string address = "") {
		this->name = name;
		this->phoneNumber = phoneNumber;
		this->address = address;
	}

	//Setters 
	void setName(string name) {
		this->name = name;
	}
	void setPhoneNumber(string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}
	void setAddress(string address) {
		this->address = address;
	}

	//Getters
	string getName() const {
		return name;
	}
	string getPhoneNumber() const {
		return phoneNumber;
	}
	string getAddress() const {
		return address;
	}

	//print phone book entry
	void printPhoneBook() { 
		cout << "Entry added: " << name << ", " << phoneNumber << ", " << address << endl;
	}
};

class Dao { //feature to add, search, update phone book
protected:
	vector<Member> entries; //store phone book entries
	//Member* entries[30];
public:
	void addEntry(string name, string phoneNumber, string address) {
		Member m; 
		m.setName(name);
		m.setPhoneNumber(phoneNumber);
		m.setAddress(address);
		entries.push_back(m);
		m.printPhoneBook();
	}
	void searchEntry(string name) { //search for a name in phone book and return phone book entry
		for (const auto& m : entries) {
			if (m.getName() == name) {
				cout << "Entry found: " << m.getName() << ", " << m.getPhoneNumber() << ", " << m.getAddress() << endl;
				return;
			}
		}
		cout << "No entry found for " << name << endl;
	}
	void updateEntry(string name, string newPhoneNumber, string newAddress) {
		for (auto& m : entries) {
			if (m.getName() == name) {
				m.setPhoneNumber(newPhoneNumber);
				m.setAddress(newAddress);
				cout << "Entry updated: " << name << ", " << newPhoneNumber << ", " << newAddress << endl;
				return;
			}
		}
		cout << "No entry found for " << name << endl;
	}
	bool isDuplicate(string name) { //check for duplicate entry
		for (const auto& m : entries) {
			if (m.getName() == name) return true;
		}
		return false;
	}
};

class Service : public Dao { //it gets the entry from a user and put it in the Member and Dao class
public:
	void add(string name, string phoneNumber, string address) {
		if (!isDuplicate(name)) {
			addEntry(name, phoneNumber, address);
		} else {
			cout << "Duplicate entry for " << name << endl;
		}
	}
};

int main() {
	//test the phone book functionality
	Service PB;
	PB.add("Alice", "123", "GUMI");
	PB.add("Bob", "987", "PAJU");
	PB.searchEntry("Alice");
	PB.updateEntry("Alice", "456", "SEOUL");
	PB.searchEntry("Alice");
	PB.searchEntry("Charlie"); // should not find this entry
	PB.add("Alice", "444", "DAEGU"); // should warn about duplicate

}