class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int firstInd = k - 1, lastInd = cardPoints.size()-1;
        int total = 0, subtotal;
        
        for(int i = 0; i < k; i++)
        {
            total += cardPoints[i];
            subtotal = total;
        }
        
        if(k == cardPoints.size())
        {
            return total;
        }
        
        for(int j = 0; j < k; j++)
        {
            subtotal = subtotal + cardPoints[lastInd] - cardPoints[firstInd];
            
            if(subtotal > total)
            {
                total = subtotal;
            }
            
            lastInd--;
            firstInd--;
        }
        
        return total;
    }
};
