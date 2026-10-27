class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        int n = s.size();
        if(n < 2) return s;
        int sz = knowledge.size();
        unordered_map<string, string> mp;
        for(int i=0; i<sz; ++i){
            mp.insert({knowledge[i][0], knowledge[i][1]});
        }
        for(int i=0; i<n; i++){

            if(s[i] == '('){
                string key;
                i++;
                while(s[i] != ')'){
                    key += s[i++];
                }
                string value;
                if(mp.find(key) != mp.end()){
                    value = mp[key];
                    ans += value;
                }
                else {
                    ans += "?";
                }
            }
            else ans += s[i];
        }
        return ans;
    }
};

**Please do upvote**
