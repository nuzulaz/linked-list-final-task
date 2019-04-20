#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct infotype_child{
    string nama;
    int umur;
    string hobi;
    int member;
};
typedef struct ElemenChild *address_child;

struct ElemenChild{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct Child{
    address_child first;
    address_child last;
};

void sorting(Child &L,address_child P);
address_child alokasi(infotype_child x);
void createList(Child &L);
void insertFirst(Child &L, address_child P);
void insertLast(Child &L, address_child P);
void insertAfter(Child &C, address_child Prec, address_child P);
void deleteFirst(Child &L, address_child &P);
void deleteLast(Child &L, address_child &P);
void deleteAfter(Child &C, address_child Prec, address_child &P);
void DeleteChild(Child &L, infotype_child x);
void printInfo(Child L);
address_child findElmChild(Child L, infotype_child x);
void InsertDataNetizen(Child &L);
void editDataNetizen(Child &L, address_child P);


#endif // CHILD_H_INCLUDED
