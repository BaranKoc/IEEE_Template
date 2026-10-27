class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int diff = n - k;
        int lo = 1;
        int hi = n;
        vector<int> out;
        int i = 0;

        while(i < diff){
            out.push_back(lo);
            lo++;
            i++;
        }
        bool flag = true;

        for(int i = out.size()   ; i < n ; i++){

		   if(flag){
                out.push_back(hi);
                hi--;
                flag = false;
            }
            else{
                out.push_back(lo);
                lo++;
                flag = true;
            }
        }
        return out;
    }
};
