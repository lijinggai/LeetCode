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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr)
			return nullptr;
		ListNode* cur = pListHead;
		int count = 0;
		while (cur)
		{
			count++;
			cur = cur->next;
		}
		count -= k;
		if (count < 0)
			return nullptr;;
		while (count--)
		{
			pListHead = pListHead->next;
		}
		return pListHead;
	}
};
