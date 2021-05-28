class LetterMap
{
private:
    set<int> letters[(int)('z' - 'a') + 1];
    
public:        
    set<int> &operator [](char index)
    {
        return letters[(int)(index - 'a')];
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
        int retVal = 0;
        mapifySrc(s);
        
        for(int i = 0; i < words.size(); i++)
        {
            if(findSequence(words[i]))
            {
                retVal++;
            }
        }
        
        return retVal;
    }
private:  
    void mapifySrc(string& s)
    {        
        for(int i = 0 ; i < s.size(); i++)
        {
            letterMap[s[i]].emplace(i);       
        }
    }
    
    inline bool findSequence(string& word)
    {
        int currIdx = 0;
        for(int i = 0; i < word.size(); i++)
        {
            auto it = letterMap[word[i]].lower_bound(currIdx);
            if(it == letterMap[word[i]].end())
            {
                return false;
            }
            
            currIdx = *it+1;
        }
        
        return true;
    }
    
    LetterMap letterMap;
};
