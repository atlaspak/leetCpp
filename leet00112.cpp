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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root)
            return calculate(root, targetSum, 0);
        return false;
    }
    
    bool calculate(TreeNode* root, int targetSum, int totalSoFar)
    {
        if(!root->right && !root->left)
        {
            return  targetSum == totalSoFar + root->val;
        }
        
        return (root->right && calculate(root->right, targetSum, totalSoFar + root->val)) ||
            (root->left && calculate(root->left, targetSum, totalSoFar + root->val));
    }
};
