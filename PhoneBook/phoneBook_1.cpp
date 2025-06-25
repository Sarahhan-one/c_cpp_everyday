#include <iostream>
using namespace std;
class Member {
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
    string getName() {
        return name;
    }
    void setTel(string tel) {
        this->tel = tel;
    }
    void setAddress(string address) {
        this->address = address;
    }
    void print() {
        cout << "name:" << name << endl;
        cout << "tel:" << tel << endl;
        cout << "address:" << address << endl;
    }
};
class MemDao {
    Member* arr[30];
public:
    int cnt = 0;
    void insert(Member* m) {
        if (cnt >= 29) {
            cout << "array is full" << endl;
            return;
        }
        arr[cnt++] = m;
    }
    int selectByName(string name) {
        int i;
        for (i = 0; i < cnt; i++) {
            if (name == arr[i]->getName()) {
                return i;
            }
        }
        return -1;
    }

    Member* selectByIdx(int idx) {
        if (idx >= cnt || idx < 0) {
            cout << "wrong index" << endl;
            return NULL;
        }
        else {
            return arr[idx];
        }
    }

    bool update(Member* m) {
        int idx = selectByName(m->getName());
        if (idx < 0) {
            return false;
        }

		delete arr[idx];//delete old object
		arr[idx] = m; //insert new object
        return true;
    }

    bool del(string name) {
        int idx = selectByName(name);
        if (idx < 0) {
            return false;
        }
        cout << "object deleted" << endl;
        arr[idx]->print();

        delete arr[idx];
        for (int i = idx; i < cnt - 1; i++) {
            arr[i] = arr[i + 1];
        }
        cnt--;
    }
	//delete all objects
    void delAll() {
        for (int i = 0; i < cnt; i++) {
            delete arr[i];
        }
    }
};
//provides service to user
class Service {
    MemDao dao;
public:
    void add() {
        cout << "add" << endl;
        string name;
        cout << "name:";
        cin >> name;
        int idx;
        while ((idx = dao.selectByName(name)) >= 0) {
            cout << "name already exists." << endl;
            cin >> name;
        }
        string tel;
        cout << "tel:";
        cin >> tel;

        string address;
        cout << "address:";
        cin >> address;

        dao.insert(new Member(name, tel, address));
    }

    void printAll() {
        cout << "list" << endl;
        for (int i = 0; i < dao.cnt; i++) {
            dao.selectByIdx(i)->print();
        }
    }

    void getByName() {
        cout << "search by name" << endl;
        string name;
        cout << "name:";
        cin >> name;
        Member* m = dao.selectByIdx(dao.selectByName(name));
        if (m != NULL) {
            m->print();
        }
    }

    void edit() {
        cout << "edit" << endl;
        string name;
        cout << "name:";
        cin >> name;
        string tel;
        cout << "new tel:";
        cin >> tel;
        string addr;
        cout << "new address:";
        cin >> addr;
        if (dao.update(new Member(name, tel, addr))) {
            cout << "edit complete" << endl;
        }
        else {
            cout << "edit cancel" << endl;
        }
    }
    void del() {
        cout << "delete" << endl;
        string name;
        cout << "name:";
        cin >> name;
        if (dao.del(name)) {
            cout << "delete complete" << endl;
        }
        else {
            cout << "delete cancel" << endl;
        }
    }
    void delAll() {
        dao.delAll();
    }
};
int main()
{
    Service s;
    bool flag = true;
    int x;
    while (flag) {
        cout << "1.add 2.search 3.edit 4.delete 5.list 6.exit" << endl;
        cin >> x;
        switch (x) {
        case 1:
            s.add();
            break;
        case 2:
            s.getByName();
            break;
        case 3:
            s.edit();
            break;
        case 4:
            s.del();
            break;
        case 5:
            s.printAll();
            break;
        case 6:
            flag = false;
            s.delAll();
            break;
        }
    }
}