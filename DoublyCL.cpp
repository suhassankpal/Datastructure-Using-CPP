///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************************Doubly Circular LinkedList in C to C++*********************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#pragma pack(1)

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

class DoublyCL
{
public:
    PNODE First;
    PNODE Last;
    int iCount;

    DoublyCL();

    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

    void Display();
};

DoublyCL::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void DoublyCL::InsertFirst(int No)
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;

        First->prev = Last;
        Last->next = First;

        iCount++;
    }
    else
    {
        newn->next = First;
        newn->next->prev = newn;
        First = newn;

        First->prev = Last;
        Last->next = First;

        iCount++;
    }
}

void DoublyCL::InsertLast(int No)
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;

        First->prev = Last;
        Last->next = First;

        iCount++;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;

        First->prev = Last;
        Last->next = First;

        iCount++;
    }
}

void DoublyCL::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if (First == Last)
    {
        delete (First);
        First = NULL;
        Last = NULL;

        iCount--;
    }
    else
    {
        First = First->next;
        delete (First->prev);

        First->prev = Last;
        Last->next = First;

        iCount--;
    }
}

void DoublyCL::DeleteLast()
{
    if ((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if (First == Last)
    {
        delete (First);
        First = NULL;
        Last = NULL;

        iCount--;
    }
    else
    {
        PNODE Temp = First;

        Last = (Last->prev);
        delete ((Last)->next);

        (First)->prev = Last;
        (Last)->next = First;

        iCount--;
    }
}

void DoublyCL::InsertAtPos(int No, int ipos)
{
    if ((ipos < 1) || (ipos > (iCount + 1)))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(No);
        iCount++;
    }
    else if (ipos == (iCount + 1))
    {
        InsertLast(No);
        iCount++;
    }
    else
    {
        int i = 0;

        PNODE newn = new NODE;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE Temp = First;

        i = 1;
        while (i < ipos - 1)
        {
            Temp = Temp->next;
            i++;
        }

        newn->next = Temp->next;
        newn->next->prev = newn;

        newn->prev = Temp;
        Temp->next = newn;

        iCount++;
    }
}

void DoublyCL::DeleteAtPos(int ipos)
{
    if ((ipos < 1) || (ipos > (iCount)))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
        iCount--;
    }
    else if (ipos == (iCount))
    {
        DeleteLast();
        iCount--;
    }
    else
    {
        int i = 0;

        PNODE Temp = First;

        i = 1;
        while (i < ipos - 1)
        {
            Temp = Temp->next;
            i++;
        }

        Temp->next = Temp->next->next;
        delete (Temp->next->prev);
        Temp->next->prev = Temp;

        iCount--;
    }
}

void DoublyCL::Display()
{
    PNODE Temp = First;

    cout << "<=|";

    do
    {
        cout << First->data << "|=>";
        First = First->next;
    } while (First != Last->next);

    cout << endl;
}

int main()
{
    DoublyCL *ptr = NULL;
    ptr = new DoublyCL();

    ptr->InsertFirst(51);
    ptr->InsertFirst(41);
    ptr->InsertFirst(31);
    ptr->InsertFirst(21);
    ptr->InsertFirst(11);
    ptr->Display();
    cout << ptr->iCount << endl;
    cout << endl;

    ptr->InsertLast(71);
    ptr->InsertLast(81);
    ptr->InsertLast(91);
    ptr->InsertLast(101);
    ptr->InsertLast(111);
    ptr->Display();
    cout << ptr->iCount << endl;
    cout << endl;

    ptr->InsertAtPos(61, 6);
    ptr->Display();
    cout << ptr->iCount << endl;
    cout << endl;

    ptr->DeleteAtPos(6);
    ptr->Display();
    cout << ptr->iCount << endl;
    cout << endl;

    ptr->DeleteFirst();
    ptr->Display();
    cout << ptr->iCount << endl;
    cout << endl;

    ptr->DeleteLast();
    ptr->Display();
    cout << ptr->iCount << endl;
    cout << endl;

    return 0;
}