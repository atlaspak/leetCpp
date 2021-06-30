/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        return isEqual(root->left, root->right);
    }
    
    bool isEqual(TreeNode* node1, TreeNode* node2)
    {
        if(!node1 && !node2)
        {
            return true;
        }
        else if(node1 && node2)
        {
            return (node1->val == node2->val) &&
                    isEqual(node1->left, node2->right) &&
                    isEqual(node1->right, node2->left);
        }
        else
        {
            return false;
        }
    }
};
