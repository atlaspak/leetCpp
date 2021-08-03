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
    int goodNodes(TreeNode* root)
    {
        int maxSoFar = root->val;
        int totalGood = 1;
        totalGood += amIgood(root->left, maxSoFar);
        totalGood += amIgood(root->right, maxSoFar);
        return totalGood;
    }
    
    int amIgood(TreeNode* root, int maxSoFar)
    {
        int i = 0;
        if(root)
        {
            if(root->val >= maxSoFar)
            {
                maxSoFar = root->val;
                i = 1;
            }
            return amIgood(root->left, maxSoFar) + amIgood(root->right, maxSoFar) + i;
        }
        return 0;
    }
};
