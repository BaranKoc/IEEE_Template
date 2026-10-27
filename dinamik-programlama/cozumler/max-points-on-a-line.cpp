class Solution {
public:

    bool static cmp(vector<int> p1,vector<int> p2){
        if(p1[0]==p2[0])
            return p1[1]<p2[1];
        return p1[0]<p2[0];
    }

    float calcSlope(int x1,int y1,int x2,int y2){
       return (y2-y1)/(float)(x2-x1);
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==2 || points.size()==1)
            return points.size();

        sort(points.begin(),points.end(),cmp);
        int ans=1;

        vector<unordered_map<float,int>> dp(points.size()+1);
        for(int i=1;i<points.size();i++){
            for(int j=0;j<i;j++){
                float slope=calcSlope(points[j][0],points[j][1],points[i][0],points[i][1]);
                if(dp[j].find(slope)!=dp[j].end()){
                    dp[i][slope]=1+dp[j][slope];
                    ans=max(ans,dp[i][slope]);
                }else{
                    dp[i][slope]+=1;
                }
            }
        }

        return ans+1;

    }
};
