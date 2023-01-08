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
    int pairSum(ListNode* head) {
        stack<ListNode*> st;
        int n = 0;
        for (ListNode* cur = head; cur; cur = cur->next)
        {
            n++;
        }
        cout << n;
        for (int i = 0; i < n / 2; i++)
        {
            st.push(head);
            head = head->next;
        }
        int answer = -1;
        for (int i = 0; i < n / 2; i++)
        {
            ListNode* tmp = st.top();
            answer = max(answer, tmp->val + head->val);
            st.pop();
            head = head->next;
        }
        return answer;
    }
};