class Solution {
private:
    int mod=1e9+7;

    unordered_map<int,vector<int>>hatTable;

    vector<vector<int>>mem;

    int solve(int hat,int mask,int n){

        if(mask==(1<<n)-1){
            return 1;
        } else if(hat==41){

            return 0;
        } else if(mem[hat][mask]!=-1){
            return mem[hat][mask];
        } else if(!hatTable.count(hat)) {
            return mem[hat][mask]=solve(hat+1,mask,n)%mod;
        }
        else {

            int ans=solve(hat+1,mask,n);

            for(int i=0;i<hatTable[hat].size();i++){
                int curr=hatTable[hat][i];
                if((mask>>curr)&1){
                    continue;
                } else {
                    ans=(ans%mod+solve(hat+1,mask|(1<<curr),n)%mod)%mod;
                }
            }
            return mem[hat][mask]=ans;
        }
    }
public:
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        for(int i=0;i<hats.size();i++){
            for(int j=0;j<hats[i].size();j++){
                hatTable[hats[i][j]].push_back(i);
            }
        }
        mem=vector<vector<int>>(41,vector<int>(1<<n,-1));
        return solve(1,0,n);
    }
};
