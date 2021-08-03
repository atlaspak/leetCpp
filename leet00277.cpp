/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n)
    {
        list<int> suspects;
        int j = n-1;
        for(int i = 0; j > i; ++i, --j)
        {
            if(knows(i,j))
            {
                suspects.push_front(j);
            }
            if(knows(j,i))
            {
                suspects.push_front(i);
            }
        }
        
        if(n%2 == 1 && knows(0,j))
        {
            suspects.push_front(j);
        }
        
        if(suspects.size() == 0)
        {
            return -1;
        }
        
        return checkSuspect(suspects, n);
    }
    
    int checkSuspect(list<int>& suspects, int n)
    {
        bool notFamous = false;
        for(auto& suspect : suspects)
        {
            notFamous = false;
            for(int i = 0; i < n; i++)
            {
                if(i == suspect)
                {
                    continue;
                }
                if(!knows(i, suspect) || knows(suspect, i))
                {
                    notFamous = true;
                    break;
                }
            }
            if(!notFamous)
            {
                return suspect;
            }
        }
        return -1;
    }
};
