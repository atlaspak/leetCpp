class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> retVal;
        
        for(int i = 1; i <= n/2; i++){
            retVal.push_back(i * -1);
            retVal.push_back(i);
        }
        
        if(n % 2 == 1)
            retVal.push_back(0);
        
        return retVal;
    }
};
