#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct Node *address;

struct student {
    int age;
    string name, id;
};

struct Node {
    student data;
    address next;
};

struct LinkedList {
    address first;
};

bool isEmpty(LinkedList L);
void createList(LinkedList &L);
address alokasi(int age, string name, string id);
void dealokasi(address &P);
void printList(LinkedList L);
void insertFirst(LinkedList &L, address P);
void insertAfter(LinkedList &L, address Prev, address P);
void insertLast(LinkedList &L, address P);

void delfirst(LinkedList &L);
void delAfter(LinkedList &L, address Prev, address P);
void delLast(LinkedList &L);
int nbList(LinkedList L);
void delList(LinkedList &L);
#endif