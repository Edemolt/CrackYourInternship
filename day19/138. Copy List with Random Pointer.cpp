/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * l = NULL, *r = NULL;
        map<Node *, Node *> mp;
        while(head){
            Node * temp = new Node(head->val);
            temp->next = head->next;
            temp->random = head->random;
            mp[head] = temp;
            if(!(l) && !(r)){
                l = r = temp;
            }else{
                r->next = temp;
                r = temp;
            }
            head = head->next;
        }
        Node * ptr = l;
        while(ptr){
            ptr->random = mp[ptr->random];
            ptr = ptr->next;
        }
        return l;
    }
};