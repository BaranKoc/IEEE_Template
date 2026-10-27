class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int res=0;
        int m=0;
        for(auto x:events)
            m=max(m,x[1]);

        sort(events.begin(),events.end());
        int j=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<=m;i++)
        {
            while(!pq.empty() && pq.top()<i)
                pq.pop();

            while(j<events.size() && events[j][0]==i)
                pq.push(events[j++][1]);

            if(!pq.empty())
            {
                pq.pop();
                res++;
            }
        }
        return res;
    }
};
