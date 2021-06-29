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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        TreeNode* current = root;
        queue<TreeNode*>* jobQue = new queue<TreeNode*>;
        queue<TreeNode*>* nextLevel = new queue<TreeNode*>;
        queue<TreeNode*>* temp;
        vector<vector<int>> retVal;
        vector<int> currentVec;
        
        if(current)
            jobQue->push(current);
        
        
        while(!jobQue->empty())
        {
            currentVec.push_back(jobQue->front()->val);
            if(jobQue->front()->left)
            {
                nextLevel->push(jobQue->front()->left);
            }
            if(jobQue->front()->right)
            {
                nextLevel->push(jobQue->front()->right);
            }
            jobQue->pop();
            
            if(jobQue->empty())
            {
                retVal.emplace_back(currentVec);
                currentVec.clear();
                temp = jobQue;
                jobQue = nextLevel;
                nextLevel = temp;                
            }
        }
        
        delete jobQue;
        delete nextLevel;
        
        return retVal;
    }
};
