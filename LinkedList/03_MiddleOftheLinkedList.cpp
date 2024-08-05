#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/middle-of-the-linked-list/description/

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
    ListNode *middleNode(ListNode *head)
    {
        if (head->next == NULL)
            return head;

        ListNode *temp = head;
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;

        int cnt = 0;

        while (fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next;
            cnt++;

            if (fastPtr->next != NULL)
            {
                fastPtr = fastPtr->next;
                cnt++;
            }

            slowPtr = slowPtr->next;
        }
        return slowPtr;
    }
};

int main()
{
    return 0;
}