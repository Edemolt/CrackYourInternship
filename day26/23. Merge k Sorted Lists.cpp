class Solution {
public:
    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->val <= right->val) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    // Function to find the middle of the linked list
    ListNode* getMiddle(ListNode* head) {
        if (!head) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to sort the linked list using merge sort
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* middle = getMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }

    // Function to merge k sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Flatten all the linked lists into one list
        ListNode* flattenedList = nullptr;
        ListNode* tail = nullptr;

        for (ListNode* list : lists) {
            while (list) {
                if (!flattenedList) {
                    flattenedList = list;
                    tail = list;
                } else {
                    tail->next = list;
                    tail = tail->next;
                }
                list = list->next;
            }
        }

        // Sort the flattened list using merge sort
        return mergeSort(flattenedList);
    }
};
