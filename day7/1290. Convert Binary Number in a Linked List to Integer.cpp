#include <bitset>
#include <iostream>

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        // First, find the length of the linked list
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        
        // Create a bitset with the appropriate size
        std::bitset<32> bitset; // 32 bits is enough to cover typical integer ranges
        
        // Fill the bitset
        int i = length - 1;
        while (head) {
            if (head->val == 1) {
                bitset[i] = 1;
            }
            i--;
            head = head->next;
        }

        // Convert bitset to integer
        return static_cast<int>(bitset.to_ulong());
    }
};
