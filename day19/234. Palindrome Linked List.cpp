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
    ListNode* reverse(ListNode * ptr){
        ListNode * temp = ptr, *curr = NULL;
        while(temp){
            ListNode * front = temp->next;
            temp->next = curr;
            curr = temp;
            temp = front;
        }
        return curr;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * fast = head, * slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * head2 = reverse(slow);

        while( head && head2){
            if(head->val != head2->val) return 0;
            head = head->next;
            head2 = head2->next;
        }
        return 1;
    }
};