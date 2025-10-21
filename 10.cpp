#include <iostream>
using namespace std;

//Abstract base class
class Shape {
    public:
        //CREATING  virtual function
        virtual double area() = 0;
        //Putting a virtual destructor is good practice for base classes : NOTE
        virtual ~Shape() {}
};

// Derived class NO.1

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}
        // Provide implementation for the pure virtual function
        double area() override {
            return 3.14159 * radius * radius;
        }
};

// Derived class - 2

class Square : public Shape {
    private:
        double side;
    public:
        Square(double s) : side(s) {}
        // Provide implementation for the pure virtual function
        double area() override {
            return side * side;
        }
};

//A function that works with any shape
void printArea(Shape* s) {
    cout << "The area is: " << s->area() << endl;
}

int main() {
    //Cannot create an object of an abstract class
    //  Shape s; // This would cause a compile error

    Circle c(10.0);
    Square sq(5.0);
    printArea(&c);
    printArea(&sq);

    return 0;
}