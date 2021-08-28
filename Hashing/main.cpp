#include <iostream>
#include "Linked List.h"

using namespace std;

#define ll long long

//size of hash table
const int table_size = 1e3 + 13;

//used in double hashing to calculate the second hash
//  the number must be prime and less than the number of the hash table size
const int prime_size = 1e3 + 9;

//calculate the hash value of the int key
int hash_function_int(int x) {
    return x % table_size;
}

//calculate the hash value of the int key
int hash_function_int_complex(int x) {
    return (37LL * (x % table_size)) % table_size;
}

//calculate the hash value of the long key
int hash_function_long(ll x) {
    return x % table_size;
}

//calculate the hash value of the long key
int hash_function_long_complex(ll x) {
    return (37LL * (x % table_size)) % table_size;
}

//calculate the hash value of a string key
int hash_function_string(string x) {
    int res = 0;
    for (int i = 0; i < x.size(); i++) {
        res = (res + x[i]) % table_size;
    }
    return res;

}

//calculate the hash value of a string key
int hash_function_string_complex(string x) {
    int res = 0;
    for (int i = 0; i < x.size(); i++) {

        res = (res + 37LL * x[i]) % table_size;
    }
    return res;

}

//calculate the hash value of a char key
int hash_function_char(char x) {
    return int(x) % table_size;

}

//calculate the hash value of a char key
int hash_function_char_complex(char x) {
    return int(37LL * int(x)) % table_size;

}

//start Separate chaining

//Hash table to use in separate chaining
Linked_list<string> arr1[table_size];
/*

//This function  searches for an element in the hash table
bool search_iteam(string key) {
    int idx = hash_function_string_complex(key);
    return arr1[idx].Search(key);
}

//This function inserts an element in the hash table
void insert_item(string &key) {
    if (search_iteam(key))
        return;
    int idx = hash_function_string_complex(key);
    arr1[idx].insert(key);
}

//This function deletes an element in the hash table
void delete_item(string key) {
    if (!search_iteam(key))
        return;
    int idx = hash_function_string_complex(key);
    arr1[idx].Delete(key);
}

//This function prints all elements in the hash table
void print_hash_table() {
    for (int i = 0; i < table_size; ++i) {
        if (arr1[i].is_empty())
            continue;
        cout << "index " << i << ":\n";
        arr1[i].print();
    }
}
*/

//end separate chaining



//start open Addressing

//hash table use in open addressing
string arr[table_size];


//start liner probing(open Addressing)
/*
//This function  searches for an element in the hash table
bool search(string key) {
    int idx = hash_function_string_complex(key);
    int i = 0;
    while (arr[(idx + i) % table_size] != key && arr[(idx + i) % table_size] != "")
        i++;
    return arr[(idx+i)%table_size]==key;

}

 //This function inserts an element in the hash table
 void insert(string key){
    if(search(key))
        return;
    int idx=hash_function_string_complex(key);
    int i=0;
    while (arr[(idx+i)%table_size]!=""&&arr[(idx+i)%table_size]!="#")
        i++;
    arr[(idx+i)%table_size]=key;
}

//This function deletes an element in the hash table
void Delete(string key){
    if(!search(key))
        return;
    int idx=hash_function_string_complex(key);
    int i=0;
    while (arr[(idx+i)%table_size]!=key)
        i++;
    arr[(idx+i)%table_size]="#";
}

//This function prints all elements in the hash table
void Print_Hash_Table(){
    for (int i = 0; i <table_size ; ++i) {
        if ( arr[i] == "" || arr[i] == "#")
            continue;
        cout<<"index "<<i<<": "<<arr[i]<<'\n';
    }
}
*/
//end Liner probing


//start quadratic probing(open Addressing)
/*

//This function  searches for an element in the hash table
bool search(string key) {
    int idx = hash_function_string_complex(key);
    int i = 0;
    while (arr[(idx + i*i) % table_size] != key && arr[(idx + i*i) % table_size] != "")
        i++;
    return arr[(idx+i*i)%table_size]==key;

}

//This function inserts an element in the hash table
 void insert(string key){
    if(search(key))
        return;
    int idx=hash_function_string_complex(key);
    int i=0;
    while (arr[(idx+i*i)%table_size]!=""&&arr[(idx+i*i)%table_size]!="#")
        i++;
    arr[(idx+i*i)%table_size]=key;
}

//This function deletes an element in the hash table
void Delete(string key){
    if(!search(key))
        return;
    int idx=hash_function_string_complex(key);
    int i=0;
    while (arr[(idx+i*i)%table_size]!=key)
        i++;
    arr[(idx+i*i)%table_size]="#";
}

//This function prints all elements in the hash table
void Print_Hash_Table(){
    for (int i = 0; i <table_size ; ++i) {
        if ( arr[i] == "" || arr[i] == "#")
            continue;
        cout<<"index "<<i<<": "<<arr[i]<<'\n';
    }
}
*/
//end quadratic probing


