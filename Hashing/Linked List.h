
#ifndef UNTITLED17_LINKED_LIST_H
#define UNTITLED17_LINKED_LIST_H

#include <iostream>

using namespace std;

template<class T>
class Linked_list {
public:
    Linked_list()  {head=NULL;}
    ~Linked_list(){
        Delete_all_nodes(head);
    }
    void insert(T& key) {
        insert_front(head, key);
    }

    void Delete(const T& key) {
        Delete_node(head, key);
    }

    bool Search(const T &key) {
        search_node(head, key);
    }

    void print(ostream&out=cout) {
        print_nodes(head,out);
    }
    bool is_empty(){
        if(head==NULL)
            return true;
        else
            return false;
    }
private:
    struct node {
        T data;
        node *next;

        node() : next{NULL} {}

        node(T& key) : next{NULL} { data = key; }
    };

    node *head;

    void insert_front(node *& curr_head, T &key);

    void Delete_node(node *&curr_head, const T &key);

    bool search_node(node *&curr_head, const T &key);

    void print_nodes(node *curr_head, ostream &out);

    void Delete_all_nodes(node*& curr_head);
};

template<class T>
void Linked_list<T>::insert_front(node *& curr_head, T& key) {
    node* new_node = new node(key);
    if (curr_head == NULL) {
        curr_head = new_node;
        return;
    } else {
        new_node->next = curr_head;
        curr_head = new_node;
    }

}

template<class T>
void Linked_list<T>::Delete_node(node *&curr_head, const T &key) {
    if (curr_head == NULL)
        return;
    if (curr_head->data == key) {
        node *tmp_node = curr_head;
        curr_head = curr_head->next;
        delete tmp_node;
    } else {
        node *curr = curr_head;
        node *prev = NULL;
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL) {
            prev->next = curr->next;
            delete curr;
        }

    }
}

template<class T>
bool Linked_list<T>::search_node(node *&curr_head, const T &key) {

    if (curr_head == NULL)
        return false;
    node *curr = curr_head;
    while (curr != NULL) {
        if (curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}

template<class T>
void Linked_list<T>::print_nodes(Linked_list::node *curr_head, ostream &out) {
    if (curr_head == NULL)
        return;
    node *curr = curr_head;

    while (curr != NULL) {
        out << curr->data << '\n';
        curr = curr->next;
    }
}

template<class T>
void Linked_list<T>::Delete_all_nodes(Linked_list::node *&curr_head) {
if(curr_head==NULL)
    return;
node* curr=curr_head;
node* prev=NULL;

while (curr!=NULL){
    prev=curr;
    curr=curr->next;
    delete prev;
}
    delete curr;
}

#endif //UNTITLED17_LINKED_LIST_H
