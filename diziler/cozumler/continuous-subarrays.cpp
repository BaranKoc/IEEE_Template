class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        deque<int> minn, maxx;
        int n = nums.size();
        int left = 0;
        long long ans = 0;
        for (int right = 0; right < n; right++)
        {
            while (!maxx.empty() && nums[maxx.back()] < nums[right])
                maxx.pop_back();
            maxx.push_back(right);

            while (!minn.empty() && nums[minn.back()] > nums[right])
                minn.pop_back();
            minn.push_back(right);

            while (nums[maxx.front()] - nums[minn.front()] > 2){
                if (maxx.front() < minn.front())
                    maxx.pop_front();
                else if (maxx.front() > minn.front())
                    minn.pop_front();
                else
                    minn.pop_front(),
                    maxx.pop_front();
                left = max(left, min(maxx.front(), minn.front()));
            }
            int len = right - left + 1;
            ans += len;
        }
        return ans;
    }
};
