#include "Tag.h"
#include "Relation.h"

void createList(List_tag &L){

    first(L) = NULL;
    last(L) = NULL;
}

address_tag allocatetag(infotype_tag x){

    address_tag P;
    P = new elmlist_tag;
    info(P) = x;
    nextTag(P) = NULL;
    return P;
}

void insertFirst(List_tag &L, address_tag P){

    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        nextTag(P) = first(L);
        first(L) = P;
        }
}

void deleteFirst(List_tag &L){

    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        first(L) = nextTag(first(L));
    }
}

void deleteLast(List_tag &L){

    address_tag P;
    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        while (nextTag(P) != last(L)){
            P = nextTag(P);
        }
        last(L) = P;
    }

}

address_tag findM(List_tag &L, infotype_tag M){

address_tag P =first(L);
    bool found = false;
    while (P != NULL && !found){
        found = info(P) == M;
        if (!found){
            P = nextTag(P);
        }
    }
    if (found){
        return P;
    } else {
        return NULL;
    }

}

void deleteTag(List_tag &L, address_tag &P){

    address_tag prec;
    prec = first(L);
    while (nextTag(prec) != P){
        prec = nextTag(prec);
    }
    if (nextTag(P) == NULL){
        last(L) = prec;
    } else {
    nextTag(prec) = nextTag(P);
    }
}

void printInfo(List_tag L){

    address_tag p = first(L);
    while (p != NULL){
        cout<<info(p)<<" || ";
        p = nextTag(p);
    }
    cout<<endl;
}





