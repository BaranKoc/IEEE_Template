class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {

        priority_queue<pair<int,pair<int,int>>> pq;
        int n= points.size();
        for(int i=0;i<n;i++)
        {
            int dist=(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            pq.push({dist, {points[i][0],points[i][1]}});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> temp={(pq.top().second.first),pq.top().second.second};
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};
