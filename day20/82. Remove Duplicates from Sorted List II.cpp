class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);  // Dummy node to simplify handling of head
        ListNode* tail = &dummy;
        ListNode* current = head;

        while (current) {
            if (!current->next || current->val != current->next->val) {
                tail->next = current;
                tail = current;
            }
            // Move to the next distinct node
            while (current->next && current->val == current->next->val) {
                current = current->next;
            }
            current = current->next;
        }
        tail->next = nullptr;  // Terminate the list

        return dummy.next;
    }
};
