class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * ptr = head;
        while(ptr && ptr->val != x) ptr = ptr->next;
        
        ListNode * l1 = NULL, * r1 = NULL, *l2 = NULL, * r2 = NULL, * l3 = NULL, * r3 = NULL;

        ListNode * ptr2 = head;
        while(ptr2){
            if(ptr2->val < x){
                ListNode * temp = new ListNode(ptr2->val);
                if(!(l1) && !(r1)) l1 = r1 = temp;
                else{
                    r1->next = temp;
                    r1 = temp;
                }
            }
            ptr2 = ptr2->next;
        }

        ptr2 = head;
        while(ptr2 != ptr){
            if(ptr2->val >= x){
                ListNode * temp = new ListNode(ptr2->val);
                if(!(l2) && !(r2)) l2 = r2 = temp;
                else{
                    r2->next = temp;
                    r2 = temp;
                }
            }
            ptr2 = ptr2->next;
        }

        if (ptr) { // Ensure ptr is not NULL
            ptr2 = ptr->next;
            while(ptr2){
                if(ptr2->val >= x){
                    ListNode * temp = new ListNode(ptr2->val);
                    if(!(l3) && !(r3)) l3 = r3 = temp;
                    else{
                        r3->next = temp;
                        r3 = temp;
                    }
                }
                ptr2 = ptr2->next;
            }
        }

        // Combine the three lists
        ListNode * ans = l1;
        if (l1) {
            while(l1->next){
                l1 = l1->next;
            }
            l1->next = l2;
        } else {
            ans = l2;
        }

        if (l2) {
            while(l2->next){
                l2 = l2->next;
            }
            l2->next = ptr;
        } else if (ptr) {
            if (l1) l1->next = ptr;
            else ans = ptr;
        }

        if (ptr) {
            ptr->next = l3;
        } else {
            if (l2) l2->next = l3;
            else if (l1) l1->next = l3;
            else ans = l3;
        }

        return ans;
    }
};
