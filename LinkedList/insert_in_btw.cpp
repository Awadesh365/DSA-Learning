#include <bits/stdc++.h>
using namespace std;

// Node of LinkedList
struct Node
{
    int data;
    Node *Next;
};

// printing the linkedlist
void printList(Node *head)
{
    if (head == NULL)
        return;

    cout << (head->data) << endl;
    printList(head->Next);
}

void insert_In_Between(Node *prevNode, int newData)
{
    Node *intermediate = new Node();

    intermediate->Next = prevNode->Next;
    intermediate->data = newData;
    prevNode->Next = intermediate;
}

int main()
{
    Node *head = new Node();
    Node *first = new Node();
    Node *second = new Node();

    head->data = 24;
    head->Next = first;

    first->data = 25;
    first->Next = second;

    second->data = 26;
    second->Next = NULL;

    int newData = 23;
    insert_In_Between(first, newData);

    printList(head);
    return 0;
}