class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int i=1;
        vector<vector<int>> ans;

        for(;i<1001;i++){
            if(customfunction.f(i,i)>z){
                break;
            }
        }
        i--;
        int k=i;

        for(int j=i;j<=1000 && k>0;j++){
            int curr=customfunction.f(k,j);
            if(curr==z){
                ans.push_back({k,j});
                k--;
            }
            else if(curr>z){
                k--;
                j--;
            }
        }
        k=i;

        for(int j=i+1;j<=1000 && k>0;j++){
            int curr=customfunction.f(j,k);
            if(curr==z){
                ans.push_back({j,k});
                k--;
            }
            else if(curr>z){
                k--;
                j--;
            }
        }
        return ans;
    }
};
