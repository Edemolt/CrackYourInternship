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
    ListNode* middleNode(ListNode* head) {
        // int n = 0;
        // ListNode * temp = head;
        // while(temp){
        //     temp= temp->next;
        //     n += 1;
        // }
        // n = n/2;
        // temp = head;
        // while(n){
        //     temp = temp->next;
        //     n -= 1;
        // }
        // return temp;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};