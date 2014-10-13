/*
思路：这道题 rotate to right 包含循环旋转的意思！
首先从head开始跑，直到最后一个节点，这时可以得出链表长度len。然后将尾指针指向头指针，
将整个圈连起来，接着往前跑len – k%len（这时pNode指向尾节点，如果从头节点开始跑，则前进len – k%len-1步），从这里断开，就是要求的结果了。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head) return head;
        ListNode *pNode = head;
        int len = 1;
        while(pNode->next != NULL)
        {
            len++;
            pNode = pNode->next;
        }
        pNode->next = head;
        //pNode = head;
        int step = len - (k%len);
        for(int i = 0; i < step; ++i)
        {
            pNode = pNode->next;
        }
        ListNode *pHead = pNode->next;
        pNode->next = NULL;
        return pHead;
    }
};
/*
下面是错误的思路，以为就是把倒数的k个点移到前头来！
*/

/*
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(k == 0) return head;
        ListNode dummpy(0);
        dummpy.next = head;
        ListNode* p1 = &dummpy;
        ListNode* p2 = &dummpy;
        for(int i = 0; i < k; ++i)
        {
            if(p2->next == NULL)
            {
                return head;
            }
            p2 = p2->next;
        }
        while(p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* pHead = p1->next;
        p1->next = NULL;
        if(p2 != head && pHead != head)
        {
            p2->next = head;
        }
        return pHead;
    }
};
*/
