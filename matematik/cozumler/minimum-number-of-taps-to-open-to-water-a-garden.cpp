class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> v;
        for(int i=0;i<ranges.size();i++){

            v.push_back({i-ranges[i],i+ranges[i]});
        }

        sort(v.begin(),v.end());

        int uncovered = 0;
        int idx = 0;

        int cnt = 0;

        bool ok = true;

        while(uncovered<n){

            int new_uncovered = uncovered;
            while(idx<n+1 && v[idx].first<=uncovered){
                new_uncovered = max(new_uncovered,v[idx].second);
                idx++;
            }

            cnt++;

            if(new_uncovered == uncovered){
                ok = false;
                break;
            }

            uncovered = new_uncovered;
        }
        if(ok) return cnt;
        return -1;
    }
};
