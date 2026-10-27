class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0)
            return false;
        map<int,int>mp;
        for(auto it : hand)
            mp[it]++;
        while(mp.size() > 0){
            int start = mp.begin()->first;

            for(int i=0; i<groupSize; i++){
                if(mp.find(start) != mp.end()){
                    mp[start]--;
                    if(mp[start] == 0)
                        mp.erase(start);
                    start++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
