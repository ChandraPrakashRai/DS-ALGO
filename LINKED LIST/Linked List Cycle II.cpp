// ++++++++ LEETCODE 142 ++++

// using slow and fast pointer first  we detect the cycle 
// then we make a pointer P  which tells about the starting node of the cycle of the linked list

// P and slow pointer moves and when P and slow meet to each other that node is the starting node of the cycle of linked list


        //  ----------****_____*******---------

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
    ListNode *detectCycle(ListNode *head) {

        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast)
            break;

        }
        if(slow!=fast) return NULL;

        ListNode* p = head;
        while(p!=slow)
        {
            p = p->next;
            slow= slow->next;
        }

        return p;


    }
};