/*
Name: George Calvert
Class: CPSC 122, Section 1
Date Submitted: March 20, 2022
Assignment: Project 9 
Description: Program illustrates a simple linked list  
*/

#ifndef LIST_H
#define LIST_H

typedef int itemType;

struct node
{
    itemType item;
    node* next;
};

class List
{
    public:
        /*
        pre: None. This is the constructor function 
        post: an instance of List exists
        */ 
        List();

        /*
        pre: An instance of List exists.This is the destructor function
        post: All dynamically declared memory, i.e., 
        the memory for all nodes, has been
        returned to the heap.   
        */ 
        ~List();

        /*
        pre: an instance of List exists
        post: returns true if list is empty, false otherwise
        */ 
        bool IsEmpty() const;

        /*
        pre: an instance of List exists
        post: returns length of the list 
        */
        int GetLength() const;

        /*
        pre: an instance of List exists
        post: node containing itemIn is at the head of the list 
        */
        void PutItemH(const itemType itemIn);

        /*
        pre: an instance of List exists and is not empty
        post: Returns the contents pointed to by the head of the list 
        */
        itemType GetItemH() const;

        /*
        pre: an instance of list exists and is not empty
        post: Node pointed to by head is deleted 
        */
        void DeleteItemH();

        /*
        pre: an instance of list exists and is not empty
        post: contents of list nodes are displayed on subsequent lines
        */
        void Print() const;

        /*
        pre: an instance of List exists and is not empty
        post: returns the number of nodes in the list that stores target 
        */
        int Find(const itemType target) const;

        /*
        pre:  an instance of List exists and is not empty 
        post: deletes all nodes that store target.  Returns
                the number of nodes deleted 
        */
        int DeleteItem(const itemType target);

    private:
        int length;   //length of the list
        node* head;   //points to the first node on the list 
};
#endif