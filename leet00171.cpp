class Solution {
public:
    int titleToNumber(string columnTitle) {
        int keyValue = 'A' - 1;
        long long coef = 1;
        int count = 0;
        
        for(int i = columnTitle.size()-1; i >= 0; i--){
            count += coef * (columnTitle[i] - keyValue);
            coef *= 26;
        }
        
        return count;
    }
};
