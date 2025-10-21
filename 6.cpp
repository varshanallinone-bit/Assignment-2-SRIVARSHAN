#include <iostream>
using namespace std;

class Sports; // Forward declaration of Sports class

class Student {
    private:
        int marks;

    public:
        Student(int m) : marks(m) {}
        // Declare the friend function
        friend void combineData(Student s, Sports sp);
};

class Sports {
    private:
        int score;

    public:
        Sports(int s) : score(s) {}
        // Declare the friend function
        friend void combineData(Student s, Sports sp);
};

// Friend function definition
void combineData(Student s, Sports sp) {
    // It can access private members of both classes
    cout << "Student Marks: " << s.marks << endl;
    cout << "Sports Score: " << sp.score << endl;
    cout << "Combined Total: " << s.marks + sp.score << endl;
}

int main() {
    Student student1(85);
    Sports sports1(90);
    combineData(student1, sports1);
    return 0;
}