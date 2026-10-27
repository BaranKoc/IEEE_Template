class Solution {
public:
    int maxRepOpt1(string text) {
        vector<pair<int, int>> intervals[26];

        for(int i = 0; i < text.size();){
            int st = i, ed = i;
            while(i < text.size() && text[i] == text[st]){
                ed = i;
                i++;
            }
            intervals[text[st] - 'a'].push_back({st, ed});
        }

        int ans = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < intervals[i].size(); j++){

                int len1 = intervals[i][j].second - intervals[i][j].first + 1;
                if(intervals[i].size() > 1)
                    len1++;
                ans = max(ans, len1);

                if(j+1 < intervals[i].size() && intervals[i][j].second + 2 == intervals[i][j+1].first){
                    int len2 = intervals[i][j].second - intervals[i][j].first + 1 + intervals[i][j+1].second - intervals[i][j+1].first + 1;
                    if(intervals[i].size() > 2){
                        len2++;
                    }
                    ans = max(ans, len2);
                }
            }
        }

        return ans;
    }
};
