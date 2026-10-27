class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int n=destination[0]+1,m=destination[1]+1;

        vector<vector<int>> ways(n,vector<int> (m));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1||j==m-1){
                    ways[i][j]=1; continue;
                }
                ways[i][j]=ways[i][j+1]+ways[i+1][j];
            }
        }

        string ans="";

        int i=0,j=0;
        while(i<n-1&&j<m-1){

             if(k<=ways[i][j+1]){
                ans=ans+'H';j++;
             }

            else{
                k=k-ways[i][j+1];
                i++;
                ans=ans+'V';
            }

         }
         while(j++<m-1) ans=ans+'H';
         while(i++<n-1) ans=ans+'V';

        return ans;

    }
};
