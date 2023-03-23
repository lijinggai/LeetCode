/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow, * fast;//����ָ��
    fast = slow = head;
    while (fast && fast->next)//ż��������2�����
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}