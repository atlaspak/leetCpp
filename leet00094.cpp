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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> jobStack;
        vector<int> retVal;
        TreeNode* current = root, *prev;
        
        while(current)
        {              
            if(current->right)
            {
                jobStack.push(current->right);
                current->right = nullptr;
            }
            jobStack.push(current);
            
            prev = current;
            current = current->left;
            prev->left = nullptr;
            if(!current && !jobStack.empty())
            {
                retVal.push_back(jobStack.top()->val);
                jobStack.pop();
                if(jobStack.empty())
                {
                    break;  
                }                    
                current = jobStack.top();
                jobStack.pop(); 
            }
        }
        return retVal;
    }
};
