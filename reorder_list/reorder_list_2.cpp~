/*
思路：直接用vector操作指针。
题目的要求的是： You must do this in-place without altering the nodes' values.
这里in-place 的意思仅仅是不要改变节点的值？
*/

#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL)
            return;
        vector<ListNode*> nodes;
        ListNode* p_node = head;
        while(p_node != NULL)
        {
            nodes.push_back(p_node);
            p_node = p_node->next;
        }
        int low = 0;
        int high = nodes.size() - 1;
        while(low + 1 < high)
        {
            nodes[high]->next = nodes[low]->next;
            nodes[low]->next = nodes[high];
            low++;
            high--;
        }
        if(low == high)
        {
            nodes[low]->next = NULL;
        }
        else
        {
            nodes[high]->next = NULL;
        }
        
    }
};

void Print(ListNode* p_node)
{
    while(p_node != NULL)
    {
        cout << p_node->val << " ";
        p_node = p_node->next;
    }
    cout << endl;
}

void Test()
{
   ListNode n1(1);
   ListNode n2(2);
   ListNode n3(3);
   n1.next = &n2;
   n2.next = &n3;
   Solution s;
   s.reorderList(&n1);
   Print(&n1);
}

int main()
{
    Test();
    return 0;
}
