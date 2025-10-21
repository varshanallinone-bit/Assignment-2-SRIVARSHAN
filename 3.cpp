#include <iostream>
using namespace std;

//Shape - Base class : containing protected variables
class Shape {
    protected:
        int width;
        int height;

    public:
        void setDimensions(int w, int h) {
            width = w;
            height = h;
        }
};

//Rectangle - Derived class
class Rectangle : public Shape {
    public:
        int calculateArea() {
            return width * height;
        }
        int calculatePerimeter() {
            return 2 * (width + height);
        }
};

int main() {
    Rectangle rect;
    rect.setDimensions(10, 5);
    cout << "Area: " << rect.calculateArea() << endl;
    cout << "Perimeter: " << rect.calculatePerimeter() << endl;

    return 0;
}