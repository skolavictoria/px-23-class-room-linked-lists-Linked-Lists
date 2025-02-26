#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
public:
    int value;
    Node* next = nullptr;
    Node(int v) : value(v) {}
};

class LinkedList {
public:
    Node* head = nullptr;

    void display() {
        Node* tmp = head;
        while (tmp) {
            cout << tmp->value << " -> ";
            tmp = tmp->next;
        }
        cout << "NULL" << endl;
    }

    void push(int v) {
        Node* newNode = new Node(v);
        newNode->next = head;
        head = newNode;
    }

    void append(int v) {
        Node* newNode = new Node(v);
        if (!head) {
            head = newNode;
            return;
        }
        Node* tmp = head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = newNode;
    }

    int pop() {
        if (!head) return -1;
        Node* tmp = head;
        int value = tmp->value;
        head = head->next;
        delete tmp;
        return value;
    }

    void del(int pos) {
        if (!head) return;
        Node* tmp = head;
        if (pos == 0) {
            head = tmp->next;
            delete tmp;
            return;
        }
        for (int i = 0; tmp && i < pos - 1; i++) tmp = tmp->next;
        if (!tmp || !tmp->next) return;
        Node* toDelete = tmp->next;
        tmp->next = tmp->next->next;
        delete toDelete;
    }

    void reverse() {
        Node *prev = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void sort() {
        if (!head) return;
        bool swapped;
        do {
            swapped = false;
            Node* tmp = head;
            while (tmp->next) {
                if (tmp->value > tmp->next->value) {
                    swap(tmp->value, tmp->next->value);
                    swapped = true;
                }
                tmp = tmp->next;
            }
        } while (swapped);
    }

    void shuffle() {
        if (!head) return;
        int len = 0;
        Node* tmp = head;
        while (tmp) { len++; tmp = tmp->next; }
        
        for (int i = 0; i < len; i++) {
            int randIdx = rand() % len;
            Node* randNode = head;
            for (int j = 0; j < randIdx; j++) randNode = randNode->next;
            swap(randNode->value, head->value);
            head = head->next;
        }
    }

    bool search(int v) {
        Node* tmp = head;
        while (tmp) {
            if (tmp->value == v) return true;
            tmp = tmp->next;
        }
        return false;
    }
};

int main() {
    LinkedList list;
    list.push(10);
    list.push(20);
    list.push(30);
    list.append(40);
    list.append(50);

    cout << "Linked List: ";
    list.display();

    list.del(1);  
    cout << "After Deletion: ";
    list.display();

    cout << "Reversing the List" << endl;
    list.reverse();
    list.display();

    cout << "Sorting the List" << endl;
    list.sort();
    list.display();

    cout << "Shuffling the List" << endl;
    list.shuffle();
    list.display();

    int searchValue = 30;
    cout << "Searching for " << searchValue << ": " << (list.search(searchValue) ? "Found" : "Not Found") << endl;

    return 0;
}

