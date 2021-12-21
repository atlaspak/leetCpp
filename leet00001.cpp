class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> keyIndexMap;
        int searchFor = 0;
        vector<int> result(2);
        for(int i = 0; i < nums.size(); ++i)
        {
            keyIndexMap.insert({nums[i], i});
        }
        
        for(int i = 0; i <nums.size(); ++i)
        {
            searchFor = target - nums[i];
            auto val = keyIndexMap.find(searchFor);
            if(val != keyIndexMap.end() && val->second != i)
            {
                result[0] = i;
                result[1] = val->second;
                break;
            }                
        }
        
        return result;        
    }
};
