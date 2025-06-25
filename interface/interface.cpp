#include <iostream>
using namespace std;

//DB parent class definition
class DB {
public:
	virtual void select() = 0;
	virtual void insert() = 0;
	virtual void update() = 0;
	virtual void del() = 0;
};

//Oracle DB Class definition
class OracleDao : public DB {
public: 
	void select() override {
		cout << "Oracle select" << endl;
	}
	void insert() override {
		cout << "Oracle insert" << endl;
	}
	void update() override {
		cout << "Oracle update" << endl;
	}
	void del() override {
		cout << "Oracle delete" << endl;
	}
};

//MySQL DB Class definition
class MySqlDao : public DB {
public:
	void select() override {
		cout << "MySQL select" << endl;
	}
	void insert() override {
		cout << "MySQL insert" << endl;
	}
	void update() override {
		cout << "MySQL update" << endl;
	}
	void del() override {
		cout << "MySQL delete" << endl;
	}

};

//Service class definition
class Service {
	DB* db; 
public: 
	Service(DB* db) {
		this->db = db; 
	}
	void add() {
		cout << "add service" << endl;
		db->insert();
	}
	void get() {
		cout << "get service" << endl;
		db->select();
	}
	void edit() {
		cout << "edit service" << endl;
		db->update();
	}
	void del() {
		cout << "delete service" << endl;
		db->del();
	}
};

int main() {
	Service s(new OracleDao);
	s.add();
	s.get();
	s.edit();
	s.del();
}