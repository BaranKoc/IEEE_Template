class Solution {
public:
    bool isValid(int r1, int r2, int c1, int c2, vector<vector<int>>& grid, vector<vector<int>>& rg, vector<vector<int>>& cg,int checkSum){

        for(int i = r1 + 1; i<r2; i++){
            int sum = rg[i][c2];
            if(c1>0)sum-=rg[i][c1-1];
            if(sum!=checkSum)return false;
        }

        for(int j = c1 + 1; j<c2; j++){
            int sum = cg[r2][j];
            if(r1>0)sum-=cg[r1-1][j];
            if(sum!=checkSum)return false;
        }
        int sum = 0;

        for(int i = r1, j = c1; i<=r2&&j<=c2; i++, j++){
            sum+=grid[i][j];
        }
        if(sum!=checkSum)return false;
        sum = 0;

        for(int i = r1, j = c2; i<=r2&&j>=c1; i++, j--){
            sum+=grid[i][j];
        }
        if(sum!=checkSum)return false;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>rg, cg;
        rg = grid;
        cg = grid;

        for(int i = 0; i<m; i++){
            for(int j = 1; j<n; j++){
                rg[i][j] += rg[i][j-1];
            }
        }

        for(int j = 0; j<n; j++){
            for(int i = 1; i<m; i++){
                cg[i][j] += cg[i-1][j];
            }
        }
        int ans = 1;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(m-i<=ans)return ans;

                int r = i + ans;
                int c = j + ans;
                while(r<m&&c<n){

                    int rsum1 = j>0 ? rg[i][c] - rg[i][j-1] : rg[i][c];
                    int csum1 = i>0 ? cg[r][j] - cg[i-1][j] : cg[r][j];
                    int rsum2 = j>0 ? rg[r][c] - rg[r][j-1] : rg[r][c];
                    int csum2 = i>0 ? cg[r][c] - cg[i-1][c] : cg[r][c];
                    if(rsum1==csum2&&rsum2==csum2&&isValid(i,r,j,c,grid, rg, cg, rsum1)){
                        ans = max(ans, r-i+1);
                    }
                    r++;
                    c++;
                }
            }
        }
        return ans;
    }
};
