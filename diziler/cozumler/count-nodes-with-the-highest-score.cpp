class Solution {
public:

    int dfs(int src,vector<vector<int>>& g,vector<int>& size)
    {
         int ans = 1;
         for(auto child : g[src]){
             ans += dfs(child,g,size);
         }
         return size[src] = ans;
     }

    int countHighestScoreNodes(vector<int>& parents)
    {
        int n=parents.size();
        vector<int>size(n,0);
        vector<vector<int>>g(n);
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i);
        }

        dfs(0,g,size);

        long long int maxCount = 0;
        long long int maxScore = 0;
        for(int i=0;i<n;i++)
        {

            long long int product = 1;
            product = max(product, (long long int)(n - size[i]));
            for(auto x : g[i])
            {
                product = product*size[x];
            }

            if(product > maxScore){
                maxScore = product;
                maxCount = 1;
            }
            else if(product == maxScore){
                maxCount++;
            }
        }

        return maxCount;
    }
};
