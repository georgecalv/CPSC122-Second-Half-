#include <iostream>
using namespace std;

#include "list.h"


int main()
{
    List* lst1 = new List;
    for (int i = 1; i <= 10; i++)
    lst1->PutItemH(i);
    lst1->Print();
    cout << endl;
    lst1->PrintRev();
    cout << endl;
    cout << lst1->GetLength() << endl;
    if(lst1->IsEmpty())
    {
        cout << "Is empty" << endl;
    }
    else 
    {
        cout << "Is not Empty" << endl;
    }
    cout << endl;
    delete lst1; 


    List* lst2 = new List;
    if(lst2->IsEmpty())
    {
        cout << "Is empty" << endl;
    }
    else 
    {
        cout << "Is not Empty" << endl;
    }
    lst2->Print();
    cout << endl;
    lst2->PrintRev();
    cout << endl;
    cout << lst2->GetLength() << endl;
    delete lst2;

    return 0;
}