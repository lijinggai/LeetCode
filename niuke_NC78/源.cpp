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
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr)
			return nullptr;
		ListNode* prev = nullptr, * cur = pHead, * next = pHead->next;
		//3ָ�뷽����ʵ�ָ���
		while (next)
		{
			cur->next = prev;
			prev = cur;
			cur = next;
			next = cur->next;
		}
		//��Ҫ����һ��
		cur->next = prev;
		return cur;
	}
};
