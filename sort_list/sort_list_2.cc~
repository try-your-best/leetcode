//单链表快排，交换节点而不是交换节点的值。
//在用分界点区分链表时，要利用链表的灵活性找出左右链表。
//这个程序无法跑过测试，会超时，因为这个算法没有处理相等值和选择恰当分界点的问题。


#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode* pHead, ListNode** pLeft, ListNode** pRight)
    {
        int key = pHead->val;
        ListNode* pNode = pHead->next;
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;
        while(pNode != NULL) //关键点，灵活的找出左右链表，如果是基于单向遍历，在交换节点处理会很麻烦！
        {
            if(pNode->val <= key)
            {
                if(*pLeft == NULL)
                {
                    *pLeft = pNode;
                     p1 = pNode;
                }
                else
                {
                    p1->next = pNode;
                    p1 = p1->next;
                }
            }
            else
            {
                if(*pRight == NULL)
                {
                    *pRight = pNode;
                    p2 = pNode;
                }
                else
                {
                    p2->next = pNode;
                    p2 = p2->next;
                }

            }
            pNode = pNode->next;
        }
        if(p1)
        {
            p1->next = NULL;
        }
        if(p2)
        {
            p2->next = NULL;
        }
        return pHead;
    }

    void jointList(ListNode* pKey,ListNode** pLeft, ListNode* pLeftTail, ListNode* pRight)
    {
        if(*pLeft == NULL)
        {
            *pLeft = pKey;
        }
        else
        {
            pLeftTail->next = pKey;
        }
        pKey->next = pRight;
    }

    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* pLeft = NULL;
        ListNode* pRight = NULL;
        ListNode* key = partition(head, &pLeft, &pRight);
        pLeft = sortList(pLeft);
        pRight = sortList(pRight);
        ListNode* pLeftTail = pLeft;
        if(pLeftTail != NULL) // 找到左链表的结尾节点！
        {
            while(pLeftTail->next != NULL)
            {
                pLeftTail = pLeftTail->next;
            }
        }
        jointList(key, &pLeft, pLeftTail, pRight);
        return pLeft;
    }
};

void printList(ListNode *head)
{
	while(head != NULL)
	{
		cout << head->val<<",";
		head = head->next;
	}
	cout << endl;
}

void test1()
{
	ListNode* p1 = new ListNode(2);
  p1->next = new ListNode(1);
	Solution s;
	ListNode* p = s.sortList(p1);
	printList(p);
}

int main()
{
	test1();
}
