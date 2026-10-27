class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;

        for(int i  = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {

                area += grid[i][j]*4;

                if(grid[i][j] != 0)
                    area+=2;

                if(i-1 >= 0)
                    area -= min(grid[i-1][j], grid[i][j]);
                if(i+1 < grid.size())
                    area -= min(grid[i+1][j], grid[i][j]);
                if(j-1 >= 0)
                    area -= min(grid[i][j-1], grid[i][j]);
                if(j+1 < grid.size())
                    area -= min(grid[i][j+1], grid[i][j]);
            }
        }

        return area;
    }
};
