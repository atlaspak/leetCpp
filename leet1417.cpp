#define  I_STATE        1
#define  J_STATE        2
#define MATCH_STATE     3

class Solution {
public:
    string reformat(string s) 
    {
        string retVal = "";
        int i = 0, j = 1;
        int state = I_STATE;
        char temp;

        if(!isValid(s))
        {
            return retVal;
        }

        while(i < s.size() && j < s.size())
        {
            if(state == I_STATE)
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                {
                    state = J_STATE;
                }
                else
                {
                    i++;
                }
            }
            else if(state == J_STATE)
            {
                if(s[j] >= '0' && s[j] <= '9')
                {
                    state = MATCH_STATE;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                temp = s[i+1];
                s[i+1] = s[j];
                s[j] = temp;
                state = I_STATE;
                i++;
                j++;
            }

        }
        return s;
    }
    
    bool isValid(string& s)
    {
        int cntLetters = 0, cntDigits = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                cntLetters++;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                cntDigits++;
            }
        }

        if(abs(cntLetters - cntDigits) > 1)
        {
            return false;
        }
        return true;
    }
};
