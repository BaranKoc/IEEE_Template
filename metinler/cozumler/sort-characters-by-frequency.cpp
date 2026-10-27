class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }

        priority_queue<pair<int,char>>pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }
        string str="";
        int val;
        while(!pq.empty())
        {
            val=pq.top().first;
            while(val--)
            {
                str.push_back(pq.top().second);
            }
            pq.pop();
        }
        return str;

    }
};
