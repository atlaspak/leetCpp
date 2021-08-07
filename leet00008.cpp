#define NEGATIVE    -1
#define POSITIVE    -2
#define SPACE       -3
#define DOT         -4
#define OTHERS      -99

class Solution {
public:
    int myAtoi(string s) 
    {
        bool isCapped = false, isNumbered = false, isClean = true;
        int isPositive = 1;
        int currChar = 0;
        int leftStart = 0, rightStart = s.size()-1;
        long factor = 1;
        long retVal = 0;
        
        //eliminate left hand side
       for(; leftStart < s.size(); ++leftStart)
       {
           currChar = getChar(s[leftStart]);
           if(currChar == -9)
           {
               //left hand side cannot include random char
               return 0;
           }
           else if(currChar == NEGATIVE)
           {
               if(isCapped)
               {
                   //left hand side cannot have more than one sign
                   return 0;
               }
               isCapped = true;
               isPositive = -1;
           }
           else if(currChar == POSITIVE)
           {
               if(isCapped)
               {
                   //left hand side cannot have more than one sign
                   return 0;                   
               }
               isCapped = true;
           }
           else if(currChar == SPACE && isNumbered)
           {
               rightStart = leftStart;
           }
           else if(currChar == SPACE && isCapped)
           {
               return 0;
           }
           else if(currChar == DOT)
           {
               break;
           }
           else if(currChar == 0)
           {
               //Zero is skipable
               isCapped = true;
               isNumbered = true;
           }
           else if(currChar > 0)
           {
               break;
           }
       }
        
       for(int i = 0; rightStart >= leftStart; --rightStart, ++i)
       {           
           currChar = getChar(s[rightStart]);

           if(currChar >= 0 && currChar <= 9)
           { 
               if(isClean == false)
               {
                    retVal = 0;
                    factor = 1;
                    i = 0;
                    isClean = true;
               }
               if(factor >= 2000000000)
               {
                   if(isPositive == 1)
                   {
                       return INT_MAX;
                   }
                   return INT_MIN;
               }
               else if(i != 0)
               {
                   factor *= 10; 
               }
               retVal += currChar * factor;               
              
           }
           else if(currChar == DOT)
           {
               retVal = 0;
               factor = 1;
               i = -1;
           }
           else
           {
               isClean = false;
           }
        }
        
       if(retVal > INT_MAX)
       {
           if(isPositive == 1)
           {
               return INT_MAX;
           }
           return INT_MIN;
       }
        return retVal * isPositive;
    }
    
    int getChar(char c)
    {
        if(c >= '0' && c <= '9')
        {
            return (int)(c - '0');
        }
        else if(c == '-') 
        {
            return -1;
        }
        else if(c == '+')
        {
            return -2;            
        }
        else if(c == ' ')
        {
            return -3;
        }
        else if(c == '.')
        {
            return -4;
        }
        return -9;
    }
};
