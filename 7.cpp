#include <iostream>
using namespace std;

class Sorter {
    private:
        int* arr;
        int size;

    public:
        //Initialising by Constructor
        Sorter(int s) {
            size = s;
            arr = new int[size];
        }

        // Destructor
        ~Sorter() {
            delete[] arr;
        }

        //Method to get array data from user
        void inputData() {
            cout << "Enter " << size << " elements: ";
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
        }

        // Method to perform Bubble Sort
        void bubbleSort() {
            for (int i = 0; i < size - 1; i++) { 
                for (int j = 0; j < size - i - 1; j++) { //moving by each element
                    if (arr[j] > arr[j + 1]) {
                        // Swap elements
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
        void display() {
            cout << "Sorted Array: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Sorter mySorter(5);
    mySorter.inputData();
    mySorter.bubbleSort();
    mySorter.display();
    return 0;
}