class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        if(position.size() == 0)
        {
            return 0;
        }
        std::vector<std::pair<int, int>> posSpeedVec;
        int retVal = 0;
        posSpeedVec.reserve(position.size());
        
        for(int i = 0; i < position.size(); i++)
        {
            posSpeedVec.push_back({target - position[i], speed[i]});
        }
        
        std::sort(posSpeedVec.begin(), posSpeedVec.end());
        
        float firstT = 0, secondT;
        for(auto node : posSpeedVec)
        {
            secondT = (float)node.first / (float)node.second;
            
            if(firstT >= secondT)
            {
                continue;
            }
            else
            {
                retVal++;
                firstT = secondT;
            }
        }
        return retVal;
    }
};
