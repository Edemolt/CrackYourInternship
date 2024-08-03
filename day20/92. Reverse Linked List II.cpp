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
    void Reverse(ListNode* start, ListNode* end) {
        ListNode* prev = NULL;
        ListNode* curr = start;
        ListNode* endNext = end->next; // Save the node after 'end'
        
        while (curr != endNext) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL || left == right) {
            return head;
        }

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev1 = dummy;
        
        // Move prev1 to the node before the 'left' position
        for (int i = 1; i < left; i++) {
            prev1 = prev1->next;
        }

        // 'start' points to the 'left' position node
        ListNode* start = prev1->next;
        
        // Move 'end' to the 'right' position node
        ListNode* end = start;
        for (int i = left; i < right; i++) {
            end = end->next;
        }
        
        ListNode* temp1 = end->next;
        
        // Reverse the segment between 'start' and 'end'
        Reverse(start, end);

        // Connect the reversed segment back to the list
        prev1->next = end;
        start->next = temp1;

        return dummy->next;
    }
};