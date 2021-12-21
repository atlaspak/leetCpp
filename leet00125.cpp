class Solution {
public:
    bool isPalindrome(string s) 
    {
        auto isInside = [](char controlVal){
            if(controlVal >= 'a' && controlVal <= 'z')
                return true;
            return false;
        };
        
        for(int i = 0, j = s.size()-1, k = 0; k < s.size() / 2; ++i, --j, ++k) 
        {
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            
            while(i < s.size() && !isInside(s[i])) ++i;
            while(j < s.size() && !isInside(s[j])) --j;
            
            if(i < s.size() && j < s.size() && s[i] != s[j])
                return false;
        }
        
        return true;
    }
};
