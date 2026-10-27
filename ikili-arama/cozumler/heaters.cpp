class Solution {
public:

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int radius=0;
        for(int house:houses){

            int index=lower_bound(heaters.begin(),heaters.end(),house)-heaters.begin();
            if(index==heaters.size()){
                index--;
            }

            int leftDiff=(index-1>=0)?abs(house-heaters[index-1]):INT_MAX;
            int rightDiff=abs(house-heaters[index]);
            radius=max(radius,min(leftDiff,rightDiff));
        }
        return radius;
    }
};
