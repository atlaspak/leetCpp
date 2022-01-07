/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root){
            Node* current = root;
            Node* prevLink = nullptr;
            Node* nextRoot = nullptr;
            
            while(current){
                if(current->left){
                    if(nextRoot == nullptr)
                        nextRoot = current->left;
                    if(prevLink){
                        prevLink->next = current->left;
                    }
                    prevLink = current->left;
                }
                if(current->right){                    
                    if(nextRoot == nullptr)
                        nextRoot = current->right;
                    if(prevLink){
                        prevLink->next = current->right;
                    }
                    prevLink = current->right;   
                }
                current = current->next;                
            }
            connect(nextRoot);
        }
        
        return root;
    }
};
