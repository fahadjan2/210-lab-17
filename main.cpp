// COMSC-210 | Lab 17 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void nodeAddHead(Node *);
void nodeAddTail(Node *);
void nodeDelete(Node *);
void nodeInsert(Node *);
void linkedListDelete(Node *);

int main() {
    Node *head = nullptr;

    cout << "test" << endl;
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {    
        if (!head) { // if this is the first node, it's the new head
            nodeAddHead(head);
        }
        else { // its a second or subsequent node; place at the head
            nodeAddTail(head);
        }
    }
    output(head);

    nodeDelete(head);
    nodeInsert(head);
    linkedListDelete(head);
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

 // adds node at head
void nodeAddHead(Node * head) {
    int tmp_val = rand() % 100;
    Node *newVal = new Node;
    
    head = newVal;
    newVal->next = nullptr;
    newVal->value = tmp_val;  
}

void nodeAddTail(Node * head) {
    int tmp_val = rand() % 100;
    Node *newVal = new Node;

    newVal->next = head;
    newVal->value = tmp_val;
    head = newVal;
}

 // deleting a node
void nodeDelete(Node * head) {
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;    

    // traverse that many times and delete that node
    current = head;
    Node * prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);
}

void nodeInsert(Node * head) {
    // insert a node
    Node * current = head;
    int count = 1;
    int entry;
    cout << "After which node to insert 10000? " << endl;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node * prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);
}

void linkedListDelete(Node * head) {
    // deleting the linked list
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}
