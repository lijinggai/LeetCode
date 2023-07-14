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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr)
			return nullptr;
		int num1 = 0, num2 = 0;
		//算出两个链表的长度
		for (ListNode* cur = pHead1; cur; num1++)
		{
			cur = cur->next;
		}
		for (ListNode* cur = pHead2; cur; num2++)
		{
			cur = cur->next;
		}
		//长的链表先走超出的部分
		int t = abs(num1 - num2);
		if (num1 > num2)
		{
			while (t--)
				pHead1 = pHead1->next;
		}
		else {
			while (t--)
				pHead2 = pHead2->next;
		}
		//长度相同，同时走比较；
		while (pHead1)
		{
			if (pHead1 == pHead2)
				return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return nullptr;
	}
};