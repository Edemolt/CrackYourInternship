/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void swap(ListNode* a, ListNode* b) {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
    
    ListNode* zigzagRearrange(ListNode* head) {
        if (!head || !head->next) return head; // If list is empty or has one element

        ListNode* curr = head;
        bool isLess = true; // Start with "<" comparison
        
        while (curr->next) {
            if (isLess) {
                // If the current value is not less than the next value, swap them
                if (curr->val > curr->next->val) {
                    swap(curr, curr->next);
                }
            } else {
                // If the current value is not greater than the next value, swap them
                if (curr->val < curr->next->val) {
                    swap(curr, curr->next);
                }
            }
            curr = curr->next;
            isLess = !isLess; // Toggle the flag
        }
        return head;
    }
};
