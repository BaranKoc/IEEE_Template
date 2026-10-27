class Solution {
public:
    int edgeScore(vector<int>& edges) {

        int n = edges.size();

        vector<long long> inDegree(n,0);

        long long maxVal = LONG_MIN;

        int minIndx = -1;

        for(int i=0;i<edges.size();i++)
            inDegree[edges[i]] += i;

        for(int i=0;i<n;i++)
        {
            if(maxVal < inDegree[i])
            {
                maxVal = inDegree[i];
                minIndx = i;
            }

        }

        return minIndx;
    }
};
