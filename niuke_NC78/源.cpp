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
		//3指针方案，实现更新
		while (next)
		{
			cur->next = prev;
			prev = cur;
			cur = next;
			next = cur->next;
		}
		//还要更新一次
		cur->next = prev;
		return cur;
	}
};
