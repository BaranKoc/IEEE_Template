class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                    res++;
            }
        }

        for(int i=0;i<grid.size();i++)
        {
            int m=grid[i][0];
            for(int j=1;j<grid[0].size();j++)
            {
                m=max(m,grid[i][j]);
            }
            res+=m;
        }

        for(int j=0;j<grid[0].size();j++)
        {
            int m=grid[0][j];
            for(int i=1;i<grid.size();i++)
            {
                m=max(m,grid[i][j]);
            }
            res+=m;
        }
        return res;
    }
};
