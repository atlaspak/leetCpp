class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> f(cost.size());
        f[0] = cost[0];
        f[1] = cost[1];
        
        if(cost.size() > 1)
        {        
            for(int i = 2; i < cost.size(); i++)
            {
                f[i] = cost[i] + min(f[i-1] , f[i-2]);
            }
        }
        
    
        return min (f[cost.size()-1], f[cost.size()-2]);
    }
};
