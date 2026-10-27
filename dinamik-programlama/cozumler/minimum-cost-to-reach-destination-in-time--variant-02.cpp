typedef pair<int,pair<int,int>> pii;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();

    int dp[n][maxTime+1];

        int ttime[n];
        for(int i=0;i<n;i++){
            ttime[i]=INT_MAX;
            for(int j=0;j<=maxTime;j++){
                dp[i][j]=INT_MAX;
            }
        }
        ttime[0]=0;
        dp[0][0]=passingFees[0];

        vector<vector<int>>adj[n];
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }

        priority_queue<pii,vector<pii>,greater<pii>>minHeap;
        minHeap.push({passingFees[0],{0,0}});

        while(!minHeap.empty()){
            auto top=minHeap.top();
            minHeap.pop();

		   int u=top.second.first;
            int time=top.second.second;
            int cost=top.first;

			if(u==n-1)return cost;

			ttime[u]=time;

            for(auto x:adj[u]){

                if(time+x[1]<ttime[x[0]]){
                    if(time+x[1]<=maxTime){

                        if(cost+passingFees[x[0]]<dp[x[0]][time+x[1]] ){
                            dp[x[0]][time+x[1]]=cost+passingFees[x[0]];
                            ttime[x[0]]=time+x[1];
                            minHeap.push({dp[x[0]][time+x[1]],{x[0],time+x[1]}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
