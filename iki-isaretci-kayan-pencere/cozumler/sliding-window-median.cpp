class Solution {
public:

    vector<double> binarySearchSol(vector<int>& nums, int k) {
        vector<double> medians;
        vector<int> window;

        if(k > nums.size())
            return medians;

        int i = 0;

        while(i < k) {
            window.emplace_back(nums[i]);
            ++i;
        }

        sort(window.begin(), window.end());

        double median = k % 2 ? window[k / 2] : (double) ((double)window[k/2 - 1] + window[k/2]) / 2;
        medians.emplace_back(median);

        for(; i < nums.size(); i++) {

            auto it = lower_bound(window.begin(), window.end(), nums[i - k]);
            window.erase(it);

            it = lower_bound(window.begin(), window.end(), nums[i]);
            window.insert(it, nums[i]);

            double median = k % 2 ? window[k / 2] : (double) ((double)window[k/2 - 1] + window[k/2]) / 2;
            medians.emplace_back(median);
        }
        return medians;
    }

    vector<double> treeSol(vector<int>& nums, int k) {
        multiset<int> elements;
        vector<double> medians;

        int i = 0;

        while(i < k) {
            elements.insert(nums[i]);
            ++i;
        }

        auto mid = next(elements.begin(), k / 2);
        double median = k % 2 ? *mid : ((double)*mid + *prev(mid)) / 2;
        medians.emplace_back(median);

        for(; i < nums.size(); i++) {

            elements.insert(nums[i]);

            if(nums[i] < *mid)
                --mid;

            auto delete_pos = elements.find(nums[i - k]);

            if(nums[i-k] <= *mid)
                ++mid;
            elements.erase(delete_pos);

            double median = k % 2 ? *mid : ((double)*mid + *prev(mid)) / 2;
            medians.emplace_back(median);
        }

        return medians;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        return treeSol(nums, k);
    }
};
