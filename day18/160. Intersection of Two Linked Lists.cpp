/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getlen(ListNode * head){
        int len = 0;
        while(head){
            len += 1;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getlen(headA);
        int len2 = getlen(headB);

        if(len1 < len2){
            swap(headA, headB);
            swap(len1, len2);
        }

        int len = len1 - len2;
        while(len--){
            headA = headA->next;
        }

        int k = 0;
        while(k < len2){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
            k += 1;
        }
        return nullptr;
    }
};