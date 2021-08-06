class Solution {
public:
    int reverse(int x) {
        int out = 0;
        int digits = 0;
        int signBit = 1;
        
        if(x == -2147483648)
        {
            return 0;
        }
        
        if(x < 0)
        {
            signBit = -1;
            x *= signBit;
        }
        
        if(x > 1000000000)
        {
            if((x%10) > 2)
            {
                return 0;
            }
            stringstream ss;
            ss << x;
            string strx = ss.str();
            std::reverse(strx.begin(), strx.end());
            try
            {
                out = std::stoi(strx);    
            }
            catch(...)
            {
                return 0;
            }
            return out * signBit;
        }

        //Actual code after handling ridiculous edge cases
        while (x != 0)
        {
            out *= 10;
            out += (x%10);
            x /= 10;
        }
        
        return out * signBit;
    }
};
