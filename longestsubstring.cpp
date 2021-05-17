class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int longest = s.size() >=  0 ? 1 : 0;
        int current = longest;
        
        for(int i = 0; s.size(); ++i)
        {
            if(s[i] && s[i+1])
            {
                if(s[i] != s[i+1])
                {
                    ++current;                    
                    if(current > longest)
                    {
                        current = longest;
                    }
                }
                else
                {
                    current = 1;
                }
            }
        }
        
        return longest;
    }
};
