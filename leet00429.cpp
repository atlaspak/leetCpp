/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        queue<Node*> quedNodes;
        vector<vector<int>> levelOrder;
        int level = 0, nextLevel = 0, i = 0;
        if(!root)
        {
            return levelOrder;
        }
        quedNodes.push(root); ++level;
        vector<int> firstLevel;
        levelOrder.emplace_back(firstLevel);
        while(quedNodes.size() != 0)
        {
            if(level)
            {
                for(int j = 0; quedNodes.front()->children.size() > j; ++j)
                {
                    quedNodes.push(quedNodes.front()->children[j]);
                    nextLevel++;
                }
                levelOrder[i].push_back(quedNodes.front()->val);
                quedNodes.pop();
                level--;
            }
            else
            {
                vector<int> newLevel;
                levelOrder.emplace_back(newLevel);
                i++;
                level = nextLevel;
                nextLevel = 0;
            }
        }
        
        return levelOrder;
    }
};
