//2. Add Two Numbers
//给定两个使用链表倒序储存的大数
//要求用链表输出倒序的两数和
//注意处理进位状况与两链表不等长的状况

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode *res = NULL;
		ListNode *prev = NULL;

		int carry = 0;
		while (l1 || l2) 
		{
			int v1 = 0;
			int v2 = 0;
			if (l1)
				v1 = l1->val;
			if (l2)
				v2 = l2->val;

			int tmp = v1 + v2 + carry;
			carry = tmp / 10;
			int val = tmp % 10;
			ListNode* cur = new ListNode(val);

			if (!res) 
				res = cur;
			if (prev) 
				prev->next = cur;
			prev = cur;

			if (l1)
				l1 = l1->next;
			else 
				l1 = NULL;

			if (l2)
				l2 = l2->next;
			else
				l2 = NULL;
		}
		if (carry > 0) {
			ListNode* l = new ListNode(carry);
			prev->next = l;
		}
		return res;
	}

};