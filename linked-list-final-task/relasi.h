#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "parent.h"
#include "child.h"
#define next(P) P->next
#define first(L) L.first
#define netizen(P) P->netizen
#define group(P) P->group
#include <iostream>


using namespace std;

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child netizen;
    address_parent group;
};

struct List_relasi{
    address_relasi first;
};
void dealokasi(address_relasi &P);
void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(List_relasi &L,address_relasi Prec, address_relasi &P);
address_relasi alokasi(address_child C, address_parent P);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_parent P, address_child C);
address_relasi FindNetizen(List_relasi L, infotype_child x);
address_relasi FindSocmed(List_relasi L, infotype_parent x);
void printInfo(List_relasi L);
void InsertRelasi(List_relasi &R, Parent &A, Child &B);
void PrintSemuaRelasi(List_relasi L);
bool isRelation(List_relasi L, infotype_child C, infotype_parent P);
void DeleteRelasiGroup(List_relasi &L, infotype_parent x);
void DeleteRelasiNetizen(List_relasi &L, infotype_child X);
void PrintGroupNetizenTertentu(List_relasi L, infotype_child X);
void PrintNetizenGroupTertentu(List_relasi L, infotype_parent X);
void GroupMemberTerbanyak(List_relasi R);
void GroupMemberTersedikit(List_relasi R, Parent G);



#endif // RELASI_H_INCLUDED
