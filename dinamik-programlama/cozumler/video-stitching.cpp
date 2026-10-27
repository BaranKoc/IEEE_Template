class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[0]<b[0]) return true;
        else if(a[0]==b[0]) return a[1]>b[1];
        return false;
    }

    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), comp);
        vector<vector<int>> res;

        if(clips[0][0] != 0) return -1;
        res.push_back(clips[0]);

    for(int i=1; i<clips.size(); i++){
            if(res.back()[1]>=time) break;
            if(clips[i][0]==res.back()[0]) continue;
            if(clips[i][1]>res.back()[1]){
                if(res.size()>1 and res[res.size()-2][1]>=clips[i][0]) res.pop_back();
                res.push_back(clips[i]);
            }
        }

        int prev = res[0][1];
        for(int i=1; i<res.size(); i++){
            if(res[i][0]>prev) return -1;
            prev = res[i][1];
        }

        if(res.back()[1]<time) return -1;
        return res.size();
    }
};
