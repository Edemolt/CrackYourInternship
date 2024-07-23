class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;  // Check if the list is empty

        ListNode* current = head;  // Use a current pointer to traverse the list

        while (current && current->next) {  // Ensure current and current->next are not null
            if (current->val == current->next->val) {
                ListNode* next_next = current->next->next;  // Save the next unique node
                delete current->next;  // Optional: Free the memory of the duplicate node
                current->next = next_next;  // Skip the duplicate node
            } else {
                current = current->next;  // Move to the next node
            }
        }

        return head;  // Return the head of the modified list
    }
};
