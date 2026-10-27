class Solution {
public:
    int solve(int i, int j, int m , int n, vector<vector<int>> &grid)
    {

        if(i >= m || j >= n)
            return INT_MAX;

        int down = solve(i + 1, j, m, n, grid);
        int right = solve(i, j + 1, m, n, grid);

        int health = min(down, right);

        if(health == INT_MAX)
        {
            health = 1;
        }

        int ans = 0;
        if(health - grid[i][j] > 0)
        {
            ans = health - grid[i][j];
        }
        else
        {
            ans = 1;
        }

        return ans;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();

        return solve(0, 0, m, n, dungeon);
    }
};
