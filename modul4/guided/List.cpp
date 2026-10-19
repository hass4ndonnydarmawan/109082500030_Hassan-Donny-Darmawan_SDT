#include "List.h"
#include <iostream>
using namespace std;
// Implementasion of the functions declared in List.h

// Function to check if the linked list is empty
bool isEmpty(LinkedList L){
    if (L.first == Nil){
        return (L.first == Nil);
    } else {
        return (L.first == Nil);
    }
};
// Function to create an empty linked list
void createList(LinkedList &L){
    L.first = Nil;
};
// Function to allocate a new node with the given student data
address alokasi(int age, string name, string id){
    address P = new Node;
    if (P != Nil){
        P->data.age = age;
        P->data.name = name;
        P->data.id = id;
        P->next = Nil;
    }
    return P;
};
// Function to deallocate a node
void dealokasi(address &P){
    P->next = Nil;
    delete P;
};
// Function to print the elements of the linked list
void printList(LinkedList L){
    address P = L.first;
    while (P != Nil){
        cout << "Name: \t" << P->data.name << ", ID: \t" << P->data.id << ", Age: " << P->data.age << endl;
        P = P->next;
    }
};
// Function to insert a node at the beginning of the linked list
void insertFirst(LinkedList &L, address P)
{
    if (isEmpty(L)){
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
};
// Function to insert a node after a given node in the linked list
void insertAfter(LinkedList &L, address Prev, address P)
{
    if (Prev != Nil){
        P->next = Prev->next;
        Prev->next = P;
    }
};
// Function to insert a node at the end of the linked list
void insertLast(LinkedList &L, address P)
{
    if (isEmpty(L)){
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil){
            Q = Q->next;
        }
        Q->next = P;
    }
};

// Function to delete the first node of the linked list
void delfirst(LinkedList &L){
    if (isEmpty(L)){
        cout << "List is empty, cannot delete." << endl;
    } else {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
};
// Function to delete a node after a given node in the linked list
void delAfter(LinkedList &L, address Prev, address P){
    if (isEmpty(L)){
        cout << "List is empty, cannot delete." << endl;
    } else {
        if(Prev != Nil && Prev->next != Nil){
            P = Prev->next;
            Prev->next = P->next;
            P->next = Nil;
            dealokasi(P);
        }else{
            cout << "Previous node is not valid, cannot delete." << endl;
        }
    }
};
// Function to delete the last node of the linked list
void delLast(LinkedList &L){
    if (isEmpty(L)){
        cout << "List is empty, cannot delete." << endl;
    } else {
        address P = L.first;
        address Q = Nil;
        while (P->next != Nil){
            Q = P;
            P = P->next;
        }
        if (Q != Nil){
            Q->next = Nil;
        } else {
            L.first = Nil;
        }
        dealokasi(P);
    }
};
// Function to count the number of nodes in the linked list
int nbList(LinkedList L){
    int count = 0;
    address P = L.first;
    while (P != Nil){
        count++;
        P = P->next;
    }
    return count;
};
// Function to delete all nodes in the linked list
void delList(LinkedList &L){
    while (!isEmpty(L)){
        delfirst(L);
    }
};