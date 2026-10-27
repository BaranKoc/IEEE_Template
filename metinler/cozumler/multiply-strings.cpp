class Solution {
    void compute(string &num, int dig, int ind, string &ans){
        int c = 0;
        int i = num.size()-1;

        while(i >= 0){
            int mul = dig*(num[i]-'0') + c;
            c = mul/10;
            mul %= 10;
            if(ind >= ans.length()){
                ans.push_back('0' + mul);
            }
            else{

                mul += (ans[ind] - '0');
                c += mul/10;
                mul %= 10;
                ans[ind] = ('0' + mul);
            }
            i--;
            ind++;
        }

        if(c > 0){
            ans.push_back('0' + c);
        }

    }
public:
    string multiply(string num1, string num2) {
        string ans = "";
        if(num1 == "0" || num2 == "0") return "0";
        int ind = 0;
        for(int i  = num1.size()-1; i >= 0; ind++,i--){

            int dig = num1[i]-'0';
            compute(num2, dig, ind, ans);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
