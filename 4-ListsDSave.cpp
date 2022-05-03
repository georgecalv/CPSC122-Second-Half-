#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

ListD::ListD()
{
    InitializeVars();
}

ListD::ListD(ListD* lst)
{
    InitializeVars();
    //returns a pointer to the first node, which is what we want here
    doubleNode* cur = lst->FindPosition(2);
    for (int i = 1; i <= lst->length; i++)
    {
        cout << cur->item << endl;
        Insert(cur->item,i);
        cur = cur->next;
    }
}

void ListD::InitializeVars()
{
    length = 0;

    //create dummy nodes;
    head = new doubleNode;
    tail = new doubleNode;

    //set values for head dummy node;
    head->prev = NULL;
    head->item = INT_MIN;
    head->next = tail;

    //set values for tail dummy node;
    tail->prev = head; 
    tail->item = INT_MAX;
    tail->next = NULL;
}

//how would you do this?
ListD::~ListD()
{
    delete []head;
    delete []tail;
}

doubleNode* ListD::FindPosition(int pos)
{
    //Inserting at the tail is a special case.  It can be made much more efficient than
    //this.
    doubleNode* cur = head;
    int i = 0; //begin at the dummy node
    while (i < pos - 1)
    {
        cur = cur->next;
        i++;
    }
    return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
    //new node goes between these two nodes
    doubleNode* insertPtA = FindPosition(pos);  
    doubleNode* insertPtB = insertPtA->next; 

    //create new node and set its values
    doubleNode* tmp = new doubleNode; 
    tmp->prev = insertPtA;
    tmp->item = item;
    tmp->next = insertPtB;

    //set pointers for nodes before and after the insertion point
    insertPtA->next = tmp;
    insertPtB->prev = tmp;

    length++;
}

void ListD::PrintForward()
{
    doubleNode* cur = head->next;

    int i = 0;
    // goes through list
    while (i < length)
    {
        cout << cur->item << endl;
        // goes down forward
        cur = cur->next;
        i++;
    }
    cur = NULL;
    delete cur;
}

void ListD::PrintBackward()
{
    doubleNode* cur = tail->prev;

    int i = 0;
    // goes through list
    while(i < length)
    {
        cout << cur->item << endl;
        // goes up the list backwards
        cur = cur->prev;
        i++;
    }
    cur = NULL;
    delete cur;

}

void ListD::Delete(int pos)
{
    doubleNode* cur = head->next;


    int i = 0;
    while(i < pos)
    {
        cur = cur->next;
        i++;
    }
    // removes that node from the list 
    // modifies the next and prev values 
    doubleNode* prior = cur->prev;
    doubleNode* nextNode = cur->next;
    prior->next = nextNode;
    nextNode->prev = prior;
    length -= 1;
    cur = NULL;
    prior = NULL;
    nextNode = NULL;

    delete cur, prior, nextNode;
}
int ListD::DeleteAll(itemType itemIn)
{
    int count = 0;
    doubleNode* cur = head->next;

    // goes through list
    for(int i = 0; i < length; i++)
    {
        // if item is in this pos
        if(cur->item == itemIn)
        {
            // calls delete for this position
            Delete(i);
            i -= 1;
            count += 1;
        }

        cur = cur->next;
        
    }
    cur = NULL;
    delete cur;
    return count;
}
void ListD::Sort()
{
    doubleNode* inner = head->next;
    doubleNode* swap;
    itemType compare;
    // goes through list for comparisons
    for(int i = 0; i < length; i++)
    {
        // goes through i + 1
        for(int k = i + 1; k < length; k++)
        {
            doubleNode* nextNode = inner->next;
            compare = nextNode->item;
            // switches when something is bigger
            if(inner->item > compare)
            {
                swap = FindPosition(k + 1);
                itemType temp = inner->item;
                inner->item = swap->item;
                swap->item = temp;
            }
            nextNode = NULL;
            delete nextNode;  
        }
        inner = inner->next;
        compare = inner->item;
    }
    inner, swap = NULL;
    delete inner, swap;

}