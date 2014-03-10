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
//�ؼ��㣺 
//Given n will always be valid.
//ɾ���ڵ��Ҫ�ǵ���delete�����ڴ棡����

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
        if(step == n-1)//Ҫɾ������ͷ�ڵ㣡
        {
	    
            head = head->next; //delete list head
            delete p_behind; //��������
            return head;
        }
        while(p_ahead->next != NULL)
        {
            p_ahead = p_ahead->next;
            p_behind = p_behind->next;
        }
        ListNode* tmp = p_behind->next;
        p_behind->next = p_behind->next->next;
        delete tmp; //��������
        return head;
    }
};


void Test()
{
    ListNode a(1);

}
