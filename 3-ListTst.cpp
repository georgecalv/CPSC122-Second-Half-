/*
Name: George Calvert
Class: CPSC 122, Section 1
Date Submitted: March 20, 2022
Assignment: Project 11
Description: Program illustrates a simple linked list  
*/

#include <iostream>
using namespace std;

#include "3-List.h"

int main()
{
    //Static list 
    ListT lst;
    // put stuff in list
    cout << "putItemH" << endl;
    for (int i = 0; i < 10; i++) 
        lst.PutItemH(i);
    // print
    lst.Print();
    cout << endl;
    // delete header
    cout << "Delete Header" << endl;
    lst.DeleteItemH();
    lst.Print();
    cout << endl;
    // delete Tail
    cout << "Delete Tail" << endl;
    lst.DeleteItemT();
    lst.Print();
    cout << endl;
    // put ItemT
    cout << "putItemT" << endl;
    lst.PutItemT(12);
    lst.Print();
    cout << endl;
    // find function
    cout << "Finding instances of 3" << endl;
    cout << lst.FindItem(3);
    cout<< endl;
    cout << endl;
    // length function
    cout << "getting length" << endl;
    cout << lst.GetLength();
    cout << endl;
    cout << endl;
    // get header function
    cout << "Getting item of the header" << endl;
    cout << lst.GetItemH() << endl;
    cout << endl;
    cout << "Get item of the tail" << endl;
    cout << lst.GetItemT() << endl;
    cout << endl;
    // delete item function
    cout << "Delting instances of 2" << endl;
    cout << lst.DeleteItem(2) << endl;
    cout << endl;
    lst.Print();
    cout << endl;




    // //Dynamic list 
    ListT* lst1 = new ListT;
    // put stuff in list
    for (int i = 0; i < 10; i++)
        lst1->PutItemH(10*i);
    lst1->Print();
    cout << endl;
    // delete head
    cout << "delete head" << endl;
    lst1->DeleteItemH();
    lst1->Print();
    cout << endl;
    // delete Tail
    cout << "Delete Tail" << endl;
    lst1->DeleteItemT();
    lst1->Print();
    cout << endl;
    cout << "Put Item tail" << endl;
    lst1->PutItemT(12);
    lst1->Print();
    cout << endl;
    // Find Function
    cout << "Finding instances of 30" << endl;
    cout<< lst1->FindItem(30);
    cout << endl;
    cout << endl;
    // length function
    cout << "getting length" << endl;
    cout << lst1->GetLength() << endl;
    cout << endl;
    // get header function
    cout << "Getting item of the header" << endl;
    cout << lst1->GetItemH() << endl;
    cout << endl;
    // get tail
    cout << "Get Tail" << endl;
    cout << lst1->GetItemT() << endl;
    cout << endl;
    // delete instance of something
    cout << "Delting instances of 10" << endl;
    cout << lst1->DeleteItem(10) << endl;
    cout << endl;
    lst1->Print();

    delete lst1; //necessary to invoke destructor on dynamic list
    cout << endl;
    return 0;
}