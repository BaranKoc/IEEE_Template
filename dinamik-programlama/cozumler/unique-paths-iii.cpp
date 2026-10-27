class Solution {
public:
    int dfs(vector<vector<int>>&grid,int x,int y,int zero){

        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1){
            return 0;
        }
        if(grid[x][y] == 2){
            return zero == -1 ? 1 : 0;

        }
        grid[x][y] = -1;
        zero--;

        int totalPaths = dfs(grid, x + 1, y, zero) +
            dfs(grid, x - 1, y, zero) +
            dfs(grid, x, y + 1, zero) +
            dfs(grid, x, y - 1, zero);

        grid[x][y] = 0;
        zero++;

        return totalPaths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
       int start_x,start_y=0,cntzero=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) cntzero++;
               else if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;
                }
            }
        }
      return dfs(grid,start_x,start_y,cntzero);

    }
};
