#include <iostream>

using namespace std;
#include "Tag.h"
#include "Document.h"
#include "Relation.h"


int main()

{

    cout << "Group 4 Tubes"<< endl;
    cout << "Multi Linked List"<< endl;
    cout << "By Hilal Ramadhan(1301194236) and Naufal Scudetto(1301190197)"<<endl;

    List_document LD;
    List_tag LT;
    List_relation LR;


    address_document D;
    string DC;
    address_tag T;
    string TC;
    address_relation R;

    createList(LD);
    createList(LT);
    createList(LR);
    int X;
    int G;

    cout<<"/-----------------------------------/"<<endl;
    cout<<"|        D I R E C T O R Y          |"<<endl;
    cout<<"|-----------------------------------|"<<endl;
    cout<<"|   [1] Add a Document              |"<<endl;
    cout<<"|   [2] Add a Tag                   |"<<endl;
    cout<<"|   [3] Add a Relation between      |"<<endl;
    cout<<"|       a Document and Tag          |"<<endl;
    cout<<"|   [4] Delete a Document           |"<<endl;
    cout<<"|   [5] Delete a Tag                |"<<endl;
    cout<<"|   [6] Show documents              |"<<endl;
    cout<<"|   [7] Show most popular tags      |"<<endl;
    cout<<"|   [8] Show document with largest  |"<<endl;
    cout<<"|       amount of tags              |"<<endl;
    cout<<"|   [9] Show document with fewest   |"<<endl;
    cout<<"|       amount of tags              |"<<endl;
    cout<<"|   [10] Show document with atleast |"<<endl;
    cout<<"|        one of the searched tags   |"<<endl;
    cout<<"|   [11] See the Amount             |"<<endl;
    cout<<"|        of Documents               |"<<endl;
    cout<<"|   [12] See the Amount             |"<<endl;
    cout<<"|        of Tags                    |"<<endl;
    cout<<"|   [13] See the Documents          |"<<endl;
    cout<<"|        without a Tag              |"<<endl;
    cout<<"|   [0] Exit                        |"<<endl;
    cout<<"/-----------------------------------/"<<endl;
    cout<<endl;
    cout<<" Insert your choice: ";
    cin>>X;
    cout<<endl;

    while (X != 0){
        if (X == 1){
            string Doc;
            cout<<"Insert a Document: ";
            cin>>Doc;
            D = allocatedoc(Doc);
            insertFirst(LD, D);
        } else if (X == 2){
            string ttg;
            cout<<"Insert a Tag: ";
            cin>>ttg;
            T = allocatetag(ttg);
            insertFirst(LT, T);
        } else if (X == 3){
            cout<<"Here you can combine a document and a tag to create a relation"<<endl;
            cout<<"Documents :";
            printInfo(LD);
            cout<<"Tags :";
            printInfo(LT);
            cout<<"Document to combine: ";
            cin>>DC;
            D = findX(LD,DC);
            cout<<"Tag to combine: ";
            cin>>TC;
            T = findM(LT,TC);
            R = allocaterelate(D,T);
            insertFirst(LR, R);
        } else if (X == 4){
            cout<<"Document to delete: ";
            cin>>DC;
            D = findX(LD,DC);
            deleteDocu(LD, D);
        } else if (X == 5){
            cout<<"Tag to delete: ";
            cin>>TC;
            T = findM(LT,TC);
            deleteTag(LT, T);
        } else if (X == 6){
            showAll(LD, LR);
            cout<<endl;
        } else if (X == 7){
            populartags(LT, LR);
            cout<<endl;
        } else if (X == 8){
            mostTag(LD,LR);
            cout<<endl;
        } else if (X == 9){
            leastTags(LD,LR);
            cout<<endl;
        } else if (X == 10){
            cout<<"Tags :";
            printInfo(LT);
            cout<<"Press 1 to input a tag to search"<<endl;
            cout<<"Press 2 to search the documents for the tag(s)"<<endl;
            cout<<"Press 0 to exit this function"<<endl;
            cout<<"Input choice: ";
            cin>>G;
            cout<<endl;
            while (G != 0){
                if (G == 1){
                    cout<<"Tag input to search: ";
                    cin>>TC;
                    T = findM(LT,TC);
                    cout<<endl;
                }else if (G == 2){
                    searchTag(LR, LD, T);
                    cout<<endl;
                }
                cout<<"Press 1 to input a tag to search"<<endl;
                cout<<"Press 2 to search the documents for the tag(s)"<<endl;
                cout<<"Press 0 to exit this function"<<endl;
                cout<<"Input choice: ";
                cin>>G;
                cout<<endl;
            }
        } else if (X == 11){
            amountDocument(LD);
        } else if (X == 12){
            amountTags(LT);
        } else if (X == 13){
            DocuWithoutTag(LD,LR);
        } else {
            cout<<"Sorry that is not one of the choices"<<endl;
        }

        cout<<endl;
        cout<<"/-----------------------------------/"<<endl;
        cout<<"|        D I R E C T O R Y          |"<<endl;
        cout<<"|-----------------------------------|"<<endl;
        cout<<"|   [1] Add a Document              |"<<endl;
        cout<<"|   [2] Add a Tag                   |"<<endl;
        cout<<"|   [3] Add a Relation between      |"<<endl;
        cout<<"|       a Document and Tag          |"<<endl;
        cout<<"|   [4] Delete a Document           |"<<endl;
        cout<<"|   [5] Delete a Tag                |"<<endl;
        cout<<"|   [6] Show documents              |"<<endl;
        cout<<"|   [7] Show most popular tags      |"<<endl;
        cout<<"|   [8] Show document with largest  |"<<endl;
        cout<<"|       amount of tags              |"<<endl;
        cout<<"|   [9] Show document with fewest   |"<<endl;
        cout<<"|       amount of tags              |"<<endl;
        cout<<"|   [10] Show document with atleast |"<<endl;
        cout<<"|        one of the searched tags   |"<<endl;
        cout<<"|   [11] See the Amount             |"<<endl;
        cout<<"|        of Documents               |"<<endl;
        cout<<"|   [12] See the Amount             |"<<endl;
        cout<<"|        of Tags                    |"<<endl;
        cout<<"|   [13] See the Documents          |"<<endl;
        cout<<"|        without a Tag              |"<<endl;
        cout<<"|   [0] Exit                        |"<<endl;
        cout<<"/-----------------------------------/"<<endl;
        cout<<endl;
        cout<<"Insert your next choice: ";
        cin>>X;
        cout<<endl;
    }

    cout << "Thank you for your participation  ^^" << endl;
    return 0;

}
