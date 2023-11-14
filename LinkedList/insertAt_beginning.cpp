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
void insert_At_beginning(Node **head, int newData)
{
    Node *newHead = new Node();
    newHead->data = newData;
    newHead->Next = *head;
    *head = newHead;
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
    insert_At_beginning(&head, newData);

    printList(head);
    return 0;
}