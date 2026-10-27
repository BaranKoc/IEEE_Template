class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& arr) {

        vector<int>ans;

        int maxcounter = INT_MIN;
        vector<int>vis(n+1,0);

        int idx = 1;

        bool flag = true;

        while(idx < arr.size())
        {
            int startpos = arr[idx-1];
            int endpos = arr[idx];

            int temp = startpos;

            if(idx > 1)
            {
               temp+=1;

               if(temp > n)
               temp = 1;
            }

            while(temp!=endpos)
            {
                vis[temp]++;
                maxcounter = max(maxcounter , vis[temp]);
                if(temp == n)
                {
                    temp = 1;
                }
                else
                {
                   temp++;
                }
            }
            vis[temp]++;
            maxcounter = max(maxcounter,vis[temp]);
            idx = idx + 1;
        }
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i] == maxcounter)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
