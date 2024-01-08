#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

/*
    Getting headPtr in ** i.e reference to a pointer variable
*/
void Insert(int newData, node **headPtr)
{
    node *temp = new node();
    temp->data = newData;
    temp->next = *headPtr;
    *headPtr = temp;
}

void Print(node *head)
{
    while (head != NULL)
    {
        cout << (head->data) << endl;
        head = head->next;
    }
}

int main()
{
    node *head = new node();
    node *first = new node();

    head->data = 23, first->data = 24;
    head->next = first;
    first->next = NULL;

    Insert(22, &head); // passing reference to head so that we don't need to return it.
    Print(head);

    return 0;
}