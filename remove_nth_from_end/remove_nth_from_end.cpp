#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//关键点： 
//Given n will always be valid.
//删除节点后，要记得用delete回收内存！！！

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
            return head;
        ListNode* p_ahead = head;
        ListNode* p_behind = head;
        int step = 0;
        while(step < n && p_ahead->next != NULL)
        {
            p_ahead = p_ahead->next;
            step++;
        }
        if(step == n-1)//要删除的是头节点！
        {
	    
            head = head->next; //delete list head
            delete p_behind; //回收垃圾
            return head;
        }
        while(p_ahead->next != NULL)
        {
            p_ahead = p_ahead->next;
            p_behind = p_behind->next;
        }
        ListNode* tmp = p_behind->next;
        p_behind->next = p_behind->next->next;
        delete tmp; //回收垃圾
        return head;
    }
};


void Test()
{
    ListNode a(1);

}
