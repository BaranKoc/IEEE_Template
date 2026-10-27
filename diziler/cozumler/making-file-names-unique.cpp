class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {

        unordered_map<string, int> mp;
        vector<string> res;

        for(auto i : names){
            string val = i;
            int cnt = mp[val];

            while(mp[val] != 0){
                val = i + '(' + to_string(cnt) + ')';
				cnt++;
                mp[i] = cnt;

            }
            mp[val]++;
            res.emplace_back(val);
        }
        return res;

    }
};
