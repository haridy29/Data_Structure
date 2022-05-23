#include <iostream>


using namespace std;


template<class type>
class Linked_List
{
protected:
    struct node
    {
        type iteam;
        node * next;
        node *prev;
    };
    int length;
    node *head;
    node *tail;

public:

    Linked_List()
    {
        length = 0;
        head = tail = NULL;
    }
    Linked_List(type value, int initial_size)
    {
        length=0;
        node *newnode = new node;
        newnode->iteam = value;
        head = tail = newnode;
        length++;
        for(int i=1; i<initial_size; i++)
        {
            this->push_back(value);

        }
    }
    void push_back(type value)
    {
        node *newnode = new node;
        node * dummy = new node;
        newnode->iteam = value;
        newnode->next = dummy;
        if(length==0)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
        dummy->prev = tail;
        length++;
    }


    int size()
    {
        return length;
    }

    type  operator [](int idx)const{

            if (idx>=length||idx<0){
              return NULL;
            }
            if (idx==0)
                return head->iteam;
            if (idx==length-1)
                return tail->iteam;
            node* tmp=head;
            while (idx--){
                tmp=tmp->next;
            }
        return tmp->iteam;
    }

    type back(){
        return tail->iteam;
    }
    ~Linked_List()
    {

        while(head!=NULL&&head != tail->next)
        {
            node* curr = head;
            node* nextToDelete = curr->next;
            head = nextToDelete;
            delete curr;
        }

    }


};

struct TrieNode {
    char ch;
    int id;
    Linked_List<TrieNode*>Child;
    TrieNode() {
        this->id = -1;
    }

    TrieNode(char c) {
        this->id = -1;
        this->ch = c;
    }TrieNode(char c, int id) {
        this->id = id;
        this->ch = c;
    }

};

class SuffixTrie {
public:
    TrieNode *Head;
    string s;

    SuffixTrie(string s) {
        this->s = std::move(s);
        Head = new TrieNode();

        insert(this->s);

    }


    int get_idx(TrieNode* tmp, char ch) {

        int idx=-1;
        for (int j = 0; j <tmp->Child.size() ; ++j) {
            if (tmp->Child[j]->ch==ch)
            {
                idx=j;
                break;
            }
        }
        return idx;

    }

    void insert(string str) {
        if (str.size() == 0)
            return;

        TrieNode *tmp = Head;

        for (int i = 0; i < str.size() - 1; ++i) {
            char currch = str[i];

            if (get_idx(tmp,currch)==-1) {
                TrieNode *newchild = new TrieNode(currch);

                tmp->Child.push_back(newchild);
                //  cout<<currch<<'\n';
            }

            tmp = tmp->Child[get_idx(tmp,currch)];

        }
        tmp->Child.push_back( new TrieNode(str[str.size() - 1])) ;
        tmp = tmp->Child.back();
        int idx = s.size() - str.size();
        tmp->id = idx;

        str = str.substr(1);
        insert(str);
    }

    void get_ids(TrieNode *node) {
        if (!node)
            return;

        if (node->id != -1)
            cout << node->id << ' ';

        for (int i = 0; i < node->Child.size(); i++) {
            get_ids(node->Child[i]);
        }

    }

    void Search(string str) {
        TrieNode *tmp = Head;

        for (int i = 0; i < str.size(); ++i) {
            int currch = str[i];
                int idx=get_idx(tmp,currch);
            if (idx!=-1) {
                tmp = tmp->Child[idx];
            } else {
                cout << "Not Found\n";
                return;
            }
        }
        get_ids(tmp);
        cout<<'\n';
    }

    void releaseSpace(TrieNode *node) {

        TrieNode *tmp = node;
        for (int i = 0; i < node->Child.size(); ++i) {
            if (tmp->Child[i] != NULL)
                releaseSpace(tmp->Child[i]);
        }
        delete tmp;

    }

    ~SuffixTrie() {
        releaseSpace(Head);
    }


};

int main() {
    SuffixTrie t("bananabanaba$");
    t.Search("ana");// Prints: 1 3 7

    t.Search("naba"); // Prints: 4 8

 }

