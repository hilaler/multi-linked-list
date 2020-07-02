#ifndef LIST_TAG_H_INCLUDED
#define LIST_TAG_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define nextTag(P) P->nextTag
#define last(L) L.last
#define info(P) P->info

typedef string infotype_tag;
typedef struct elmlist_tag *address_tag;

struct elmlist_tag{

    infotype_tag info;
    address_tag nextTag;

};

struct List_tag{

    address_tag first;
    address_tag last;

};

void createList(List_tag &L);
void insertFirst(List_tag &L, address_tag P);
void deleteFirst(List_tag &L, address_tag &P);
void deleteLast(List_tag &L, address_tag &P);
address_tag findM(List_tag &L, infotype_tag M);
void deleteTag(List_tag &L, address_tag &P);
address_tag allocatetag(infotype_tag x);
void printInfo(List_tag L);


#endif
