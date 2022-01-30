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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        int nodeCount = 0;
        unordered_map<int, ListNode*> addressMap;
        while(current){
            addressMap.insert({nodeCount,current});
            nodeCount++;            
            current = current->next;
        }
        if(n == 1 && nodeCount == 1)
            return nullptr;
        else if(n == nodeCount)
            head = addressMap[1];
        else if(n != 0){
            addressMap[nodeCount-n-1]->next = addressMap[nodeCount-n+1];
        }
        else
            addressMap[nodeCount-n-1]->next = nullptr;
        
        return head;        
        
    }
};
