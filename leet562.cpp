class Solution {
public:
    int longestLine(vector<vector<int>>& mat) 
    {
        n = mat.size();
        m = mat[0].size();
        int retVal = 0;
        int currVal = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j])
                {
                    if(retVal <= m-j)
                    {
                        currVal = getHorizLine(i,j,mat);
                        if(currVal > retVal)
                        {
                            retVal = currVal;
                        }

                        if(retVal <= n-i)
                        {
                            currVal = getDiagonal(i,j,mat);
                            if(currVal > retVal)
                            {
                                retVal = currVal;
                            }
                        }
                    }
                    
                    if(retVal <= n-i)
                    {
                        currVal = getVertiLine(i,j,mat);
                        if(currVal > retVal)
                        {
                            retVal = currVal;
                        }
                        
                        if(retVal <= j)
                        {
                            currVal = getAntidiagonal(i,j,mat);
                            if(currVal > retVal)
                            {
                                retVal = currVal;
                            }
                        }
                    }
                }
            }
        }

        return retVal;   
    }

private:
    int getHorizLine(int i, int j, vector<vector<int>>& mat)
    {
        int retVal = 0;
        if(j-1 >= 0 && mat[i][j-1])
        {
            //this line visited before no need to calculate
            return 0;
        }

        for(; j < m; j++)
        {
            if(mat[i][j])
            {
                retVal++;
            }
            else
            {
                break;
            }
        }

        return retVal;
    }
    
    int getVertiLine(int i, int j, vector<vector<int>>& mat)
    {
        int retVal = 0;
        if(i-1 >= 0 && mat[i-1][j])
        {
            //this line visited before no need to calculate
            return 0;
        }
        
        for(; i < n; i++)
        {
            if(mat[i][j])
            {
                retVal++;
            }
            else
            {
                break;
            }
        }
        
        return retVal;
    }

    int getDiagonal(int i, int j, vector<vector<int>>& mat)
    {
        int retVal = 0;
        if(i - 1 >= 0 && j-1 >= 0 && mat[i-1][j-1])
        {
            //this diagonal visited before no need to calculate
            return 0;            
        }

        for(; i < n && j < m; i++, j++)
        {
            if(mat[i][j])
            {
                retVal++;
            }
            else
            {
                break;
            }
        }

        return retVal;
    }

    int getAntidiagonal(int i, int j, vector<vector<int>>& mat)
    {
        int retVal = 0;
        if(i-1 >= 0 && j+1 < m && mat[i-1][j+1])
        {
            //this antidiagonal visited before
            return 0;
        }

        for(; i < n && j >= 0; i++, j--)
        {
            if(mat[i][j])
            {
                retVal++;
            }
            else
            {
                break;
            }
        }

        return retVal;
    }

    int n,m;
};
