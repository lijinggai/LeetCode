/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr && pHead2 == nullptr)
            return nullptr;
        ListNode* result = new ListNode(-1);
        ListNode* cur = result;
        while (pHead1 && pHead2) {
            if (pHead1->val > pHead2->val) {
                cur->next = pHead2;
                cur = cur->next;
                pHead2 = pHead2->next;
            }
            else {
                {
                    cur->next = pHead1;
                    cur = cur->next;
                    pHead1 = pHead1->next;
                }
            }
        }
        if (pHead1 == nullptr)
            cur->next = pHead2;
        else
            cur->next = pHead1;
        return result->next;
    }
};
