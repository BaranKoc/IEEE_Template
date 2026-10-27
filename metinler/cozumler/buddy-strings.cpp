class Solution {
public:

    bool dupeCase(string s){
        unordered_set<char> letters;
        for(auto it : s){
            if(letters.count(it)){
                return true;
            } else {
                letters.insert(it);
            }
        }
        return false;
    }

    bool buddyStrings(string s, string goal) {

        if(goal.length() != s.length()) return false;

        if(s == goal) return dupeCase(s);

        vector<int> diff;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != goal[i]){
                if(diff.size() > 2){
                    return false;
                } else {
                    diff.push_back(i);
                }
            }
        }

        if(diff.size() == 1) return false;

        return (s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]]);
    }
};
