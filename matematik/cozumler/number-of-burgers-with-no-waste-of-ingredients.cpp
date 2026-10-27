class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {

        vector <int> ans;
        if(tomatoSlices == 0 and cheeseSlices == 0) {
            ans.push_back(0), ans.push_back(0);
            return ans;
        }

        int low = 0, high = cheeseSlices;
        while(low < high) {
            int mid = (low + high) / 2;
            int jumbo = mid, small = cheeseSlices - mid;

            int needJumboTom = jumbo * 4;
            int needSmallTom = small * 2;

            if(needJumboTom + needSmallTom == tomatoSlices) {
                ans.push_back(jumbo), ans.push_back(small);
                break;
            } else if(needJumboTom + needSmallTom < tomatoSlices) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return ans;
    }
};
