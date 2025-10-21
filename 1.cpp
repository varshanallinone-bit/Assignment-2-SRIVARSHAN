#include <iostream>
using namespace std;

class SimpleList{
    private:
        int* arr;
        int capacity;
        int current_size;

    public:
        //Constructor to initialize the list
        SimpleList() {
            capacity = 5; //with Initial capacity
            current_size = 0;
            arr = new int[capacity];
        }

        //Destructor: free the allocated memory
        ~SimpleList() {
            delete[] arr;
        }

        // Function to add an element to the list
        void add(int item) {
            //If the array is full then we are doubling its capacity
            if (current_size == capacity) {
                int* temp = new int[2 * capacity];
                for (int i = 0; i < capacity; i++) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                capacity *= 2;
                arr = temp;
            }
            //Adding new element
            arr[current_size] = item;
            current_size++;
        }

        // Function to remove an element (of first occurrence)
        void remove(int item) {
            int index = -1;
            //Finding the index of the item to be removed
            for (int i = 0; i < current_size; i++) {
                if (arr[i] == item) {
                    index = i;
                    break;
                }
            }
            // If item is found then we are shifting elements to the left
            if (index != -1) {
                for (int i = index; i < current_size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                current_size--;
            } 
            else {
                cout << "Item not found in the list." << endl;
            }
        }

        //Function to display the list elements
        void display() {
            cout << "[ ";
            for (int i = 0; i < current_size; i++) {
                cout << arr[i] << " ";
            }
            cout << "]" << endl;
        }

        // Function to get the current size of the list
        int getSize() {
            return current_size;
        }
};

int main() {
    SimpleList myList;
    myList.add(10);
    myList.add(20);
    myList.add(30);
    cout << "List: ";
    myList.display();
    cout << "Size: " << myList.getSize() << endl;
    myList.remove(20);
    cout << "List after removing 20: " << endl;
    myList.display();
    return 0;
}