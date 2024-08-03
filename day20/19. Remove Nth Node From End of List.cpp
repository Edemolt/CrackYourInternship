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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * ptr = head;
        int sz = 0;

        while(ptr){
            ptr = ptr->next;
            sz += 1;
        }

        int remove = sz - n;
        if(remove == 0){
            head = head->next;
            return head;
        }
        ptr = head;
        remove-= 1;
        while(remove--){
            ptr = ptr->next;
        }

        if(ptr->next->next == NULL) ptr->next = NULL;
        else ptr->next = ptr->next->next;

        return head;
    }
};