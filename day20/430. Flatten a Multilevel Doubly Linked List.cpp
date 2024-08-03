class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* ptr = head;
        while (ptr) {
            if (ptr->child) {
                Node* child = ptr->child;
                Node* next = ptr->next;

                // Find the last node of the child's list
                Node* last = child;
                while (last->next) {
                    last = last->next;
                }

                // Attach the child to the current node
                ptr->next = child;
                child->prev = ptr;
                
                // Attach the last node of the child to the next node
                if (next) {
                    last->next = next;
                    next->prev = last;
                }

                // Set child to nullptr as we have flattened this level
                ptr->child = nullptr;
            }
            ptr = ptr->next;
        }
        return head;
    }
};
