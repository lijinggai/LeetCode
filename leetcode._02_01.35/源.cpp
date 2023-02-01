/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* ans = new Node(head->val), * cur = ans, * headt = head->next;
        int i = 0;
        vector<Node*> tmp(1, ans);
        unordered_map<Node*, int> m;
        m[head] = i++;
        while (headt)
        {
            cur->next = new Node(headt->val);
            tmp.push_back(cur->next);
            m[headt] = i++;
            cur = cur->next;
            headt = headt->next;
        }
        cur = ans;
        while (head)
        {
            if (head->random != nullptr)
            {
                cur->random = tmp[m.find(head->random)->second];
            }
            head = head->next;
            cur = cur->next;
        }
        return ans;
    }
};