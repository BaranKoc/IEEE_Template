#define ipair pair<int,int>
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

       sort(events.begin(), events.end());

        int mx = 0, ans = 0, n = events.size();
        priority_queue<ipair, vector<ipair>, greater<>> pq;

        for(int i=0; i<n; i++)
        {
            while(!pq.empty() && pq.top().first < events[i][0])
                mx = max(mx, pq.top().second), pq.pop();

            ans = max(ans, mx+events[i][2]);
            pq.push({events[i][1], events[i][2]});
        }

        return ans;
    }
};
