class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int n = s.size();
        vector<int> noOfZerosToRight(n,0);
        vector<int> noOfOnesToLeft(n,0);

        if(s[0] == '1') noOfOnesToLeft[0] = 1;
        for(int i=1;i<n;i++){
            if(s[i] == '1') noOfOnesToLeft[i] = noOfOnesToLeft[i-1] + 1;
            else noOfOnesToLeft[i] = noOfOnesToLeft[i-1];
        }

        if(s[n-1] == '0') noOfZerosToRight[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(s[i] == '0') noOfZerosToRight[i] = noOfZerosToRight[i+1] + 1;
            else noOfZerosToRight[i] = noOfZerosToRight[i+1];
        }

        int ans = 1e9;
        for(int i=0;i<n;i++){
            int leftFlips = 0;
            int rightFlips = noOfZerosToRight[i];

            if(i-1 >= 0) leftFlips = noOfOnesToLeft[i-1];
            ans = min(ans, (leftFlips + rightFlips));
        }

        ans = min(ans, noOfOnesToLeft.back() + 0);
        return ans;
    }

};
