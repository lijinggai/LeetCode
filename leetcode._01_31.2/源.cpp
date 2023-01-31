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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int t = 0, i = 1;
        ListNode* ans = new ListNode, * tmp = ans;
        while (l1 != nullptr || l2 != nullptr || t != 0)
        {
            if (l1 != nullptr)
            {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                t += l2->val;
                l2 = l2->next;
            }
            if (i == 1)
            {
                i = 0;
                tmp->val = t % 10;
            }
            else
            {
                tmp->next = new ListNode(t % 10);
                tmp = tmp->next;
            }
            t /= 10;
        }
        return ans;
    }
};