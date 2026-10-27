class Solution
{
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k)
    {
        int n=vals.size();
        vector<pair<int, int>> adj[n];

        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], vals[edges[i][1]]});
            adj[edges[i][1]].push_back({edges[i][0], vals[edges[i][0]]});
        }

        int maxi = INT_MIN;
        vector<int> connectedNodesVals;
        for(int node=0; node<n; node++)
        {
            for(auto it:adj[node])
            {
                connectedNodesVals.push_back(it.second);
            }

            sort(connectedNodesVals.begin(), connectedNodesVals.end(), greater<int>());

            int i=0, sum=vals[node];
            maxi = max(maxi, sum);
            while(i<connectedNodesVals.size() && i<k)
            {
                sum += connectedNodesVals[i++];
                maxi = max(maxi, sum);
            }

            connectedNodesVals.clear();
        }
        return maxi;

    }
};
