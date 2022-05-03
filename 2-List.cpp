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


//Class-related functions
//Constructor
/*
pre: None. This is the constructor function, invoked like this from the 
post: an instance of List exists
*/ 
List::List()
{    
    length = 0;
    head = NULL;

}

//Destructor
/*
pre: An instance of List exists.  This is the destructor function
post: All dynamically declared memory, i.e., the memory for all nodes, has been
    returned to the heap.   
*/ 
List::~List()
{
    delete []head;
}

//Head-related functions

/*
pre: an instance of List exists
post: node containing itemIn is at the head of the list 
*/
void List::PutItemH(itemType itemIn)
{
    // creates new node
    node* curr = new node;
    curr->item = itemIn;
    curr->next = head;
    // makes head point to new node wit the users item
    head = curr;
    curr = NULL;
    length += 1;
}
/*
pre: an instance of List exists and is not empty
post: Returns the contents pointed to by the head of the list 
*/
itemType List::GetItemH() const
{
    itemType value = head->item;
    return value;
}
/*
pre: an instance of List exists and is not empty
post: returns the number of nodes in the list that stores target 
*/
int List::Find(const itemType target) const
{
    // makes node to traverse through entire list created
    node* temp = new node;
    temp = head;
    int result = 0;

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
    return result;
}
/*
pre: an instance of list exists and is not empty
post: Node pointed to by head is deleted 
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
    length -= 1;
}
/*
pre:  an instance of List exists and is not empty 
post: deletes all nodes that store target.  Returns
        the number of nodes deleted 
*/
int List::DeleteItem(const itemType target) 
{
    int nodeDel = 0;
    node* prev = new node;
    prev = head;
    itemType check = prev->item;
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
        // creates new curr and next every loop
        node* curr = new node;
        node* nextNode = new node;

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
    return nodeDel;
}


//General operations on the class
/*
pre: an instance of list exists and is not empty
post: contents of list nodes are displayed on subsequent lines
*/
void List::Print() const
{
    node* temp = new node;
    temp = head;

    // prints every value on one line
    for(int i = 0; i < length; i++)
    {
        itemType value = temp->item;
        cout << value << endl;
        temp = temp->next;
    }
    temp = NULL;
    cout << endl;

}
/*
pre: an instance of List exists
post: returns true if list is empty, false otherwise
*/ 
bool List::IsEmpty() const
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
int List::GetLength() const 
{
    return length;
}