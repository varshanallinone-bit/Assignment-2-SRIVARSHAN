#include <iostream>
using namespace std;

//Part 1: Function Overloading (Compile-time Polymorphism) ---
class Calculator {
    public:
        int add(int a, int b) { //Overloaded 'add' functions
            cout << "Adding two integers: ";
            return a + b;
        }
        double add(double a, double b) {
            cout << "Adding two doubles: ";
            return a + b;
        }
};

// Function Overriding (Run-time Polymorphism) ---
class Animal {
public:
    // NOTE: 'virtual' keyword enables run-time polymorphism
    virtual void makeSound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
    public:
        //NOTE: 'override' is a good practice to ensure it is overriding a base method
        void makeSound() override {
            cout << "Dog barks: Woof!" << endl;
        }
};

class Cat : public Animal {
    public:
        void makeSound() override {
            cout << "Cat : Meow MEOW!" << endl;
        }
};

int main() {
    cout << "--- Function Overloading ---" << endl;
    Calculator calc;
    cout << calc.add(5, 10) << endl;
    cout << calc.add(3.5, 7.2) << endl;

    cout << "\n--- Function Overriding ---" << endl;
    Animal* myAnimal;
    Dog myDog;
    Cat myCat;
    myAnimal = &myDog;
    myAnimal->makeSound(); // Calls Dog's version at run-time

    myAnimal = &myCat;
    myAnimal->makeSound(); // Calls Cat's version at run-time

    return 0;
}