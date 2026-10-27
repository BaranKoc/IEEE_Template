class Solution {

#define ENABLE_LOG(...)

public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int chunk_size = (int)(sqrt(nums.size())) / 2 * 2 + 2;
        const int original_n = nums.size();
        constexpr int kPadPositive = 100006;
        constexpr int kPadNegative = -100006;

        for (int i=0; i<nums.size() % (4 * chunk_size); ++i) {
            nums.push_back(i % 2 == 0 ? kPadPositive : kPadNegative);
        }
        ENABLE_LOG(
            cout << "chunk_size: " << chunk_size << endl;

            cout << "padded array: ";
            for (int v: nums) cout << v << " "; cout << endl;
        )

        vector<int> chunk_buffer(chunk_size);
        for (int i=0; i < nums.size(); i += chunk_size) {
            chunk_buffer.clear();
            for (int j=i; j<i+chunk_size; ++j)
                if (nums[j] > 0)
                    chunk_buffer.push_back(nums[j]);
            for (int j=i; j<i+chunk_size; ++j)
                if (nums[j] < 0)
                    chunk_buffer.push_back(nums[j]);

            copy_n(chunk_buffer.cbegin(), chunk_size, nums.begin() + i);
        }
        ENABLE_LOG(
            cout << "chunk-sorted array: ";
            for (int v: nums) cout << v << " "; cout << endl;
        )

        chunk_buffer = vector<int>{nums.begin(), nums.begin() + chunk_size};
        for (int i = chunk_size; i<nums.size(); i+= chunk_size) {
            const int m = find_if(chunk_buffer.cbegin(), chunk_buffer.cend(), [](int v) {
                return v < 0;
            }) - chunk_buffer.cbegin();
            const int n = chunk_size - m;
            const int p = find_if(nums.cbegin() + i, nums.cbegin() + i + chunk_size, [](int v) {
                return v < 0;
            }) - (nums.cbegin() + i);
            const int q = chunk_size - p;

            if (m + p >= chunk_size) {

                copy_n(chunk_buffer.cbegin(), m, nums.begin() + i - chunk_size);
                copy_n(nums.cbegin() + i, chunk_size - m, nums.begin() + i - chunk_size + m);
                vector<int> new_buffer;

                copy_n(nums.cbegin() + i + (chunk_size - m),
                       p - (chunk_size - m),
                       back_inserter(new_buffer));

                copy_n(chunk_buffer.cbegin() + m, n, back_inserter(new_buffer));

                copy_n(nums.cbegin() + i + p, q, back_inserter(new_buffer));
                chunk_buffer = move(new_buffer);
            } else {

                copy_n(chunk_buffer.cbegin() + m, n, nums.begin() + i - chunk_size);
                copy_n(nums.cbegin() + i + p, chunk_size - n, nums.begin() + i - chunk_size + n);
                vector<int> new_buffer;

                copy_n(chunk_buffer.cbegin(), m, back_inserter(new_buffer));

                copy_n(nums.cbegin() + i, p, back_inserter(new_buffer));

                copy_n(nums.cbegin() + i + p + chunk_size - n, q - (chunk_size - n),
                      back_inserter(new_buffer));
                chunk_buffer = move(new_buffer);
            }
        }
        copy_n(chunk_buffer.cbegin(), chunk_size, nums.begin() + nums.size() - chunk_size);

        ENABLE_LOG(
            cout << "homonegeous array: ";
            for (int v: nums) cout << v << " "; cout << endl;
        )

        const int chunk_cnt = nums.size() / chunk_size;

        vector<int> target(chunk_cnt);
        int positive_chunks = 0, negative_chunks = 0;
        for (int i=0; i<chunk_cnt; ++i) {
            if (nums[i * chunk_size] > 0)
                target[i] = (positive_chunks++) * 2;
            else
                target[i] = (negative_chunks++) * 2 + 1;
        }
        for (int i=0; i<chunk_cnt; ++i) {
            while (target[i] != i) {
                swap_ranges(nums.begin() + i * chunk_size,
                            nums.begin() + i * chunk_size + chunk_size,
                            nums.begin() + target[i] * chunk_size);
                swap(target[target[i]], target[i]);
            }
        }
        ENABLE_LOG(
            cout << "sorted array: ";
            for (int v: nums) cout << v << " "; cout << endl;
        )

        vector<int> two_chunk_elements_interleaved;
        for (int i=0; i<nums.size(); i += 2 * chunk_size) {
            two_chunk_elements_interleaved.clear();
            for (int j=0; j<chunk_size; ++j)
            {
                two_chunk_elements_interleaved.push_back(nums[i + j]);
                two_chunk_elements_interleaved.push_back(nums[i + chunk_size + j]);
            }
            copy_n(two_chunk_elements_interleaved.cbegin(), 2 * chunk_size, nums.begin() + i);
        }

        nums.resize(original_n);
        return nums;

    }
};
