
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int windex = 0, curCol = cols, retVal = 0;
        for(int i = 1; i <= rows; i++)
        {
            while (curCol >= (int)sentence[windex].size())
            {
                curCol = curCol - (sentence[windex].size() + 1);
                windex++;

                if(windex == (int)sentence.size())
                {
                    retVal++;
                    windex = 0;
                    
                    //recurring column of first line
                    if(i == 1 && curCol > 0 && (cols / (cols - curCol)) > 0)
                    {
                        retVal = (cols / (cols - curCol));
                        curCol = cols % (cols - curCol);
                    }

                    //recurring of a pattern of line(s)
                    if(curCol < (int)sentence[0].size())
                    {                        
                        retVal = retVal * (rows / i);
                        i = rows - (rows % i);
                    }
                }
            }
            curCol = cols;            
        }

        return retVal;
    }
};
