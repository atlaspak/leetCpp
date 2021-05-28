class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();

        int retVal = 0;
        int currIsland = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j])
                {
                    currIsland++;
                    grid[i][j] = 0;
                    currIsland = measureIsland(grid, i, j);        
                    
                    if(currIsland > retVal)
                    {
                        retVal = currIsland;
                    }
                }
            }
        }
        
        return retVal;
    }

    int measureIsland(vector<vector<int>>& grid, int i, int j)
    {
        int total = 0;
        //go right
        if(i < m && grid[i+1][j])
        {
            grid[i+1][j] = 0;
            total = measureIsland(grid, i+1, j) + 1;
        }
        //go left
        if(i > 0 && grid[i-1][j])
        {
            grid[i-1][j] = 0;
            total = measureIsland(grid, i-1, j) + 1;
        }
        //go down
        if(j < n && grid[i][j+1])
        {
            grid[i][j+1] = 0;
            total = measureIsland(grid, i, j+1) + 1;
        }

        return total;
    }

    int m;
    int n;
};
