/**
 * Reverses the nodes of a singly linked list from position `left` to `right`.
 * 
 * Example:
 * Input:  1 -> 2 -> 3 -> 4 -> 5, left = 2, right = 4
 * Output: 1 -> 4 -> 3 -> 2 -> 5
 * 
 * Logic: Do the reversal in-place using pointer manipulation.
 */


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // If list is empty or nothing to reverse
        if (!head || left == right) return head;

        // Dummy node helps handle edge cases (like reversing from head)
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // Step 1: Move 'prev' to the node just before 'left'
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // 'curr' is the starting node of the sublist to reverse
        ListNode* curr = prev->next;

        // Step 2: Reverse the sublist between left and right
        // Insert the next node right after 'prev' in each iteration
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;         // node to move
            curr->next = temp->next;             // unlink temp
            temp->next = prev->next;             // insert temp after prev
            prev->next = temp;                   // update prev->next
        }

        // Return the updated head
        return dummy->next;
    }
};
