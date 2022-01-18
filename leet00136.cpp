class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> singleSet;
        
        for(int i = 0; i < nums.size(); i++)
        {
            auto key = singleSet.find(nums[i]);
            
            if(key != singleSet.end()){
                singleSet.erase(key);
            }
            else{
                singleSet.insert(nums[i]);
            }
        }
        
        return *(singleSet.begin());
    }
};
