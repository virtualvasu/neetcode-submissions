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


//fast, slow pointer
//fast moves 2, slow moves 1
//till both not null
//at any point if they meet, cycle exists
//else not 

class Solution {
public:
    bool hasCycle(ListNode* head) {

        if(!head) return false;
        if(!head->next) return false;

        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next)
        {
            if(slow == fast) return true;

            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
        
    }
};
