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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;

        while(l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2 = l2->next;
        }

        ListNode * ptr = NULL;
        int carry = 0;

        while(!(st1.empty()) || !(st2.empty()) || carry != 0){
            int sum = carry;
            if(!(st1.empty())){
                sum += st1.top();
                st1.pop();
            }
            if(!(st2.empty())){
                sum += st2.top();
                st2.pop();
            }

            int digit = sum % 10;
            carry = sum/10;

            ListNode * temp = new ListNode(digit);
            temp->next = ptr;
            ptr = temp;
        }

        return ptr;
    }
};