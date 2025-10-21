#include <iostream>
#include <string>

using namespace std;

//Person - Base class
class Person {
    protected:
        string name;

    public:
        void setName(string n) {
            name = n;
        }
};

//Intermediate derived class
class Employee : public Person {
    protected:
        int employeeID;

    public:
        void setEmployeeID(int id) {
            employeeID = id;
        }
};

// Derived from Employee
class Manager : public Employee {
    private:
        string department;

    public:
        void setDepartment(string dept) {
            department = dept;
        }

        void display() {
            cout << "Name: " << name << endl; // Accessing Person's member
            cout << "Employee ID: " << employeeID << endl; // Accessing Employee's member
            cout << "Department: " << department << endl; // Accessing own member
        }
};

int main() {
    Manager mgr;
    mgr.setName("Srivarshan");
    mgr.setEmployeeID(501);
    mgr.setDepartment("CSDS");

    mgr.display();
    return 0;
}