/*  Awadesh */
#include <bits/stdc++.h>
using namespace std;

// https ://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *start = new ListNode();

        start->next = head;

        ListNode *fastPtr = start, *slowPtr = start;

        for (int i = 0; i < n; i++)
            fastPtr = fastPtr->next;

        while (fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }

        ListNode *temp = slowPtr->next;
        slowPtr->next = slowPtr->next->next;
        temp->next = nullptr;

        delete (temp);

        return start->next;
    }
};

int main()
{
    return 0;
}