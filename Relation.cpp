#include "Relation.h"

void createList(List_relation &L){

    first(L) = NULL;

}

address_relation allocaterelate(address_document D, address_tag T) {
    address_relation Q = new elmlist_relation;
    tagAddress(Q) = T;
    documentAddress(Q) = D;
    nextRelate(Q) = NULL;
    return Q;
}

void insertFirst(List_relation &L, address_relation P) {
    nextRelate(P) = first(L);
    first(L) = P;
}

void printInfo(List_relation L) {
    address_relation P = first(L);
    while(P !=NULL) {
        cout<<info(documentAddress(P))<<"->"<<info(tagAddress(P))<<endl;
        P = nextRelate(P);
    }
}

address_relation findElm(List_relation L, address_document D, address_tag T) {
    address_relation Q = first(L);
    while(Q != NULL) {
        if(documentAddress(Q)== D && tagAddress(Q)== T) {
            return Q;
        }
        Q = nextRelate(Q);
    }
    return NULL;
}

void showAll(List_document L, List_relation R){
    if (first(L) == NULL){
        cout<<"Empty List"<<endl;
    } else {
        address_document DN = first(L);
        address_relation RN;
        while (DN != NULL){
            cout<<info(address_document(DN))<<" contains tags: ";
            RN = first(R);
            while (RN != NULL){
                if (documentAddress(RN) == DN){
                    cout<<info(tagAddress(RN))<<"|| ";
            }
                RN = nextRelate(RN);
            }
            cout<<endl;
            DN = nextDocu(DN);
        }
    }
}

void populartags(List_tag L, List_relation R){

if (first(L) == NULL){
        cout<<"Empty tag list"<<endl;
    } else {
        address_tag TG = first(L);
        address_relation RN = first(R);
        int popword;
        int amount = 0;
        string poptag;
        while (TG != NULL) {
            popword = 0;
            RN = first(R);
            while (RN != NULL){
                if (tagAddress(RN) == TG){
                    popword++;
                }
                RN = nextRelate(RN);
            }
            if (popword > amount){
                amount = popword;
                poptag = info(TG);
            }
            TG = nextTag(TG);
        }
        cout<<"The most popular tag is "<<poptag<<" which can be found in: ";
        RN = first(R);
        while (RN != NULL){
            if (info(tagAddress(RN)) == poptag){
                cout<<info(documentAddress(RN))<<"|| ";
            }
            RN = nextRelate(RN);
        }
        cout<<endl;
    }

}

void mostTag(List_document L, List_relation R){

    if (first(L) == NULL){
        cout<<"Empty tag list"<<endl;
    } else {
        address_document DN = first(L);
        address_relation RN = first(R);
        int mostDoc;
        int amount = 0;
        string popDoc;
        while (DN != NULL) {
            mostDoc = 0;
            RN = first(R);
            while (RN != NULL){
                if (documentAddress(RN) == DN){
                    mostDoc++;
                }
                RN = nextRelate(RN);
            }
            if (mostDoc > amount){
                amount = mostDoc;
                popDoc = info(DN);
            }
            DN = nextDocu(DN);
        }
        cout<<"The most popular document is "<<popDoc<<" which consists the tag(s) : ";
        RN = first(R);
        while (RN != NULL){
            if (info(documentAddress(RN)) == popDoc){
                cout<<info(tagAddress(RN))<<"|| ";
            }
            RN = nextRelate(RN);
        }
        cout<<endl;
    }
}

void leastTags(List_document L, List_relation R){

    if (first(L) == NULL){
        cout<<"Empty tag list"<<endl;
    } else {
        address_document DN = first(L);
        address_relation RN = first(R);
        int leastDoc;
        int amount = 10000;
        string unpopDoc;
        while (DN != NULL) {
            leastDoc = 0;
            RN = first(R);
            while (RN != NULL){
                if (documentAddress(RN) == DN){
                    leastDoc++;
                }
                RN = nextRelate(RN);
            }
            if (leastDoc < amount){
                amount = leastDoc;
                unpopDoc = info(DN);
            }
            DN = nextDocu(DN);
        }
        cout<<"The least popular document is "<<unpopDoc<<" which consists the tag(s) : ";
        RN = first(R);
        while (RN != NULL){
            if (info(documentAddress(RN)) == unpopDoc){
                cout<<info(tagAddress(RN))<<"|| ";
            }
            RN = nextRelate(RN);
        }
        cout<<endl;
    }


}

void searchTag(List_relation R, List_document D, address_tag T){

    if (first(D) == NULL){
        cout<<"Empty document list"<<endl;
    } else {
        address_relation RN = first(R);
        address_document DN = first(D);
        cout<<"The tag "<<info(T)<<" are found in : ";
        RN = first(R);
        while (RN != NULL){
            if ((tagAddress(RN) == T)){
                cout<<info(documentAddress((RN)))<<"|| ";
            }
            RN = nextRelate(RN);
    }
    cout<<endl;
    }
}

void amountDocument(List_document L){
     if (first(L) == NULL){
        cout<<"Empty document list"<<endl;
    } else {
        int amount = 0;
        address_document DN = first(L);
        while (DN != NULL){
            amount++;
            DN = nextDocu(DN);
        }
        cout<<"There are "<<amount<<" amount of document(s)";
    }
}

void amountTags(List_tag L){
    if (first(L) == NULL){
        cout<<"Empty tag list"<<endl;
    } else {
        int amount = 0;
        address_tag TN = first(L);
        while (TN != NULL){
            amount++;
            TN = nextTag(TN);
        }
        cout<<"There are "<<amount<<" amount of tag(s)";
    }
}

void DocuWithoutTag(List_document D, List_relation R){

    if (first(D) == NULL){
        cout<<"Empty document list"<<endl;
    } else {
        address_document DN = first(D);
        address_relation RN = first(R);
        bool found = false;
        while (DN != NULL){
            found = false;
            RN = first(R);
            while ((RN != NULL) && (!found)){
                if (documentAddress(RN) == DN){
                    found = true;
                } else {
                    RN = nextRelate(RN);
                    }
                }
                if (found == false){
                    cout<<info(DN)<<" || ";
                    DN = nextDocu(DN);
                } else {
                    DN = nextDocu(DN);
                }
            }
        }
    cout<<" these documents do not have a tag"<<endl;
}

