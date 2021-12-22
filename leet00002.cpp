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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* current = head;
        int l1Val, l2Val, leftOver = 0, currVal = 0;
        while(true){                
            if(l1){
                l1Val = l1->val;
                l1 = l1->next;
            }
            else
                l1Val = 0;
            
            if(l2){
                l2Val = l2->val;
                l2 = l2->next;
            }
            else
                l2Val = 0;
            
            currVal = l1Val + l2Val + leftOver;
            leftOver = 0;
            if(currVal > 9){
                leftOver = 1;
                currVal -= 10;
            }
            current->val = currVal;
            
            if(!l1 && !l2){
                if(leftOver > 0){
                    current->next = new ListNode(leftOver);
                }
                break;
            }
            current->next = new ListNode();
            current = current->next;
        }
        
        return head;
    }
};
