/*
 * 思路：先用快慢指针的方法判断有无环。如果快慢指针相遇，则说明存在环。
 * 接下来就是求两链表的首个公共节点。以原链表的头节点为头节点的链表和
 * 以相遇点的下一节点为头节点的链表。
 *
 */

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
    ListNode *detectCycle(ListNode *head) {
       if(head == NULL) 
       {
           return NULL;
       }
       ListNode* one = head;
       ListNode* two = head;
       two = two->next;
       while(two != NULL)
       {
            if(one == two)
            {
                //求两链表的首个公共节点。
            	  int len1 = 0;
                ListNode* p1 = head;
                while(p1 != one)
                {
                    ++len1;
                    p1 = p1->next;
                }
                int len2 = 0;
                ListNode* p2 = one->next;
                while(p2 != one)
                {
                    ++len2;
                    p2 = p2->next;
                }
                p1 = head;
                p2 = one->next;
                if(len1 > len2)
                {
                    int step = len1-len2;
                    while(step > 0)
                    {
                        p1  = p1->next;
                        --step;
                    }
                }
                else if(len1 < len2)
                {
                    int step = len2-len1;
                    while(step > 0)
                    {
                        p2 = p2->next;
                        --step;
                    }
                }
                while(p1!= one && p2!= one)
                {
                    if(p1 == p2)
                    {
                        return p1;
                    }
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return one;//如果没有找到，则说明相遇点是首个公共节点！
            }
            
            two = two->next;
            if(two == NULL)
            {
                return NULL;
            }
            two = two->next;
            one = one->next;
       }
       return NULL;
    }

};

void printList(ListNode *head)
{
	while(head != NULL)
	{
		cout <<head->val<<",";
		head = head->next;
	}
}

void test1()
{
	ListNode n1(-1);
	ListNode n2(-7);
	ListNode n3(7);
	ListNode n4(-4);
	ListNode n5(19);
	ListNode n6(6);
	ListNode n7(-9);
	ListNode n8(-5);
	ListNode n9(-2);
	ListNode n10(-5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &n10;
	n10.next = &n7;
	Solution s;
//	printList(&n1);
	ListNode* pNode = s.detectCycle(&n1);
	cout << pNode->val << endl << endl;
//	printList(&n1);
	//cout << s.hasCycle(&n1) << endl;
}



int main()
{
	test1();
	return 0;
}

