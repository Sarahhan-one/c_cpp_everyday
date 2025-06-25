
#include <iostream>
#include <cstring>
using namespace std;

class Product {
public:
    int num; 
    string name; 
    int price; 
    static int cnt;

    Product(string name, int price) : name(name), price(price), num(cnt++) {
        //automatic numbering
        cout << num << "is produced." << endl;

    }

    void print() {
        cout << "num: " << num << endl;
        cout << "name: " << name << endl;
        cout << "price:" << price << endl;
    }
};
int Product::cnt = 1;

class Test2 {
public:
    int a = 10; 
    static int b; 

    //member function - can use both member var and static var
    void func1() {
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }

    //static function - only use static var
    static void func2() {
        cout << "b: " << b << endl;
    }

    //member function - can call both member function and static function
    void func3() {
        func1();
        func2();
    }

    //static function - can call only static function
    static void func4() {
        func2();
    }
};
int Test2::b = 20; 

class Person {
public:
    int age;
    char *name; //no memory

    //constructor 
    Person(int age, const char* name) {
        size_t len = strnlen_s(name, 20);
        this->name = new char[len + 1];
        strcpy_s(this->name,len+1, name);
        this->age = age;
    }
    Person(int age) {
        this->age = age;
    }

    Person() {
        
    }
    ~Person() {
        cout << "call Destructor: release the memory for name" << endl;
        delete[]name;
    }
};
class Point {
private:
    int x;
    int y;
public:
    Point():x(0),y(0) {
       //x=0;
        //y=0;
    }
    Point(int a, int b) :x(a), y(b) {
        //x = a;
        //y = b;
    }
    void printPoint() {
        cout << "x:" << x << endl;
        cout << "y:" << y << endl;
    }
};
class Rectangle {
private:
    //포함관계
    Point p1;
    Point p2;

public:
    Rectangle(int x, int y, int x1, int y1) :p1(x, y), p2(x1, y1) {

    }
    Rectangle(Point& pp, Point& ppp) {
        p1 = pp;
        p2 = ppp;
    }
    /*
    Rectangle(Point pp, Point ppp) {
        p1 = pp;
        p2 = ppp;
    }
    */
    Rectangle(Point *pp, Point *ppp) {
        p1 = *pp;
        p2 = *ppp;
    }
    void printPoints() {
        p1.printPoint();
        p2.printPoint();
    }
};
/*
class SingleTone {
private:
    int x;
    SingleTone(int a) :x(a) {}
    static SingleTone s;
public:
    void printX() {
        cout << "x:" << x << endl;
    }
    static SingleTone getInstance() {
        return s;
    }
};
*/
int main()
{
    cout << "Before creating an object" << endl;
    cout << "Test2::b -> " << Test2::b << endl;
    Test2::func2();
    Test2::func4();

    Test2 tt; 
    cout << "Once the object is created" << endl;
    cout << "tt.a: " << tt.a << endl;
    cout << "Test2::b -> " << Test2::b << endl;
    tt.func1();
    tt.func2();
    tt.func3();
    tt.func4();


    
    //for (int i = 0; i < 5; i++) {
    //    delete (new Test1)->add()->printVal();
    //}

    Product arr[] = { {"aaa", 1000}, {"bbb", 2000}, {"ccc", 3000}, {"ddd", 4000} };
    for (int i = 0; i < 4; i++) {
        arr[i].print();
    }
#if 0
    /*
    SingleTone s = SingleTone::getInstance();
    s.printX();
    */
    Rectangle r1(1, 2, 3, 4);
    cout << "--r1--" << endl;
    r1.printPoints();

    Point po1(10, 20);
    Point po2(30, 40);

    Rectangle r2(po1, po2);
    cout << "--r2--" << endl;
    r2.printPoints();

    Rectangle r3(&po1, &po2);
    cout << "--r3--" << endl;
    r3.printPoints();

    Point p3;
    p3.printPoint();

    Point p4(3, 4);
    p4.printPoint();

    Person p1(12, "aaa");
    cout << "p1.name:" << p1.name << endl;
    cout << "p1.age:" << p1.age << endl;

    Person p2;
    p2.age = 23;
    p2.name = new char[strnlen_s("bbb", 20) + 1];
    strcpy_s(p2.name, strnlen_s("bbb", 20) +1, "bbb");
    cout << "p2.name:" << p2.name << endl;
    cout << "p2.age:" << p2.age << endl;
#endif
}
