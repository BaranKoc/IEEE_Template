class Bitset {
public:
    vector<int>arr;
    int cnt,cntflip;
    Bitset(int size) {
        arr.resize(size,0);
        cnt=0,cntflip=0;
    }
    void fix(int idx) {

        if((arr[idx]+cntflip)%2==0){
            arr[idx]++;
            cnt++;
        }
    }
    void unfix(int idx) {

      if((arr[idx]+cntflip)%2!=0){
            arr[idx]--;
            cnt--;
        }
    }
    void flip() {

         cnt=arr.size()-cnt;
        cntflip++;
    }
    bool all() {
        if(cnt==arr.size())
            return true;
        return false;
    }
    bool one() {
        if(cnt>=1)
            return true;
        return false;
    }
    int count() {
        return cnt;
    }
    string toString() {
        string ans;
        for(auto &ele :arr){
            if((cntflip+ele)%2==0)
                ans.push_back('0');
            else
                ans.push_back('1');
        }
        return ans;
    }
};
