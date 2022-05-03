/*
Name: George Calvert
Class: CPSC 122, Section 1
Date Submitted: March 20, 2022
Assignment: Project 9 
Description: Program illustrates a simple linked list  
*/

#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
    //Static list 
    List lst;
    // put stuff in list
    for (int i = 0; i < 10; i++) 
        lst.PutItemH(i);
    // print
    lst.Print();
    cout << endl;
    // delete header
    lst.DeleteItemH();
    cout << endl;
    lst.Print();
    cout << endl;
    // find function
    cout << "Finding instances of 3" << endl;
    cout << lst.Find(3);
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
    // delete item function
    cout << "Delting instances of 2" << endl;
    cout << lst.DeleteItem(2) << endl;
    lst.Print();
    cout << endl;




    // //Dynamic list 
    List* lst1 = new List;
    // put stuff in list
    for (int i = 0; i < 10; i++)
        lst1->PutItemH(10*i);
    lst1->Print();
    cout << endl;
    // delete head
    lst1->DeleteItemH();
    cout << endl;
    lst1->Print();
    cout << endl;
    // Find Function
    cout << "Finding instances of 30" << endl;
    cout<< lst1->Find(30);
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
    // delete instance of something
    cout << "Delting instances of 10" << endl;
    cout << lst1->DeleteItem(10) << endl;
    lst1->Print();

    delete lst1; //necessary to invoke destructor on dynamic list
    cout << endl;
    return 0;
}