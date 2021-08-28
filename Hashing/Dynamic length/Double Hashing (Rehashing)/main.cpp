#include <iostream>
#include "Linked List.h"

using namespace std;
#define ll long long

//capacity for hash table capacity and n for curr items inserted
int capacity, n;

//prime capacity used in the second hash function
int prime_capacity;

//initialize Hash table with dynamic length
string *arr;

//Initialize Load factor
const float load_factor = 0.5;

//This function calculate the hash value of the given string key
int hash_function_complex_str(string key) {
    int res = 0;
    for (int i = 0; i < key.size(); ++i) {
        res = (res + 37LL * key[i]) % capacity;
    }
    return res;

}

int hash_function_secondry(int idx) {
    return prime_capacity - idx % prime_capacity;
}

void reinsert_iteams(string *tmp, int old_capacity) {
    for (int i = 0; i < old_capacity; ++i) {

        if (arr[i] == "" || arr[i] == "#")
            continue;


        int idx = hash_function_complex_str(arr[i]);
        int step = hash_function_secondry(idx);

        int j = 0;
        while (tmp[(idx + j * step) % capacity] != "") {
            j++;
        }
        tmp[(idx + j * step) % capacity] = arr[i];
    }

}

//Update the capacity of the hash table
void reserve(int new_capacity) {

    string *tmp = new string[new_capacity];

    int old_capacity = capacity;

    capacity = new_capacity;

    reinsert_iteams(tmp, old_capacity);
    delete[] arr;

    arr = tmp;
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
    int step = hash_function_secondry(idx);

    int i = 0;
    while (arr[(idx + i * step) % capacity] != key && arr[(idx + i * step) % capacity] != "")
        i++;

    return arr[(idx + i * step) % capacity] == key;

}

//This function inserts given item in the hash table
void insert_item(string key) {
    if (search_item(key))
        return;

    int idx = hash_function_complex_str(key);
    int step = hash_function_secondry(idx);
    int i = 0;

    while (arr[(idx + i * step) % capacity] != "" && arr[(idx + i * step) % capacity] != "#")
        i++;

    arr[(idx + i * step) % capacity] = key;

    n++;

    if (1.0 * n / capacity >= load_factor) {
        prime_capacity = get_next_prime(2 * capacity);
        reserve(get_next_prime(prime_capacity));

    }
}

//This function Deletes given item in the hash table
void delete_item(string key) {
    if (!search_item(key))
        return;

    int idx = hash_function_complex_str(key);
    int step = hash_function_secondry(idx);
    int i = 0;
    while (arr[(i * step + idx) % capacity] != "" && arr[(i * step + idx) % capacity] != key)
        i++;
    arr[(i * step + idx) % capacity] = "#";
    n--;

    if (n < capacity / 2) {
        prime_capacity = get_next_prime(capacity / 2);
        reserve(get_next_prime(prime_capacity));
    }
}

//This function print the hash table
void print_hash() {

    for (int i = 0; i < capacity; ++i) {
        if (arr[i] == "" || arr[i] == "#")
            continue;

        cout << "index " << i << " :" << arr[i] << '\n';


    }
}

int main() {
    // Functionality Testing

    capacity = 3;
    prime_capacity = 2;
    arr = new string[capacity];

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
        cout << "===========================================\n";

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

}

