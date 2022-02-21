class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int biggest = 0;
        int retVal = 0;
        unordered_map<int, int> counter;
        for(int i = 0; i < nums.size(); i++){
            counter[nums[i]]++;
        }
        
        for(auto i : counter){
            if(i.second > biggest){
                biggest = i.second;
                retVal = i.first;
            }
        }
        
        return retVal;
    }
};
