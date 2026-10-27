class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        using dp=pair<long int,pair<long int,long int >> ;
        using sp=pair<long int,long int>;
        priority_queue<sp,vector<sp>,greater<sp>> pq;
        int len=tasks.size();

        vector<dp> rearrange;
        for(long int  i=0;i<len;i++)
        {
            rearrange.push_back({tasks[i][0],{tasks[i][1],i}});
        }

        sort(rearrange.begin(),rearrange.end());
        long int i=0;
        long  int finishTime=rearrange[0].first;
        long int k=tasks.size();

        vector<int> res;
        while(k)
        {
            while(i<len && finishTime>=rearrange[i].first)
            {

                pq.push({rearrange[i].second.first,rearrange[i].second.second});
                i++;
            }

            auto [time,ind]=pq.top();
            pq.pop();

            finishTime+=time;
            res.push_back(ind);

            if(pq.empty() && (i<len && finishTime < rearrange[i].first ))
                finishTime=rearrange[i].first;

            k--;
        }
        return res;

    }
};
