class Solution {
public:

    int atmostK(vector<int>& arr, int K) {
        int i = 0, j = 0, substrings = 0;
        unordered_map<int, int> freq;
        const int N = arr.size();

        while(i < N) {

            if(K >= 0) {
                ++freq[arr[i]];
                if(freq[arr[i]] == 1)
                    --K;
                ++i;
            }

            while(K < 0) {
                --freq[arr[j]];
                if(freq[arr[j]] == 0)
                    ++K;
                ++j;
            }

            substrings += i - j + 1;
        }
        return substrings;
    }

    int subarraysWithKDistinct(vector<int>& arr, int K) {
        return atmostK(arr, K) - atmostK(arr, K-1);
    }
};
