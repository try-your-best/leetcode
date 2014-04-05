#include<iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dump(-1);
        ListNode *p_node  = &dump;
        int carry_over = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int val1 = l1 == NULL ? 0 : l1->val;
            int val2 = l2 == NULL ? 0 : l2->val; 
            int sum = val1 + val2 + carry_over;
            p_node->next = new ListNode(sum % 10);
            carry_over = sum / 10;
            p_node = p_node->next;
            if(l1 != NULL)//注意判断l1是否为NULL
                l1 = l1->next;
            if(l2 != NULL)//注意判断l2是否为NULL
                l2 = l2->next;
        }
        if(carry_over == 1)
        {
            p_node->next = new ListNode(1);//注意{5}和{5}为{0,1}的情况！
        }
        return dump.next;
    }
};

void Test()
{
    ListNode a1(1);
    ListNode a2(8);
    a1.next = &a2;
    ListNode b1(0);
    Solution s;
    s.addTwoNumbers(&a1, &b1);
}

int main()
{
    Test();
    return 0;
}
