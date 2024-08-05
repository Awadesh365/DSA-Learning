#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-linked-list/description/

/**
 */
//  Definition for singly-linked list.
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newhead = NULL;
        while (head != NULL)
        {
            ListNode *dummy = head->next;
            head->next = newhead;
            newhead = head;
            head = dummy;
        }
        return newhead;
    }
};

int main()
{
    return 0;
}