class Solution {
public:

    int dp[205][205];

    vector<int> dx = {-1, 0, 1, 0};

    vector<int> dy = {0, 1, 0, -1};

    int dfs(vector<vector<int>>& matrix, int i, int j, int n, int m)
    {

        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;

        for(int k = 0; k < 4; k++)
        {
            int new_i = i + dx[k];

            int new_j = j + dy[k];

            if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && matrix[new_i][new_j] > matrix[i][j])
            {
                maxi = max(maxi, dfs(matrix, new_i, new_j, n, m));
            }
        }

        return dp[i][j] = 1 + maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();

        int m = matrix[0].size();

        memset(dp, -1, sizeof(dp));

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int ans = dfs(matrix, i, j, n, m);

                maxi = max(maxi, ans);
            }
        }

        return maxi;
    }
};
