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
    ListNode *getmid(ListNode * ptr){
        if(!ptr) return ptr;
        ListNode * slow = ptr;
        ListNode * fast = ptr;
        ListNode * prev = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev) prev->next = NULL;
        return slow;
    }

    ListNode * merge(ListNode *l, ListNode *r){
        if(!(l)) return r;
        if(!(r)) return l;

        ListNode * dummy = new ListNode(0);
        ListNode * curr = dummy;

        while(l && r){
            if( l->val <= r->val){
                curr->next = l;
                l = l->next;
            }else{
                curr->next = r;
                r = r->next;
            }

            curr = curr->next;
        }

        if(l) curr->next = l;
        if(r) curr->next = r;

        ListNode * sorted = dummy->next;
        return sorted;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode * mid = getmid(head);
        ListNode * left = head;
        ListNode * right = mid;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};