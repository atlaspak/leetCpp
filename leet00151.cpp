class Solution {
public:
    string reverseWords(string s) 
    {
        int newPoint = 0;
        int lastChar = s.size()-1, firstChar = s.size()-1; 
        string reversedS;
        bool isLastCharFixed = false;
        bool isFirstWord = true;
        
        auto algorithm = [&](int beginFrom, int endTo){
            if(!isFirstWord)
                reversedS += ' ';
            if(reversedS.size() == 0) //because we are adding content
                isFirstWord = false;
            for(int i = beginFrom; i <= endTo; i++, newPoint++){
                reversedS += s[i];
            }
        };
        
        for(; firstChar >= 0; firstChar--){
            if(!isLastCharFixed){
                if(s[firstChar] != ' '){
                    lastChar = firstChar;
                    isLastCharFixed = true;
                }
            }
            if(isLastCharFixed && s[firstChar] == ' ')
            {
                algorithm(firstChar+1, lastChar);
                isLastCharFixed = false;
            }
            else if(isLastCharFixed && firstChar == 0)
            {
                algorithm(firstChar, lastChar);
                isLastCharFixed = false;                
            }
        }
        
        return reversedS;        
    }
};
