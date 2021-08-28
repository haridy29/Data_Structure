#include <iostream>
#include "Linked List.h"

using namespace std;

#define ll long long
//capacity for hash table capacity and n for curr items inserted
int capacity, n;

//dynamic hash table
Linked_list<string> *Head;

//Load factor
const float load_factor = 0.5;

//This function calculate the hash value of the given string key
int hash_function_complex_str(string key) {
    int res = 0;
    for (int i = 0; i < key.size(); ++i) {
        res = (res + 37LL * key[i]) % capacity;
    }
    return res;

}

//Update the capacity of the hash table
void reserve(int new_capacity) {

    Linked_list<string> *temp = new Linked_list<string>[new_capacity];

    int old_capacity = capacity;

    capacity = new_capacity;

    Head->reinsert(temp, old_capacity, capacity);

    Head->Delete_Linked();
    delete Head;

    Head = temp;
}

//This function get the next prime for given number
int get_next_prime(int x) {

    for (int i = x + 1; i < x + 150; ++i) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0)
                is_prime = false;
        }
        if (is_prime)
            return i;
    }
    return x;
}

//This function searches given item in the hash table
bool search_item(string key) {
    int idx = hash_function_complex_str(key);
    return Head[idx].Search(key);
}

//This function inserts given item in the hash table
void insert_item(string key) {
    if (search_item(key))
        return;
    int idx = hash_function_complex_str(key);
    Head[idx].insert(key);
    n++;

    if (1.0 * n / capacity >= load_factor)
        reserve(get_next_prime(2 * capacity));
}

//This function Deletes given item in the hash table
void delete_item(string key) {
    if (!search_item(key))
        return;

    int idx = hash_function_complex_str(key);
    Head[idx].Delete(key);
    n--;

    if (n < capacity / 2)
        reserve(get_next_prime(capacity / 2));

}

//This function print the hash table
void print_hash() {

    for (int i = 0; i < capacity; ++i) {
        if (Head[i].is_empty())
            continue;
        cout << "index " << i << ":\n";
        Head[i].print();

    }
}

int main() {
    // Functionality Testing

    capacity = 2;
    Head = new Linked_list<string>[capacity];

    cout << "Hash table Capacity: " << capacity << '\n';
    cout << "Hash table size: " << n << '\n';
    cout << "===========================================\n";

    for (char i = 'a'; i <= 'm'; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0; j < 75; ++j) {
            insert_item(item);
            item += i;
        }
        cout << "Hash table Capacity: " << capacity << '\n';
        cout << "Hash table size: " << n << '\n';
        cout << "______________________________________________\n";

    }
    for (char i = 'a'; i <= 'm'; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0; j < 75; j++) {
            if (!search_item(item))
                cout << item << " not found\n";
            item += i;
        }
    }

    print_hash();
    cout << "----------------------------------------------------\n";
    for (char i = 'a'; i <= 'm'; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0; j < 75; j++) {
            if (j < 10) {
                item += i;
                continue;
            }
            delete_item(item);
            item += i;
        }

        cout << "Hash Table capacity: " << capacity << '\n';
        cout << "Hash Table size: " << n << '\n';
        cout << "----------------------------------------------------\n";
    }

    for (char i = 'a'; i <= 'm'; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0; j < 10; j++) {
            if (!search_item(item))
                cout << item << " not found\n";
            item += i;
        }
    }

    print_hash();
    cout << "----------------------------------------------------\n";

}

