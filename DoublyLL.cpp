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

class DoublyLL
{
public:
    PNODE First;
    int iCount;

    DoublyLL();
    void InsertFirst(int No);
    void InsertLast(int No);
    void InsertAtPos(int No, int ipos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);

    void Display();
};

DoublyLL::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

void DoublyLL ::InsertFirst(int No)
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;

        iCount++;
    }
    else
    {
        newn->next = First;
        newn->next->prev = newn;
        First = newn;

        iCount++;
    }
}

void DoublyLL ::InsertLast(int No)
{
    PNODE newn = new NODE;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
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
        newn->prev = Temp;

        iCount++;
    }
}

void DoublyLL ::DeleteFirst()
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
        First = First->next;
        delete (First->prev);
        First->prev = NULL;

        iCount--;
    }
}

void DoublyLL ::DeleteLast()
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

void DoublyLL ::InsertAtPos(int No, int ipos)
{
    if ((ipos < 1) || (ipos > (iCount + 1)))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(No);
    }
    else if (ipos == (iCount + 1))
    {
        InsertLast(No);
    }
    else
    {
        PNODE newn = new NODE;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE Temp = First;

        int i = 1;
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

void DoublyLL ::DeleteAtPos(int ipos)
{
    if ((ipos < 1) || (ipos > (iCount)))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == (iCount))
    {
        DeleteLast();
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
        Temp1->next->prev = Temp1;

        iCount--;
    }
}

void DoublyLL ::Display()
{
    PNODE Temp = First;

    cout << "Elements of Doubly linked list are:" << endl;

    cout << "NULL<-|";
    while (Temp != NULL)
    {
        cout << Temp->data << "|->";
        Temp = Temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    DoublyLL obj;

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