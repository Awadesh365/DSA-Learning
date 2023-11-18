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

void insert_AtBottom(Node *head, int newElement)
{
    Node *newNode = new Node();
    newNode->data = newElement;
    newNode->Next = NULL;

    while (head->Next != NULL)
        head = head->Next;

    head->Next = newNode;
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
    insert_AtBottom(head, newData);

    printList(head);
    return 0;
}