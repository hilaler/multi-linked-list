#ifndef LIST_DOCUMENT_H_INCLUDED
#define LIST_DOCUMENT_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define nextDocu(P) P->nextDocu
#define last(L) L.last
#define info(P) P->info

typedef string infotype_document;
//typedef char ItemType[10] infotype_document;
typedef struct elmlist_document *address_document;

struct elmlist_document{

    infotype_document info;
    address_document nextDocu;

};

struct List_document{

    address_document first;
    address_document last;

};

void createList(List_document &L);
void insertFirst(List_document &L, address_document P);
void deleteFirst(List_document &L, address_document &P);
void deleteLast(List_document &L, address_document &P);
address_document findX(List_document &L, infotype_document X);
void deleteDocu(List_document &L, address_document &P);
address_document allocatedoc(infotype_document x);
void printInfo(List_document L);

#endif
