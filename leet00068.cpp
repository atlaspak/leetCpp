/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        unordered_map<Node*, Node*> listMap;
        
        Node* current = head;
        Node* newNode = new Node(0);
        Node* currentNew = newNode;
        Node* newHead = newNode;
        while(current){
            currentNew->val = current->val;
            currentNew->random = current->random;
            newNode = new Node(0);            
            listMap[current] = currentNew;            
            if(current->next){
                current = current->next;    
                currentNew->next = newNode;
                currentNew = newNode;
            }
            else
                break;            
        }
        
        currentNew = newHead;
        current = head;
        while(currentNew){
            if(currentNew->random != NULL){
                currentNew->random = listMap[current->random];
            }
            currentNew = currentNew->next;
            current = current->next;
        }
        
        return newHead;
        
    }
};
