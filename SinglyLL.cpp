//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//*******************************Convert Singly linkedlist C to C++*******************************
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
};

class SinglyLL
{
public:
    PNODE First;
    int iCount;

    SinglyLL();

    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

    void Display();
};

SinglyLL ::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

void SinglyLL::InsertFirst(int No)
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount==0)
    {
        First = newn;
        iCount++;
    }
    else
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

void SinglyLL::InsertLast(int No)
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount==0)
    {
        First = newn;
        iCount++;
    }
    else
    {
        PNODE Temp = First;

        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }

        Temp->next = newn;
        iCount++;
    }
}

void SinglyLL::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete (First);
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE Temp = First;

        First = Temp->next;
        delete (Temp);
        iCount--;
    }
}

void SinglyLL::DeleteLast()
{
    if (First == NULL)
    {
        return;
    }
    else if (First->next == NULL)
    {
        delete (First);
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE Temp = First;

        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }

        delete (Temp->next);
        Temp->next = NULL;
        iCount--;
    }
}

void SinglyLL::InsertAtPos(int No, int ipos)
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

        PNODE Temp = First;

        i = 1;
        while (i < ipos - 1)
        {
            Temp = Temp->next;
            i++;
        }

        newn->next = Temp->next;
        Temp->next = newn;
        iCount++;
    }
}

void SinglyLL::DeleteAtPos(int ipos)
{
    if ((ipos < 0) || (ipos > (iCount)))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (ipos == 0)
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
        PNODE Temp1 = First;
        int i = 1;

        while (i < ipos - 1)
        {
            Temp1 = Temp1->next;
            i++;
        }

        PNODE Temp2 = Temp1->next;

        Temp1->next = Temp2->next;
        delete (Temp2);
        iCount--;
    }
}

void SinglyLL::Display()
{
    PNODE Temp = First;

    cout << "Elements of linked list as:" << endl;

    while (Temp != NULL)
    {
        cout << Temp->data << "|->";
        Temp = Temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    SinglyLL obj;

    obj.InsertFirst(1);
    // obj.InsertFirst(41);
    // obj.InsertFirst(31);
    // obj.InsertFirst(21);
    // obj.InsertFirst(11);
    obj.Display();
    cout << obj.iCount << endl;
    cout << endl;

    obj.InsertLast(3);
    // obj.InsertLast(81);
    // obj.InsertLast(91);
    // obj.InsertLast(101);
    // obj.InsertLast(111);
    obj.Display();
    cout << obj.iCount << endl;
    cout << endl;

    // obj.InsertAtPos(2, 1);
    // obj.Display();
    // cout << obj.iCount << endl;
    // cout << endl;

    // obj.DeleteAtPos(2);
    // obj.Display();
    // cout << obj.iCount << endl;
    // cout << endl;

    // obj.DeleteFirst();
    // obj.Display();
    // cout << obj.iCount << endl;
    // cout << endl;

    // obj.DeleteLast();
    // obj.Display();
    // cout << obj.iCount << endl;
    // cout << endl;

    // int ret = 0;

    // obj.InsertFirst(2);
    // obj.Display();

    // obj.DeleteAtPos(1);
    // obj.Display();

    // obj.InsertFirst(2);
    // obj.Display();

    // obj.InsertFirst(7);
    // obj.Display();

    // obj.InsertFirst(3);
    // obj.Display();

    // obj.InsertFirst(2);
    // obj.Display();

    // obj.InsertFirst(5);
    // obj.Display();

    // obj.addAtTail(5);
    // obj.Display();

    // ret = obj.get(5);
    // cout << "Value at index 1 is :" << ret << endl;

    // obj.deleteAtIndex(6);
    // obj.Display();

    // obj.deleteAtIndex(4);
    // obj.Display();

    return 0;
}