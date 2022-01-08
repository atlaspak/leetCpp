/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* pPtr = root;
        TreeNode* qPtr = root;
        
        TreeNode* lowest = root;
        
        while(pPtr && qPtr && pPtr == qPtr){
            lowest = pPtr;
            
            if(p->val > pPtr->val){
                pPtr = pPtr->right;
            }
            else if (p->val < pPtr->val){
                pPtr = pPtr->left;
            }
            
            if(q->val > qPtr->val){
                qPtr = qPtr->right;
            }
            else if(q->val < qPtr->val){
                qPtr = qPtr->left;
            }                
        }
        
        return lowest;
    }
};
