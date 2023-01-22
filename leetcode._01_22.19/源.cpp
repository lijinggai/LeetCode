/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 1;
        for (ListNode* cur = head; cur->next; cur = cur->next)
        {
            len++;//计算节点个数
        }
        ListNode* cur = head;
        for (int i = 1; i < len - n; i++)
        {
            cur = cur->next;//删除节点前一个
        }
        if (len == n)
            return head->next;
        else if (len > n)
        {
            ListNode* prev = cur;
            prev->next = cur->next->next;
        }
        return head;
    }
};