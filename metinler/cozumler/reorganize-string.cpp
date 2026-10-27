class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> mp;
        for(auto i: s){
            mp[i]++;
        }

        priority_queue<pair<int, char>> pq;

         for(auto it: mp){
            pq.push({it.second, it.first});
        }

        string ans = "";
        while(mp.size() > 1){

            char ch1 = pq.top().second;
            ans+=ch1;
            pq.pop();
            char ch2 = pq.top().second;
            ans+=ch2;
            pq.pop();

            mp[ch1]--;
            mp[ch2]--;

            if(mp[ch1] > 0){
                pq.push({mp[ch1],ch1});
            }
            else{

                mp.erase(ch1);
            }
            if(mp[ch2] > 0){
                pq.push({mp[ch2],ch2});
            }
            else{
                mp.erase(ch2);
            }
        }

        if(mp.size() == 1){
            if(mp[pq.top().second] > 1){
                return "";
            }
            ans += pq.top().second;
        }

        return ans;
    }
};
