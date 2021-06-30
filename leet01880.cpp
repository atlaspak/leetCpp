class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        if(getValue(firstWord) + getValue(secondWord) == getValue(targetWord))
        {
            return true;
        }
        return false;
    }
    
private:
    int getValue(string word)
    {
        int retVal = 0;
        int coef = 1;
        for(int i = word.size()-1; i < word.size(); i--)
        {
            retVal += (((int)word[i] - (int)'a') * coef);
            coef *= 10;
        }
        printf("%d\n", retVal);
        return retVal;
    }
};
