/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
private:
    void recursion(ListNode* head, vector<int>& v)
    {
        if (head == nullptr)
            return;
        recursion(head->next, v);
        v.push_back(head->val);
    }
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        recursion(head, result);
        return result;
    }
};
