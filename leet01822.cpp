class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int retVal = 1;
        for(int num : nums)
        {
            if(num == 0)
            {
                return 0;
            }
            
            if(num < 0)
            {
                retVal *= -1;
            }
        }
        return retVal;
    }
};
