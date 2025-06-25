#include <iostream>
using namespace std;

class PocketMon {
protected:
	string name;
	int hp;
	int exp;
	int lv;
	
public:
	// pure virtual function
	virtual void eat() = 0;
	virtual void sleep() = 0;
	virtual bool play() = 0;
	virtual bool exc() = 0;
	virtual bool lvCheck() = 0;

	virtual void printStatus() {
		cout << name << "checks status" << endl;
		cout << "hp: " << hp << endl;
		cout << "exp: " << exp << endl;
		cout << "level: " << lv << endl;
	}
};

class Pikachu : public PocketMon {
public: 
	Pikachu() {
		cout << "creates Pikachu" << endl;
		name = "Pikachu";
		hp = 30;
		exp = 0; 
		lv = 1; 
	}
	
	void eat() {
		hp += 5; 
	}
	void sleep() {
		hp += 10;
	}
	bool play() {
		hp -= 8;
		exp += 5; 
		if (lvCheck()) {
			cout << name << "'s level is upgraded!" << endl;
		}
		return hp > 0;
	}
	bool exc() {
		hp -= 14;
		exp += 10;
		if (lvCheck()) {
			cout << name << "'s level is upgraded!" << endl;
		}
		return hp > 0;
	}

	bool lvCheck() {
		if (exp >= 20) {
			lv++; 
			exp -= 20;
			return true;
		}
		return false; 
	}

	void elec() {
		cout << name << "thunder attack" << endl;
	}
};

class Gobook : public PocketMon {
public:
	Gobook() {
		cout << "creates Gobook" << endl;
		name = "Gobook";
		hp = 30;
		exp = 0;
		lv = 1;
	}

	void eat() {
		hp += 5;
	}
	void sleep() {
		hp += 10;
	}
	bool play() {
		hp -= 8;
		exp += 5;
		if (lvCheck()) {
			cout << name << "'s level is upgraded!" << endl;
		}
		return hp > 0;
	}
	bool exc() {
		hp -= 14;
		exp += 10;
		if (lvCheck()) {
			cout << name << "'s level is upgraded!" << endl;
		}
		return hp > 0;
	}

	bool lvCheck() {
		if (exp >= 20) {
			lv++;
			exp -= 20;
			return true;
		}
		return false;
	}

	void water() {
		cout << name << "Water cannon attack" << endl;
	}
};

class Lee : public PocketMon {
public:
	Lee() {
		cout << "creates LeeSangHaeSsi" << endl;
		name = "Lee";
		hp = 30;
		exp = 0;
		lv = 1;
	}

	void eat() {
		hp += 5;
	}
	void sleep() {
		hp += 10;
	}
	bool play() {
		hp -= 8;
		exp += 5;
		if (lvCheck()) {
			cout << name << "'s level is upgraded!" << endl;
		}
		return hp > 0;
	}
	bool exc() {
		hp -= 14;
		exp += 10;
		if (lvCheck()) {
			cout << name << "'s level is upgraded!" << endl;
		}
		return hp > 0;
	}

	bool lvCheck() {
		if (exp >= 20) {
			lv++;
			exp -= 20;
			return true;
		}
		return false;
	}

	void nuncool() {
		cout << name << "Nuncool attack" << endl;
	}
};

class Menu {
private: 
	PocketMon* p;

public:
	void run() {
		cout << "Choose your Pocketmon!" << endl;
		cout << "1. Pikachu (Default) 2. Gobook 3. LeeSangHaeSsi" << endl;
		int ch = 0;
		cin >> ch; 
		switch (ch) {
		case 2: 
			p = new Gobook; 
			break;
		case 3:
			p = new Lee;
			break; 
		default:
			p = new Pikachu;
			break;
		}

		bool flag = true; 
		int m; 
		while (flag) {
			cout << "1.Eat 2.Sleep 3.Play 4.Exercise 5. Print Status 6.Exit 7.Attack" << endl;
			cin >> m; 
			switch (m) {
			case 1:
				p->eat();
				break;
			case 2: 
				p->sleep();
				break;
			case 3: 
				flag = p->play();
				break;
			case 4: 
				flag = p->exc();
				break;
			case 5: 
				p->printStatus();
				break;
			case 6:
				flag = 0;
				break;
			case 7: 
				if (typeid(*p) == typeid(Pikachu)) {
					((Pikachu*)p)->elec();
				} 
				else if (typeid(*p) == typeid(Gobook)) {
					((Gobook*)p)->water();
				}
				else if (typeid(*p) == typeid(Lee)) {
					((Lee*)p)->nuncool();
				}
				break;
			}
		}
	}
};

//upcasting: moves up the inheritance hierarchy,from a derived type to a general type. 
class Parent {
public:
	void sayHello() {
		cout << "parent hello" << endl;
	}

	virtual void sayHello2() { //put virtual on function we want to override
		cout << "virtual parent hello" << endl;
	}
};

class Child : public Parent {
public:
	int a = 10; 
	void sayHello() { //overriding
		cout << "child hello" << endl;
	}
	 
	virtual void sayHello2() { 
		cout << "virtual child hello" << endl;
	}

	void print() {
		cout << "function integrated to child" << endl;
	}
};

int main() {
#if 1
	Menu m; 
	m.run();
#endif 

#if 0
	Parent* p1 = new Parent; 
	p1->sayHello(); 
	Child* c1 = new Child; 
	c1->sayHello();

	// upcasting : object is Child and type is Parent
	Parent* p2 = new Child; 
	p2->sayHello(); // static invocation - decision is made during compiling - always follow the type
	p2->sayHello2(); // dynamic invocation - decision is made during runtime - always follow the object

	//if the type is parent, you can only use the member defined by parent class 
	//cout << p2->a << endl;  <= we can't use
	//do the downcasting instead - You need casting operator! 
	cout << ((Child*)p2)->a << endl;
	((Child*)p2)->print();

	if (typeid(*p1) == typeid(Parent)) {
		cout << "Type for p1 : parent" << endl;
	}
	else if (typeid(*p1) == typeid(Child)) {
		cout << "Type for p1 : child" << endl; 
	}
	if (typeid(*p2) == typeid(Parent)) {
		cout << "Type for p2 : parent" << endl;
	}
	else if (typeid(*p2) == typeid(Child)) {
		cout << "Type for p2 : child" << endl;
	}
#endif
}