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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> jobStack;
        vector<int> retVal;
        TreeNode* current = root, *prev;
        jobStack.push(current);
        
        while(current)
        {
            if(!current->right && !current->left)
            {
                retVal.push_back(current->val);
                jobStack.pop();
            }
            else
            {                
                if(current->right)
                {
                    jobStack.push(current->right);
                    current->right = nullptr;
                }
                if(current->left)
                {                
                    jobStack.push(current->left);
                    current->left = nullptr;
                }
            }
            if(!jobStack.empty())
            {                    
                current = jobStack.top();
            } 
            else
                break;
        }
        
        return retVal;
    }
};
