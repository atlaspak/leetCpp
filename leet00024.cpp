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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* next = second->next;
        head = second;
        
        while(second){
            ListNode* prev = first;
            second->next = first;
            first->next = next;
            
            
            first = next;
            if(next && next->next)
                second = next->next;
            else
                break;
            if(next->next->next)
                next = next->next->next;
            else
                next = nullptr;
            prev->next = second;
        }
        
        return head;
    }
};
