class Solution {
public:
    string licenseKeyFormatting(string s, int k) 
    {
        string retVal = "";
        
        if(s.size() == 0)
        {
            return s;
        }
        
        for(int i = s.size()-1, j = 0; i >= 0; --i)
        {
            if(s[i] == '-')
            {
                continue;
            }
            else
            {
                if(j && j % k == 0)
                {
                    retVal.push_back('-');
                }
                retVal.push_back(caseControl(s[i]));                
                ++j;
            }
        }
        
        reverse(retVal.begin(), retVal.end());
        
        return retVal;
    }
    
    constexpr char upperDiff()
    {
        return 'A' - 'a';
    }
    
    char caseControl(char charOnTest)
    {
        if(charOnTest >= 'a' && charOnTest <= 'z')
        {
            return charOnTest + upperDiff();
        }
        return charOnTest;
    }
};
