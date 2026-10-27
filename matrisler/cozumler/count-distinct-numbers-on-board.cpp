class Solution {
public:
    unordered_set<int> s;
    int distinctIntegers(int n) {
        s.insert(n);
        for(int i = 2; i < n; ++i) {
            if(n%i == 1 && s.find(i) == s.end()) distinctIntegers(i);
        }
        return s.size();
    }
};
