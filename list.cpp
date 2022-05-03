/*
Name: George Calvert
Class: CPSC 122, Section 1
Date Submitted: April 30, 2022
Assignment: Test 3A
Description: Program illustrates a simple linked list with recursion 
*/

#include <iostream>
using namespace std;

#include "list.h"


List::List()
{
    head = new node;
    head->item = '\0';
}
List::~List()
{
    node* cur = new node;
    cur = head;
    Destructor(cur);
    head = NULL;
    cur = NULL;
    delete cur;
    delete head;
}


bool List::IsEmpty()
{
    node* cur = new node;
    cur = head;
    if(cur->item == '\0')
    {
        return true;
    }
    return false;
}

/*
pre: an instance of list exists and is not empty
post: Returns the contents of the head of the list. 
*/
itemType List::GetItemH()
{
    itemType value = head->item;
    return value;
}

/*
pre: an instance of list exists
post: newItem is at the head of the list 
*/
void List::PutItemH(itemType item)
{
    // creates new node
    node* curr = new node;
    curr->item = item;
    curr->next = head;
    // makes head point to new node wit the users item
    head = curr;
    curr = NULL;
}

/*
pre: an instance of list exists and is not empty
post: head of the list is deleted 
*/
void List::DeleteItemH()
{
    // creates new node 
    node* temp = new node;
    node* value = new node;
    // makes temp equal to head
    temp = head;
    // makes temp next point to value
    value = temp->next;
    // makes value head
    head = value;
    temp = NULL;
    value = NULL;
}

/*
pre: an instance of list exists and is not empty
post: contents of list nodes are displayed on subsequent lines 
*/
void List::Print()
{
    node* cur = new node;
    cur = head;
    // calls recursion
    Print(cur);
}

/*
pre: an instance of list exists and is not empty
post: contents of list nodes are displayed in reverse  
*/
void List::PrintRev()
{
    node* cur = new node;
    cur = head;
    // calls recursion
    PrintRev(cur);
}

/*
pre: an instance of list exists
post: returns length of the list by counting the nodes recursively
*/
int List::GetLength()
{
    node* cur = new node;
    cur = head;
    // calls recursion
    return GetLength(cur);
}

// private
void List::Print(node* cur)
{  
    if(cur->item != '\0')
    {
        Print(cur->next);
        cout << cur->item << endl;
    }
}
void List::PrintRev(node* cur)
{ 
    if(cur->item != '\0')
    {
        cout << cur->item << endl;
        PrintRev(cur->next);
    }
    
}
void List::Destructor(node* cur)
{
    if(cur->item != '\0')
    {
        Destructor(cur->next);
        delete []cur;
    }
}
int List::GetLength(node* cur)
{
    if(cur->item != '\0')
    {
        return 1 + GetLength(cur->next);  
    }
    return 0;
}