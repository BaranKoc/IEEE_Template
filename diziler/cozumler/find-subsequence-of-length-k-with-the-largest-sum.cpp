class Solution {
public:
    vector<int> maxSubsequence(vector<int>& A, int k) {
        vector<int> id(A.size());
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return A[a] > A[b]; });
        id.resize(k);
        sort(begin(id), end(id));
        vector<int> ans;
        for (int i : id) ans.push_back(A[i]);
        return ans;
    }
};
