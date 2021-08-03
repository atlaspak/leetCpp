class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> pairs;
        for(int i = 0; i<nums.size(); i++)
        {
            std::vector<int> pair;
            
            if(pairs.size() != 0)
            {
                for(int j = 0; j<pairs.size(); j++)
                {
                    if(nums.at(pairs.at(j).at(0)) + nums.at(i) == target)
                    {
                        pairs.at(j).push_back(i);
                        return pairs.at(j);
                    }
                }
            }
            pair.push_back(i);
            pairs.push_back(pair);
        }
        std::vector<int> pair(2, 0);
        return pair;
    }
};
