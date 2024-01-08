#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

void Print(node *head)
{
    while (head != NULL)
    {
        cout << (head->data) << endl;
        head = head->next;
    }
}

void reverse(node **head)
{
    node *temp = *head;
    node *prev = NULL;

    while (temp != NULL)
    {
        node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    *head = prev;
}
int main()
{
    node *head = new node();
    node *first = new node();
    node *second = new node();
    node *third = new node();

    head->data = 23, first->data = 24, second->data = 25, third->data = 26;

    head->next = first, first->next = second, second->next = third;
    third->next = NULL;

    Print(head);

    reverse(&head);

    Print(head);

    return 0;
}