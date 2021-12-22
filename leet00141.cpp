/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visitList;
        while(head){
            auto key = visitList.find(head);
            if(key == visitList.end()){
                visitList.insert(head);
            }
            else{
                return true;
            }
            
            head = head->next;
        }
        return false;
    }
};
