/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***************************** Convert Singly Circular Linkedlist C to C++ ******************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#pragma pack(1)

typedef struct node NODE;
typedef struct node *PNODE;

struct node
{
    int data;
    struct node *next;
};

class SinglyCL
{
public:
    PNODE First;
    PNODE Last;
    int iCount;

    SinglyCL();

    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

    void Display();
};

SinglyCL::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void SinglyCL::InsertFirst(int No)
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }

    Last->next = First;
    iCount++;
}

void SinglyCL::InsertLast(int No)
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }

    Last->next = First;
    iCount++;
}

void SinglyCL::DeleteFirst()
{
    if (First == NULL) // If linked list is empty
    {
        return;
    }
    else if (First->next == First) //(First == Last) Linked list contain only one node
    {
        delete (First);
        First = NULL;
        Last = NULL;

        iCount--;
    }
    else // Linkedlist contain more than  node
    {
        First = First->next;
        delete (Last->next);
        Last->next = First;

        iCount--;
    }
}

void SinglyCL::DeleteLast()
{
    if (First == NULL) // If linked list is empty
    {
        return;
    }
    else if (First == Last) // s Linked list contain only one node
    {
        delete (First);
        First = NULL;
        Last = NULL;

        iCount--;
    }
    else // Linkedlist contain more than  node
    {
        PNODE Temp = First;

        while (Temp->next->next != First)
        {
            Temp = Temp->next;
        }

        delete (Temp->next); // delete(Last)
        Last = Temp;
        Last->next = First;

        iCount--;
    }
}

void SinglyCL::InsertAtPos(int No, int ipos)
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
        PNODE newn = new NODE;

        newn->data = No;
        newn->next = NULL;

        PNODE Temp = First;

        int i = 1;
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

void SinglyCL::DeleteAtPos(int ipos)
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

void SinglyCL::Display()
{
    PNODE Temp = First;

    do
    {
        cout << "|" << Temp->data << "|->";
        Temp = Temp->next;
    } while (Temp != Last->next);
    cout << endl;
}

int main()
{
    SinglyCL obj; // Static memory allocation

    SinglyCL *ptr = new SinglyCL(); // Dynamic memory allocaobj.

    obj.InsertFirst(51);
    obj.InsertFirst(41);
    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout << obj.iCount << endl;
    cout << endl;

    obj.InsertLast(71);
    obj.InsertLast(81);
    obj.InsertLast(91);
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.Display();
    cout << obj.iCount << endl;
    cout << endl;

    obj.InsertAtPos(61, 6);
    obj.Display();
    cout << obj.iCount << endl;
    cout << endl;

    obj.DeleteAtPos(6);
    obj.Display();
    cout << obj.iCount << endl;
    cout << endl;

    obj.DeleteFirst();
    obj.Display();
    cout << obj.iCount << endl;
    cout << endl;

    obj.DeleteLast();
    obj.Display();
    cout << obj.iCount << endl;
    cout << endl;

    return 0;
}