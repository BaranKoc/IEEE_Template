class Solution {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> result;

        unordered_map<int,int> intersection;

        for(auto character : nums1)
        {
            intersection[character] = 1;
        }

        for(auto character : nums2)
        {

            if(intersection[character])
            {
                result.push_back(character);
                intersection[character] = 0;
            }
        }

        return result;
    }
};
