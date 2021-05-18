class Solution {
public:
    string convertToBase7(int num) 
    {
        int midVal = num;
        std::string retVal;
        
        if(num >= 0)
        {         
            while(num >= 7)
            {            
                midVal = num % 7;
                num /= 7;
                retVal += std::to_string(midVal);
            }
            retVal += std::to_string(num);
        }
        else
        {
            while(num <= -7)        
            {            
                midVal = num % 7;
                num /= 7;
                retVal = retVal + std::to_string(std::abs(midVal));
            }
            retVal += std::to_string(std::abs(num));
            retVal += "-";
        }
        std::reverse(retVal.begin(), retVal.end());
        
        return retVal;
    }
};
