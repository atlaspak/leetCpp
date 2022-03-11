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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head)
            return head;
        int indice = 0;
        unordered_map<int, ListNode*> nodeMap;
        ListNode* current = head;
        while(current){
            nodeMap[indice] = current;
            indice++;
            current = current->next;
        }
        
        k = k % indice;
        if(k != 0){
            nodeMap[indice-1]->next = head;
        
            head = nodeMap[indice - k];
            nodeMap[indice - k - 1]->next = nullptr;
        }
        
        return head;
    }
};
