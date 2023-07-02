
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode* result = new ListNode(-1);
        result->next = pHead;
        ListNode* res = result, * cur = pHead;
        while (cur)
        {
            while (cur->next != nullptr && cur->val != cur->next->val)
            {
                cur = cur->next;
                res = res->next;
            }
            while (cur->next != nullptr && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            //1.中间部分重复
            //2.最后部分重复
            //3.最后没有重复走到末尾
            if (res->next != cur)
                res->next = cur->next;
            cur = cur->next;
        }
        return result->next;
    }
};