class Solution {
public:

    int getRepeatedLen(string& s, int p) {
        int res = 0;
        char c = s[p];
        while(p < s.size() && s[p] == c) {
            res++;
            p++;
        }
        return res;
    }

    bool isStretchy(string& s, string& t, unordered_set<char>& sMap) {
        if(s == t) return true;
        if(s.size() < t.size()) return false;
        int p1 = 0;
        int p2 = 0;

        while(p1 < s.size()) {
            if(!sMap.count(t[p2])) return false;
            int want = getRepeatedLen(s,p1);
            int have = getRepeatedLen(t,p2);
            if( have > want) return false;
            int needToAdd = want - have;
            if(want != have && needToAdd + have < 3) return false;
            p1 += want;
            p2 += have;
        }
        return true;
    }

    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        unordered_set<char> sMap(s.begin(),s.end());

        for(string& w : words) {
            if(isStretchy(s,w,sMap)) res++;
        }
        return res;
    }
};