//start Double Hashing
/*
//The function calculate the hash value of the given hash value
int hash_function_secondry(int hash_index){
    return prime_size-hash_index%prime_size;
}

//This function  searches for an element in the hash table
bool search(string key) {
    int idx = hash_function_string_complex(key);
    //calculate the second hash value of the given key

    int step=hash_function_secondry(idx);

    int i = 0;
    while (arr[(idx + i*step) % table_size] != key && arr[(idx + i*step) % table_size] != "")
        i++;
    return arr[(idx+i*step)%table_size]==key;

}

 //This function inserts an element in the hash table
void insert(string key){
    if(search(key))
        return;
    int idx=hash_function_string_complex(key);
    //calculate the second hash value of the given key

    int step=hash_function_secondry(idx);
    int i=0;
    while (arr[(idx+i*step)%table_size]!=""&&arr[(idx+i*step)%table_size]!="#")
        i++;
    arr[(idx+i*step)%table_size]=key;
}

 //This function deletes an element in the hash table
void Delete(string key){
    if(!search(key))
        return;
    int idx=hash_function_string_complex(key);
    //calculate the second hash value of the given key
    int step=hash_function_secondry(idx);
    int i=0;
    while (arr[(idx+i*step)%table_size]!=key)
        i++;
    arr[(idx+i*step)%table_size]="#";
}

//This function prints all elements in the hash table
void Print_Hash_Table(){
    for (int i = 0; i <table_size ; ++i) {
        if ( arr[i] == "" || arr[i] == "#")
            continue;
        cout<<"index "<<i<<": "<<arr[i]<<'\n';
    }
}
*/
//end double hashing

//end open Addressing

int main() {
/*
 //for separate chaining 
    
    for (char i = 'a'; i <= 'm'; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;
        for (int j = 0; j < 75; ++j) {
            insert_item(item);
            item += i;
        }
    }
    print_hash_table();
    cout << "---------------------------------------------------------------------\n\n";
    for (char i = 'a'; i <= 'm'; i++) {
        string item = "";
        item += i;
        item += i;
        item += i;

        for (int j = 0; j < 75; ++j) {
            if (j < 10) {
                item += i;
                continue;
            }
            delete_item(item);
            item += i;
        }
    }

    print_hash_table();

    */

/*
 //For open Addressing (open Addressing)
    for (char c = 'a'; c <='z' ; ++c) {
        string item="";
        for (int i = 0; i <10 ; ++i) {
            item+=c;
            insert(item);
        }
    }

 for (char c='a';c<='z';c++){
        string item="";
        for (int i = 0; i <10 ; ++i) {
            if(!search(item))
                cout<<item<<" not found!!\n";
        item+=c;
        }
    }
    for (char c='a';c<='z';c++){
        string item="";
        for (int i = 0; i <10 ; ++i) {
            item+=c;
            if(i<3)
                continue;
            Delete(item);

        }
    }
    for (char c='a';c<='z';c++){
        string item="";
        for (int i = 0; i <10 ; ++i) {
            if(!search(item))
                cout<<item<<" not found!!\n";
            item+=c;
        }
    }
    cout<<"____________________________________________________________\n";
    Print_Hash_Table();
    */

    return 0;
}

/*
• Linear probing has the best cache
performance, but suffers from
clustering. One more advantage of
Linear probing is easy to compute.

• Quadratic probing lies between
the two in terms of cache
performance and clustering.

 • Double hashing has poor cache
performance but no clustering.
Double hashing requires more
computation time as two hash
functions need to be computed.

 */

/*
 Separate Chaining vs. Open Addressing
 1- Separate Chaining:-
1) Chaining is Simpler to implement.
2) In chaining, Hash table never fills up, we can
always add more elements to chain.
3) Chaining is Less sensitive to the hash function
or load factors.
4) Chaining is mostly used when it is unknown how
many and how frequently keys
may be inserted or deleted.
5) Cache performance of chaining is not good as
keys are stored using linked list.
6) Wastage of Space (Some Parts of hash table in
chaining are never used).
7) Chaining uses extra space for links.

2- Open Addressing:-
1) Open Addressing requires more computation.
2) In open addressing, table may become full.
3) Open addressing requires extra care for to avoid
clustering and load factor.
4) Open addressing is used when the frequency and
number of keys is known.
5) Open addressing provides better cache
performance as everything is stored in same table.
6) In Open addressing, a slot can be used even if an
input doesn’t map to it.
7) No links in Open addressing.

 */