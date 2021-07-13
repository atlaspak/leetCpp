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
    vector<int> getLonelyNodes(TreeNode* root) 
    {
        fillLonelyNodes(root);
        return lonelyNodes;
    }
    
    void fillLonelyNodes(TreeNode* root)
    {
        if(root)
        {
            if(root->left)
            {
                fillLonelyNodes(root->left);
                if(!root->right)
                {
                    lonelyNodes.emplace_back(root->left->val);
                }
            }
            if(root->right)
            {
                fillLonelyNodes(root->right);
                if(!root->left)
                {
                    lonelyNodes.emplace_back(root->right->val);
                }
            }
        }
        return;
    }
    
private:
    vector<int> lonelyNodes;
};
