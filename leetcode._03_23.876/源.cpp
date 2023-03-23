/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow, * fast;//快慢指针
    fast = slow = head;
    while (fast && fast->next)//偶数和奇数2种情况
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}