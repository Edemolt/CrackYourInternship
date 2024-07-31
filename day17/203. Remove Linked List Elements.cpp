class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Ensure we handle cases where the head itself has the value to remove
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* temp = head;

        // Now, remove nodes beyond the head
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->val == val) {
                ListNode* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};
