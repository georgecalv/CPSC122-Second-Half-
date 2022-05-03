#include <iostream>
#include <string>
using namespace std;

#include "4-ListD.cpp"

//All tests are separated by function
void TestInsert();
void TestCopyConstructor();
void TestPrintForward();
void TestPrintBackwards();
void TestInsertHead();
void TestInsertTail();
void TestInsertMiddle();
void TestSort();
void TestDelete();
void TestDeleteAll();

int main()
{
    TestInsert();
    TestCopyConstructor();
    TestPrintForward();
    TestPrintBackwards();
    TestInsertHead();
    TestInsertTail();
    TestInsertMiddle();
    TestSort();
    TestDelete();
    TestDeleteAll();
    return 0;
}



void TestInsert()
{

    ListD<int>* lst = new ListD<int>;
    for (int i = 1; i <= 5; i++)
        lst->Insert(i,i);
    lst->PrintForward();
    cout << endl;

    delete lst;

    ListD<string>* lst2 = new ListD<string>;
    for (int i = 1; i < 5; i++)
        lst2->Insert("hello",i);
    lst2->PrintForward();
    cout << endl;


}

void TestCopyConstructor()
{
    ListD<int>* lst1 = new ListD<int>;
    for (int i = 1; i <= 3; i++)
        lst1->Insert(i,i);

    ListD<int>* lst2(lst1);

    cout << "Traverse lst1" << endl;
    lst1->PrintForward();
    cout << endl;
    cout << "Traverse lst2" << endl;
    lst2->PrintForward();

    // delete lst1;
    // delete lst2;
}
void TestPrintForward() 
{
    ListD<int>* lst = new ListD<int>;

    for (int i = 1; i <= 5; i++)
        lst->Insert(i,i);
    lst->PrintForward();
    cout << endl;
    //test general case insert
    cout << "Passed Insert Test 1 if 1 through 5 appear on subsequent lines" << endl;
    lst->PrintForward();
    cout << endl;
    delete lst;

}
void TestPrintBackwards()
{
    ListD<int>* lst = new ListD<int>;

    for (int i = 1; i <= 5; i++)
        lst->Insert(i,i);
    lst->PrintForward();
    cout << endl;
    //test print backwards
    cout << "Passed Print Backwards if 5 through 1 appear on subsequent lines" << endl;
    lst->PrintBackward();
    cout << endl;
    delete lst;
}
void TestInsertHead()
{
    ListD<int>* lst = new ListD<int>;

    for (int i = 1; i <= 5; i++)
        lst->Insert(i,i);
    lst->PrintForward();
    cout << endl;
    //test insert at the head
    lst->Insert(0,1);
    cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
    lst->PrintForward();
    cout << endl;
    delete lst;
}
void TestInsertTail()
{
    ListD<int>* lst = new ListD<int>;

    for (int i = 1; i <= 5; i++)
        lst->Insert(i,i);
    lst->PrintForward();
    cout << endl;
    //test insert at the tail 
    lst->Insert(100,6);
    cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
    lst->PrintForward();
    cout << endl;
    delete lst;
}
void TestInsertMiddle()
{
    ListD<int>* lst = new ListD<int>;

    for (int i = 1; i <= 5; i++)
        lst->Insert(i,i);
    lst->PrintForward();
    cout << endl;

    //test insert in middle 
    lst->Insert(50,3);
    cout << "Passed Insert Test 4 if 50 appears in middle position" << endl; 
    lst->PrintForward();
    cout << endl;

    delete lst;

}
void TestSort()
{
    ListD<int>* lst = new ListD<int>;

    int k = 1;
    for (int i = 5; i >= 1; i--)
    {
        lst->Insert(i,k);
        k++;
    }
        
    lst->PrintForward();
    cout << endl;
    //test sort 
    cout << "Passed Sort Test if list is printed in ascending order" << endl; 
    lst->Sort();
    lst->PrintForward();
    cout << endl;

    delete lst;

}
void TestDelete()
{
    ListD<int>* lst = new ListD<int>;

    for (int i = 1; i <= 5; i++)
        lst->Insert(i,i);
    lst->PrintForward();
    cout << endl;
    //test Delete
    cout << "Passed Delete if 4 is no longer in the list" << endl;
    lst->Delete(4);
    lst->PrintForward();
    cout << endl;

    ListD<int>* lst1 = new ListD<int>;
    for (int i = 1; i <= 5; i++)
        lst1->Insert(i,i);
    
    cout << "Passed Delete if 5 is no longer in the list" << endl;
    lst1->Delete(5);
    lst1->PrintForward();
    cout << endl;

    ListD<int>* lst2 = new ListD<int>;
    for (int i = 1; i <= 5; i++)
        lst2->Insert(i,i);

    cout << "Passed Delete if 1 is no longer in the list" << endl;
    lst2->Delete(1);
    lst2->PrintForward();
    cout << endl;
    

    delete lst;
    delete lst1;
    delete lst2;
}
void TestDeleteAll()
{

    ListD<int>* lst = new ListD<int>;
    for (int i = 1; i <= 5; i++)
        lst->Insert(i,i);
    lst->PrintForward();
    cout << endl;

    //test Delete All
    lst->Insert(50,5);
    lst->Insert(50,6);
    lst->PrintForward();
    cout << endl;
    cout << "Passed Delete All if the number 2 is printed and no 50s are printed after " << endl;
    cout << "deleted " << lst->DeleteAll(50) << " items" << endl;
    lst->PrintForward();
    cout << endl;

    ListD<int>* lst1 = new ListD<int>;
    for (int i = 1; i <= 5; i++)
        lst1->Insert(i,i);
    lst1->PrintForward();
    cout << endl;
    lst1->Insert(50,1);
    lst1->Insert(50,7);

    cout << "Passed Delete All if the number 2 is printed and no 50s are printed after " << endl;
    cout << "deleted " << lst1->DeleteAll(50) << " items" << endl;
    lst1->PrintForward();
    cout << endl;




}