class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size(), x = 0;

        for(int i = 1; i<=n+1; i++) x ^= i;

        for(int i = 1; i<n; i+=2) x ^= encoded[i];

        vector <int> res;
        res.push_back(x);
        for(int i = 0; i<n; i++){
            x ^= encoded[i];
            res.push_back(x);
        }
        return res;
    }
};
