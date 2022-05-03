/*
Name: George Calvert
Class: CPSC 122, Section 1
Date Submitted: March 2022
Assignment: Project 11
Description: Program illustrates a simple linked list with 
    head and tail pointers
*/

#include <iostream>
using namespace std;

#include "3-List.h"


//Class-related functions
//Constructor
/*
pre: None. This is the constructor function, 
    invoked like this from the 
post: an instance of List exists
*/ 
ListT::ListT()
{    
    length = 0;
    head = NULL;
    tail = NULL;

}

//Destructor
/*
pre: An instance of List exists.This is the destructor function
post: All dynamically declared memory reutrned to heap   
*/ 
ListT::~ListT()
{
    delete []head;
    delete []tail;
}

//Head-related functions

/*
pre: an instance of List exists
post: node containing itemIn is at 
    the head of the list 
*/
void ListT::PutItemH(itemType itemIn)
{
    // creates new node
    node* curr = new node;
    curr->item = itemIn;
    curr->next = head;
    // makes head point to new node wit the users item
    head = curr;
    // sets curr to tail if length is zero
    if(length == 0)
    {
        tail = curr;
        tail->next = NULL;
    }
    // delete pointer
    curr = NULL;
    delete curr;
    length += 1;
}
/*
pre: an instance of listT exists
post: node containing itemIn is at the tail of the list 
*/ 
void ListT::PutItemT(const itemType itemIn)
{
    node* temp = new node;
    node* newTail = new node;
    temp = tail;
    tail = newTail;
    temp->next = tail;
    tail->item = itemIn;
    // increase leangth
    length += 1;
    // delete pointers
    tail->next = NULL; 
    temp = NULL;
    newTail = NULL;
    delete temp;
    delete newTail;
}
/*
pre: an instance of List exists and is not empty
post: Returns the contents pointed to by the head of the list 
*/
itemType ListT::GetItemH() const
{
    itemType value = head->item;
    return value;
}
/*
pre: an instance of list exists and is not empty
post: Returns the contents of the node at 
    the tail of the list. 
*/
itemType ListT::GetItemT() const
{
    itemType result = tail->item;
    return result;
}
/*
pre: an instance of List exists and is not empty
post: returns the number of nodes in the list 
    that stores target 
*/
int ListT::FindItem(const itemType target) const
{
   // makes node to traverse through entire list created
    node* temp = new node;
    temp = head;
    int result = 0;

    // traversing
    for(int i = 0; i < length; i++)
    {
        itemType value = temp->item;
        if(value == target)
        {
            result += 1;
        }
        temp = temp->next;
    }
    temp = NULL;
    delete temp;
    return result;
}
/*
pre: an instance of list exists and is not empty
post: Node pointed to by head is deleted 
*/
void ListT::DeleteItemH()
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
    // delete pointers
    temp = NULL;
    value = NULL;
    delete temp;
    delete value;
    length -= 1;
}
/*
pre: an instance of list exists and is not empty
post: node at the tail of the list is deleted 
*/
void ListT::DeleteItemT()
{
    node* prev = new node;
    prev = head;
    // if head is the tail
    if(prev == tail)
    {
        head = NULL;
        tail = NULL;
    }
    // head isnt the tail
    else
    {
        // finds tail
        node* curr = new node;
        curr = head->next;
        while(curr != tail)
        {
            prev = curr;
            curr = curr->next;
        }
        // deltes tail
        prev->next = NULL;
        tail = prev;
        curr = NULL;
        delete curr;
    }
    // deltes pointers
    prev = NULL;
    delete prev;
    length -= 1;
}
/*
pre:  an instance of List exists and is not empty 
post: deletes all nodes that store target.Returns
        the number of nodes deleted 
*/
int ListT::DeleteItem(const itemType target) 
{
    int nodeDel = 0;
    node* prev = new node;
    prev = head;
    itemType check = prev->item;
    // creates new curr and next every loop
    node* curr = new node;
    node* nextNode = new node;
    // checks if header has the target
    if(check == target)
    {
        DeleteItemH();
        nodeDel += 1;
        length -= 1;
    }
    // for loop traverses the list
    for(int i = 1; i < length; i++)
    {

        // makes prev next point to curr
        curr = prev->next;
        // makes curr next point to nextNode
        nextNode = curr->next;

        itemType value = curr->item;

        // checks value of curr
        if (value == target)
        {
            // makes prev point to next node
            // skipping over curr
            prev->next = nextNode;

            nodeDel += 1;
            length -= 1;
        }
        else 
        {
            // moving forward one node each
            prev = curr;
            curr = nextNode;
            nextNode = nextNode->next;

        }
    }
    // delte pointers
    prev = NULL;
    curr = NULL;
    nextNode = NULL;
    delete prev;
    delete curr;
    delete nextNode;
    return nodeDel;
}


//General operations on the class
/*
pre: an instance of list exists and is not empty
post: contents of list nodes are displayed on 
    subsequent lines
*/
void ListT::Print() const
{
    node* temp = new node;
    temp = head;

    // prints every value 
    for(int i = 0; i < length; i++)
    {
        itemType value = temp->item;
        cout << value << endl;
        temp = temp->next;
    }
    temp = NULL;
    delete temp;
    cout << endl;

}
/*
pre: an instance of List exists
post: returns true if list is empty, false otherwise
*/ 
bool ListT::IsEmpty() const
{
    if(length == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
/*
pre: an instance of List exists
post: returns length of the list 
*/
int ListT::GetLength() const 
{
    return length;
}