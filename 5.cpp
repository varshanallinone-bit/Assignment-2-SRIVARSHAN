#include <iostream>
#include <string>
using namespace std;

//Base class - 1
class Person {
    protected:
        string name;
    public:
        Person(string n = "") : name(n) {}
        void display() {
            cout << "Name: " << name << endl;
        }
};

//Base class no :2
class Athlete {
    protected:
        string sport;
    public:
        Athlete(string s = "") : sport(s) {}
        void display() {
            cout << "Sport: " << sport << endl;
        }
};

// Derived class
class SportsPerson : public Person, public Athlete {
    public:
        SportsPerson(string n, string s) : Person(n), Athlete(s) {}

        // Resolve ambiguity by providing an overriding function
        void display() {
            cout << "--- Sports Person Details ---" << endl;
            Person::display();      // Explicitly call Person's display
            Athlete::display();     // Explicitly call Athlete's display
        }
};

int main() {
    SportsPerson sp("Virat", "Cricket");
    sp.display(); // This calls the SportsPerson's display method
    // sp.Person::display(); //To call the base
    return 0;
}