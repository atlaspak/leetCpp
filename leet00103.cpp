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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> retVal;
        list<TreeNode*> jobQueZig;
        list<TreeNode*> jobQueZag;
        bool flipFlop = true;
        if(root){
            jobQueZig.push_back(root);            
        }
        
        vector<int> tempVec;
        while(!jobQueZig.empty() || !jobQueZag.empty()){

            while(!jobQueZig.empty()){
                tempVec.push_back(jobQueZig.front()->val);
                              
                if(jobQueZig.front()->left){
                    jobQueZag.push_front(jobQueZig.front()->left);
                }
                if(jobQueZig.front()->right){
                    jobQueZag.push_front(jobQueZig.front()->right);
                }
                jobQueZig.pop_front();
            }
            if(tempVec.size() > 0){
                retVal.push_back(tempVec);    
                tempVec.clear();
            }            
            
            while(!jobQueZag.empty()){
                tempVec.push_back(jobQueZag.front()->val);
                
                if(jobQueZag.front()->right){
                    jobQueZig.push_front(jobQueZag.front()->right);
                }
                if(jobQueZag.front()->left){
                    jobQueZig.push_front(jobQueZag.front()->left);
                }
                jobQueZag.pop_front();
            }
            
            if(tempVec.size() > 0){
                retVal.push_back(tempVec);    
                tempVec.clear();
            }   
        }
        
        return retVal;
            
    }
};
