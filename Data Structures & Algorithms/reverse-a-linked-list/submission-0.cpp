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

//use recursion
//store head.next in temp pointer
//reverse list starting from head.next
//temp stores the returned new head 
//not attach head to head.next (which is now the last pointer)
//make head.next = null

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(!head) return nullptr;

        ListNode* temp = head;

        if(head->next)
        {
            temp = reverseList(head->next);
            head->next->next = head;
        }

        
        head->next = nullptr;

        return temp;

        
    }
};
