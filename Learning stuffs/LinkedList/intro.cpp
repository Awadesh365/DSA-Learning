#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
};
void PrintList(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << endl;
        n = n->next;
    }
}
int main()
{
    Node *head = new Node();
    Node *first = new Node();
    Node *second = new Node();

    head->value = 1;
    head->next = first;

    first->value = 2;
    first->next = second;
    second->value = 3;

    second->next = NULL;

    PrintList(head);

    return 0;
}