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
    pair<ListNode *, ListNode *> reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        // Reverse the segment between head and tail
        while (curr != tail) {
            next = curr->next; // Save the next node
            curr->next = prev; // Reverse the link
            prev = curr; // Move prev to this node
            curr = next; // Move to the next node
        }

        // After the loop, curr is at tail, which should be the new head
        // Set the tail's next to the reversed part
        tail->next = prev;

        // Return the new head (prev) and the original head (which is now the end of reversed segment)
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * pre = dummy;
        ListNode * curr = dummy;
        while(head){
            ListNode * tail = pre;

            for(int i = 0; i < k; i++){
                tail = tail->next;
                if(!(tail)) return dummy->next;
            }

            ListNode * nexthead = tail->next;
            auto rev = reverse(head, tail);
            pre->next = rev.first;
            rev.second->next = nexthead;

            pre = rev.second;
            head = nexthead;
        }

        return dummy->next;

    }
}