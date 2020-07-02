#ifndef LIST_RELATION_H_INCLUDED
#define LIST_RELATION_H_INCLUDED

#include "Document.h"
#include "Tag.h"

#include <iostream>
using namespace std;

#define nextRelate(P) P->nextRelate
#define first(L) L.first
#define tagAddress(P) P->tagAddress
#define documentAddress(P) P->documentAddress
#define info(P) P->info

typedef struct elmlist_relation *address_relation;

struct elmlist_relation{

    address_relation nextRelate;
    address_tag tagAddress;
    address_document documentAddress;
    infotype_document info;

};

struct List_relation{
    address_relation first;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_relation &L);
void insertFirst(List_relation &L, address_relation P);
void deleteFirst(List_relation &L, address_relation &P);
void deleteLast(List_relation &L, address_relation &P);
//address_relation findR(infotype_tag x);
//void deleteR(address_relation Prec, address_relation &P);


/** PERLU MODIFIKASI */
address_relation allocaterelate( address_document P, address_tag C);
//void dealokasi(address_relation &P);
address_relation findElm(List_relation L, address_document P, address_tag C);
void printInfo(List_relation L);
void populartags(List_tag L, List_relation R);
void showAll(List_document L, List_relation R);
void mostTag(List_document L, List_relation R);
void leastTags(List_document L, List_relation R);
void searchTag(List_relation R, List_document D, address_tag T);
void DocuWithoutTag(List_document D, List_relation R);
void amountDocument(List_document L);
void amountTags(List_tag L);


#endif
