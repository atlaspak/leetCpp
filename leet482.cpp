class Solution {
public:
    string licenseKeyFormatting(string s, int k) 
    {
        string retVal = "";
        int i = 0;
        
        if(s.size() == 0)
        {
            return s;
        }
        else if(s[0] == '-')
        {
            for(i = 1;i < s.size(); i++)
            {
                if(s[i] != '-')
                {
                    retVal.push_back(caseControl(s[i]));
                    //retVal.push_back('-');
                }
            }
        }
        else
        {
            for(i=0;i < s.size(); i++)
            {
                if(s[i] == '-')
                {
                    //retVal.push_back('-');
                    break;
                }
                retVal.push_back(caseControl(s[i]));
            }
        }
        
        for(int j=0; i < s.size(); i++)
        {
            if(s[i] == '-')
            {
                continue;
            }
            else
            {                
                if(j % k == 0)
                {
                    retVal.push_back('-');
                }
                retVal.push_back(caseControl(s[i]));
                j++;
            }
        }
        
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
