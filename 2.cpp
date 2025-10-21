#include <iostream>
#include <string>
using namespace std;

//Simple structure to hold key-value pairs - Like Dictionary
struct KeyValuePair {
    string key;
    int value;
};

class Dictionary {
    private:
        KeyValuePair* pairs;
        int capacity;
        int size;

    public:
        //Initialising Constructor
        Dictionary() {
            capacity = 10;
            size = 0;
            pairs = new KeyValuePair[capacity];
        }
        //Destructor to free up space and memory
        ~Dictionary() {
            delete[] pairs;
        }
        // Add a key-value pair
        void add(string key, int value) {
            if (size < capacity) {
                pairs[size].key = key;
                pairs[size].value = value;
                size++;
            } 
            else {
                cout << "Dictionary is full." << endl;
            }
        }
        // Search for a key and return its value
        int search(string key) {
            for (int i = 0; i < size; i++) {
                if (pairs[i].key == key) {
                    return pairs[i].value;
                }
            }
            return -1; // Return -1 if key not found
        }
        //Display all key-value pairs
        void display() {
            cout << "Dictionary Contents:" << endl;
            for (int i = 0; i < size; i++) {
                cout << "- " << pairs[i].key << ": " << pairs[i].value << endl;
            }
        }
};

int main() {
    Dictionary dict;
    dict.add("age", 25);
    dict.add("id", 101);
    dict.add("score", 95);

    dict.display();
    cout << "\nSearching for 'id': " << dict.search("id") << endl;
    cout << "Searching for 'name': " << dict.search("name") << endl;
    return 0;
}