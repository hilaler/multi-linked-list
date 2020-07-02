#include "Document.h"
#include <iostream>
using namespace std;

void createList(List_document &L){

    first(L) = NULL;
    last(L) = NULL;

}

address_document allocatedoc(infotype_document x){

    address_document P;
    P = new elmlist_document;
    info(P) = x;
    nextDocu(P) = NULL;
    return P;

}

void insertFirst(List_document &L, address_document P){

    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        nextDocu(P) = first(L);
        first(L) = P;
        }
}

void deleteFirst(List_document &L){

    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        first(L) = nextDocu(first(L));
    }
}

void deleteLast(List_document &L){

    address_document P;
    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        while (nextDocu(P) != last(L)){
            P = nextDocu(P);
        }
        last(L) = P;
    }
}

address_document findX(List_document &L, infotype_document X){

    address_document P;
    bool found;
    P = first(L);
    found = false;
    while ((P != NULL) && (found != true)){
        if(info(P) == X) {
            found = true;
        } else {
            P = nextDocu(P);
        }
    }
    if(found = true){
        return P;
    } else {
        return NULL;
    }

}

void deleteDocu(List_document &L, address_document &P){

    address_document prec;
    prec = first(L);
    while (nextDocu(prec) != P){
        prec = nextDocu(prec);
    }
    if (nextDocu(P) == NULL){
        last(L) = prec;
    } else {
    nextDocu(prec) = nextDocu(P);
    }
}

void printInfo(List_document L){

    address_document p = first(L);
    if (first(L) == NULL && last(L) == NULL){
        cout<<"List of document is EMPTY "<<endl;
    } else {
        cout<<"|| "<<info(p)<<" || ";
        p = nextDocu(p);
    }while (p != NULL){
        cout<<info(p)<<" || ";
        p = nextDocu(p);
    }
    cout<<endl;
}



