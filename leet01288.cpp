class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int retVal = 0;
        
        for(int i = 0; i < intervals.size(); i++){            
            if(intervals[i][0] == -1)
                continue;
            for(int j = 0; j < intervals.size(); j++){
                if(i==j||intervals[j][0]==-1) 
                    continue;
                if(intervals[i][0] <= intervals[j][0] &&
                   intervals[i][1] >= intervals[j][1]){
                    retVal++;
                    intervals[j][0] = -1;
                }                
            }
        }
        return intervals.size() - retVal;
    }
};
