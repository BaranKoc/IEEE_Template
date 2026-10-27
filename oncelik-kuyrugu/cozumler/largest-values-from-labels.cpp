class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {

        priority_queue<pair<int,int>>q;
        for(int i=0;i<values.size();i++)
        {
            q.push({values[i],i});
        }
        long long int ans=0;
        unordered_map<int,int>m;

        int i=0;
        while(i<numWanted)
        {
            int t=q.top().first;
            int ind=q.top().second;
            q.pop();
            if(m[labels[ind]]<useLimit)
            {
                ans+=t;
                m[labels[ind]]++;
                i++;
            }
            if(q.size()==0)
            {
                break;
            }
        }
        return ans;
    }
};
