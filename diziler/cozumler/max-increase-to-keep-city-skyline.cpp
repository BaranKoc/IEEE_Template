class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<int> maxfromcol(n,INT_MIN);
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                maxfromcol[j]=max(maxfromcol[j],grid[i][j]);
            }
        }
        int cost=0;
        for(int i=0;i<n;i++){

            int mx=INT_MIN;
            for(int j=0;j<n;j++){
                mx=max(mx,grid[i][j]);
            }
            cout<<mx<<endl;

            for(int j=0;j<n;j++){
                int temp=grid[i][j];
                grid[i][j]=min(mx,maxfromcol[j]);
                cost+=grid[i][j]-temp;
            }
        }
        return cost;
    }
};
