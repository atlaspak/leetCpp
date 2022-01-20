class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0)
            return "";
        
        string retVal = strs[0];
        int lastIndice = retVal.size();
        
        for(int i = 1; i < strs.size(); i++){
            for(int x = 0; x < lastIndice; x++){
                if(strs[i][x] != retVal[x] || x == strs[i].size()){
                    lastIndice = x;
                    break;
                }
            }
        }
        
        return retVal.substr(0, lastIndice);        
    }
};
