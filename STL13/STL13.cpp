#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Member {
private:
	string name;
	string tel;
	string address;

public:
	Member() {}
	Member(string name, string tel, string address) {
		this->name = name;
		this->tel = tel;
		this->address = address;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setTel(string tel) {
		this->tel = tel;
	}
	string getTel() {
		return tel;
	}
	void setAddress(string address) {
		this->address = address;
	}
	string getAddress() {
		return address;
	}
	void printMember() {
		cout << "name:" << name << ", tel:" << tel << ", address:" << address
			<< endl;
	}

	friend bool operator ==(Member m1, Member m2) {
		return (m1.name == m2.name) ? true : false;
	}

};

void printMenu() {
	cout << "menu" << endl;
	cout << "1. ADD" << endl;
	cout << "2. SEARCH" << endl;
	cout << "3. EDIT" << endl;
	cout << "4. DELETE" << endl;
	cout << "5. PRINT_ALL" << endl;
	cout << "6. DELETE_ALL" << endl;
	cout << "7. EXIT잭" << endl;
}

Member input() {
	string name, tel, address;
	cout << "이름:";
	cin >> name;
	cout << "전화번호:";
	cin >> tel;
	cout << "주소:";
	cin >> address;
	Member m(name, tel, address);
	return m;
}

int main() {
	int i, menu;
	bool flag = true;
	string name, tel, address;
	vector<Member> data;
	vector<Member>::iterator it;

	while (flag) {
		printMenu();
		cin >> menu;
		switch (menu) {
		case 1: //ADD 
			data.push_back(input());
			cout << "New information is added" << endl;
			break;
		case 2:
			cout << "Name to search:";
			cin >> name;
			it = find_if(data.begin(), data.end(), [name](Member m) { return m.getName() == name; });
			if (it != data.end()) {
				cout << "info found under name: " << name << endl;
				it->printMember();
			}
			break;
		case 3:
			cout << "수정할 사람 이름:";
			cin >> name;
			//todo
			break;
		case 4:
			cout << "삭제할 사람 이름:";
			cin >> name;
			//todo
			break;
		case 5:
			//todo
			break;
		case 6:
			//todo
			break;
		case 7:
			flag = false;
			break;
		default:
			cout << "다시입력하라" << endl;
		}
	}

	return 0;
}
