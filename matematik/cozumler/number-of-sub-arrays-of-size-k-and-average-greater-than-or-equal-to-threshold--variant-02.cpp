class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int window_sum = 0;
        int count = 0;

        for(int i = 0 ; i < k ; ++i)
            window_sum += arr[i];

        for(int i = 0 ; i < arr.size() - k + 1 ; ++i)
        {
            if(i != 0)
            {
                window_sum -= arr[i - 1];
                window_sum += arr[i + k - 1];

            }

            int window_average = window_sum / k;

            if(window_average >= threshold)
                count++;
        }

        return count;

    }
};
