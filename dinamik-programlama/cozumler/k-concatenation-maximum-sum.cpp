class Solution {
public:

    int kConcatenationMaxSum(vector<int>& arr, int k) {

        const int n = arr.size();
        int64_t s{}, min_s{}, max_score{INT_MIN};

        for(int i=0; i<n; i++){
            s += arr[i];
            max_score = max(max_score, s - min_s);
            min_s = min(min_s, s);
        }

        if(k > 1){

            if(k > 2) s = max(s, s + s * (k - 2));

            for(int i=0; i<n; i++){
                s += arr[i];
                max_score = max(max_score, s - min_s);
                min_s = min(min_s, s);
            }
        }

        int ans = static_cast<int>(max_score % (1000000000 + 7));

        if(ans < 0) return 0;
        else return ans;
    }
};
