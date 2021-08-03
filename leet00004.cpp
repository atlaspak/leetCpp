class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {        
        int totalSize = nums1.size() + nums2.size();
        double median = 0, prevMedian = 0;
        
        for(int i = 0; i <= totalSize/2; ++i)
        {
            prevMedian = median;
            median = getNext(nums1, nums2);
        }
        
        if(totalSize%2 == 0)
        {
            median = (median + prevMedian) / 2;
        }
        
        return median;
    }
    
    int getNext(vector<int>& nums1, vector<int>& nums2)
    {
        int num1 = 0, num2 = 0;
        
        if(i1 < nums1.size())
        {
            num1 = nums1[i1];
        }
        else
        {
            if(i2 < nums2.size())
            {                
                num1 = nums2[i2]; 
                ++i2;
                return num1;
            }
        }
        
        if(i2 < nums2.size())
        {
            num2 = nums2[i2];
        }
        else
        {
            if(i1 < nums1.size())
            {                
                num2 = nums1[i1];
                i1++;
                return num2;
            }
        }        
        
        if(num1 < num2)
        {
            i1++;
            return num1;
        }
        else
        {
            i2++;
            return num2;
        }
    }
    
    private:
    int i1 = 0, i2 = 0;
};

