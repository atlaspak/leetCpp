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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {        
        ListNode* current,* head;
        
        if(!list1)
            return list2;
        else if(!list2)
            return list1;
        
        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next;
            current = head;
        }
        else if(list1->val > list2->val){
            head = list2;
            list2 = list2->next;
            current = head;
        }
        else{
            head = list1;
            list1 = list1->next;
            head->next = list2;
            list2 = list2->next;            
            current = head->next;
        }
        
        
        while(true){
            if(list1 && list2)
            {
                if(list1->val < list2->val){
                    current->next = list1;
                    list1 = list1->next;
                }
                else if(list1->val > list2->val){
                    current->next = list2;
                    list2 = list2->next;
                }
                else{
                    current->next = list1;
                    list1 = list1->next;
                    current = current->next;
                    current->next = list2;
                    list2 = list2->next;
                }
                current = current->next;
            }
            else if(list1)
            {
                current->next = list1;
                break;
            }
            else if(list2)
            {
                current->next = list2;
                break;
            }
            else
            {
                break;
            }
        }
        
        return head;
    }
};
