#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct infotype_parent{
    string socmed;
    int member;
    string tglGabung;
    string Jenis;
};

typedef struct Elmparent *address_parent;

struct Elmparent{
    infotype_parent info;
    address_parent next;
};

struct Parent{
    address_parent first;
};

void Print(Parent L);
address_parent Alokasi(infotype_parent x);
void dealokasi(address_parent &P);
void createList(Parent &L);
void insertFirst(Parent &L, address_parent P);
void insertAfter(Parent &L, address_parent Prec, address_parent P);
void insertLast(Parent &L, address_parent P);
void DeleteFirst(Parent &L, address_parent &P);
void DeleteLast(Parent &L, address_parent &P);
void DeleteAfter(Parent &L, address_parent Prec, address_parent &P);
address_parent findElmParent(Parent L, infotype_parent x);
void deleteElmParent(Parent &L, infotype_parent p);
void InsertDataGroup(Parent &L);
address_parent GroupMemberTerbanyak(Parent L);
address_parent GroupMemberTersedikit(Parent L);
void editDataSocmed(Parent &L, address_parent P);


#endif // Parent_H_INCLUDED

