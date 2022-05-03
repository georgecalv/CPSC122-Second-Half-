#include <iostream>
#include <climits>
#include "4-ListD.h"
using namespace std;

template class ListD<int>;

template <typename T>
ListD<T>::ListD()
{
    InitializeVars();
}

template <typename T>
ListD<T>::ListD(ListD<T>* lst)
{
    InitializeVars();
    //returns a pointer to the first node, which is what we want here
    doubleNode<T>* cur = lst->FindPosition(2);
    for (int i = 1; i <= lst->length; i++)
    {
        cout << cur->item << endl;
        Insert(cur->item,i);
        cur = cur->next;
    }
}

template <typename T>
void ListD<T>::InitializeVars()
{
    length = 0;

    //create dummy nodes;
    head = new doubleNode<T>;
    tail = new doubleNode<T>;

    //set values for head dummy node;
    head->prev = NULL;

    head->next = tail;

    //set values for tail dummy node;
    tail->prev = head; 

    tail->next = NULL;
}

template <typename T>
ListD<T>::~ListD()
{
    delete []head;
    delete []tail;
}
template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
     doubleNode<T>* cur = head;
    int i = 0; //begin at the dummy node
    while (i < pos - 1)
    {
        cur = cur->next;
        i++;
    }
    return cur;
} 
template <typename T>
void ListD<T>::Insert(const T item, int pos)
{
    //new node goes between these two nodes
    doubleNode<T>* insertPtA = FindPosition(pos);  
    doubleNode<T>* insertPtB = insertPtA->next; 

    //create new node and set its values
    doubleNode<T>* tmp = new doubleNode<T>; 
    tmp->prev = insertPtA;
    tmp->item = item;
    tmp->next = insertPtB;

    //set pointers for nodes before and after the insertion point
    insertPtA->next = tmp;
    insertPtB->prev = tmp;

    length++;
}
template <typename T>
void ListD<T>::PrintForward()
{
    doubleNode<T>* cur = head->next;

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
    // delete cur;
}
template <typename T>
void ListD<T>::PrintBackward()
{
    doubleNode<T>* cur = tail->prev;

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
    // delete cur;

}
template <typename T>
void ListD<T>::Delete(int pos)
{
    doubleNode<T>* cur = head;

    int i = 0;
    while(i < pos)
    {
        cur = cur->next;
        i++;
    }

    doubleNode<T>* prior = cur->prev;
    doubleNode<T>* nextNode = cur->next;
    // cur is the tail
    if(cur->next == tail)
    {
        tail->prev = prior;
        prior->next = tail;
        tail->next = NULL;
        cur->next = NULL;
        cur = NULL;
        length -= 1;
        // delete cur;
    }
    // removes that node from the list 
    // modifies the next and prev values 
    else
    {
        prior->next = nextNode;
        nextNode->prev = prior;
        if(nextNode->next == tail)
        {
            tail->prev = nextNode;
            nextNode->next = tail;
        }
        length -= 1;
        cur = NULL;
        prior = NULL;
        nextNode = NULL;
        // delete cur, prior, nextNode;
    }
}
template <typename T>
int ListD<T>::DeleteAll(T itemIn)
{
    int count = 0;
    doubleNode<T>* cur = head->next;

    // goes through list
    for(int i = 1; i <= length; i++)
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
template <typename T>
void ListD<T>::Sort()
{
    // is in the outer loop
    doubleNode<T>* inner = head->next;
    // compare value in the inner loop
    doubleNode<T>* nextNode = inner->next;
    doubleNode<T>* swap;
    T compare;
    T temp;
    T min;
    bool check = false;
    // goes through list for comparisons
    for(int i = 1; i <= length; i++)
    {
        min = inner->item;
        // goes through i + 1
        for(int k = i + 1; k <= length; k++)
        {
            compare = nextNode->item;
            // switches compare to min when min is bigger
            if(min > compare)
            {
                swap = nextNode;
                min = compare;
                check = true;
            }
            // goes to nextNode
            nextNode = nextNode->next;
        }
        // swap
        if(check)
        {
            temp = inner->item;
            inner->item = min;
            swap->item = temp;
            check = false;
        }
        inner = inner->next;
        nextNode = inner->next;
    }
    inner, swap, nextNode = NULL;
    // delete inner, swap, nextNode;
}