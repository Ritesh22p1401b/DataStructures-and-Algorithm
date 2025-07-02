#include <iostream>
#include <string>
using namespace std;


class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual ~Person() {}
};


class Student : public Person {
private:
    int rollNo;
    string course;

public:
    Student(string n, int a, int r, string c)
        : Person(n, a), rollNo(r), course(c) {}

    void display() override {
        cout << "Student Details:\n";
        cout << "Name: " << name << ", Age: " << age 
             << ", Roll No: " << rollNo << ", Course: " << course << endl;
    }
};


class Faculty : public Person {
private:
    int employeeId;
    string subject;

public:
    Faculty(string n, int a, int id, string sub)
        : Person(n, a), employeeId(id), subject(sub) {}

    void display() override {
        cout << "Faculty Details:\n";
        cout << "Name: " << name << ", Age: " << age 
             << ", Employee ID: " << employeeId << ", Subject: " << subject << endl;
    }
};


int main() {
    
    Student stu("Amit", 21, 102, "Information Technology");
    Faculty fac("Prof. Mehta", 50, 2001, "Physics");

    
    Person* person1 = &stu;
    Person* person2 = &fac;


    person1->display();  
    person2->display();  

    return 0;
}
