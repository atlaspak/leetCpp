class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int alexPoints = 0, leePoints = 0, left = 0, right = piles.size()-1;
        bool alexTurn = true;
        for(int i = 0; i < piles.size()/2; i++)
        {
            if(alexTurn)
            {
                if(piles[left]>piles[right])
                {
                    alexPoints += piles[left];
                    left++;
                }
                else
                {
                    alexPoints += piles[right];
                    right--;
                }
            }
            else
            {
                if(piles[left]>piles[right])
                {
                    alexPoints += piles[left];
                    left++;
                }
                else
                {
                    alexPoints += piles[right];
                    right--;
                }
            }
        }
        
        return alexPoints > leePoints;
    }
};
