//
//  main.cpp
//  LinkedList
//
//  Created by Tony Lyu on 12/03/2017.
//  Copyright © 2017 Tony. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }
    void insert(Node* n1, Node* n2) {
        if (n1 == NULL) {
            n2->next = head;
            head = n2;
            return;
        }
        n2->next = n1->next;
        n1->next = n2;
    }
    Node* find(int v) {
        Node* p = head;
        while (p != NULL) {
            if (p->value == v)
                return p;
            p = p->next;
        }
        return NULL;
    }
    Node* remove(int v) {
        if (head->value == v) {
            Node* p = head;
            head = head->next;
            return p;
        }
        if (head == NULL || head->next == NULL)
            return NULL;
        Node* p = head->next;
        while (p->next != NULL) {
            if (p->next->value == v) {
                Node* ret = p->next;
                p->next = p->next->next;
                return ret;
            }
        }
        return NULL;
    }
    void print() {
        if (head == NULL) {
            cout << "Empty!\n";
            return;
        }
        Node* p = head;
        do {
            cout << p->value << " ";
            p = p->next;
        } while (p != NULL);
    }
    
};

int main() {
    LinkedList list;
    Node node1 = {5, NULL};
    Node node2 = {10, NULL};
    Node node3 = {20, NULL};
    list.insert(NULL, &node1);
    list.insert(NULL, &node2);
    Node* n1 = list.find(5);
    list.insert(n1, &node3);
    list.print();
    cout << endl;
    list.remove(10);
    list.print();
    return 0;
    
}
