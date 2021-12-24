class Solution {
public:
    int tribonacci(int n) {
        int firstPtr = 0;
        int secondPtr = 1;
        int thirdPtr = 1;
        int current = firstPtr + secondPtr + thirdPtr;
        
        if(n == 0)
            return firstPtr;
        if(n == 1)
            return secondPtr;
        if(n == 2)
            return firstPtr + secondPtr;
        
        for(int i = 2; i < n; i++)
        {
            current = firstPtr + secondPtr + thirdPtr;
            firstPtr = secondPtr;
            secondPtr = thirdPtr;
            thirdPtr = current;
        }
            
        return current;
    }
};
