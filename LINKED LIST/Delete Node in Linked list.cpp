// **simple and easy approach*******
//  head not given only node thatis to be deleted is given

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        while(node!=NULL && node->next!=NULL)
        {
            node->val = node->next->val;
            prev = node ; // assign node val to prev before moving node to the next node
            node = node->next;

        }
        prev->next = NULL;
        delete(node);
    }
};