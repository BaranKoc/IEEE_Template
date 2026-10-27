class Solution {
public:
    bool memo[50][50][2000];
    bool comp_seqs(string& s1, string& s2, int i1, int i2, int diff){

        if(i1 == s1.size() && i2 == s2.size())
            return diff == 0;

        bool& ret = memo[i1][i2][diff+1000];
        if(ret)
            return false;
        ret = true;

        if(diff >= 0 && i1 < s1.size() && s1[i1] <= '9'){
            int num1 = 0;
            for(int i=0; i<min(3, (int)s1.size()-i1); i++){
                if(s1[i1 + i] > '9')
                    break;
                num1 = num1*10 + s1[i1 + i] - '0';
                if(comp_seqs(s1, s2, i1+i+1, i2, diff-num1))
                    return true;
            }
        }else if(diff <= 0 && i2 < s2.size() && s2[i2] <= '9'){
            int num2 = 0;
            for(int i=0; i<min(3, (int)s2.size()-i2); i++){
                if(s2[i2 + i] > '9')
                    break;
                num2 = num2*10 + s2[i2 + i] - '0';
                if(comp_seqs(s1, s2, i1, i2+i+1, diff+num2))
                    return true;
            }
        }else if(diff == 0){
            if(i1 >= s1.size() || i2 >= s2.size() || s1[i1] != s2[i2])
                return false;
            return comp_seqs(s1, s2, i1+1, i2+1, 0);
        }else if(diff > 0){
            if(i1 >= s1.size())
                return false;
            return comp_seqs(s1, s2, i1+1, i2, diff - 1);
        }else{
            if(i2 >= s2.size())
                return false;
            return comp_seqs(s1, s2, i1, i2+1, diff + 1);
        }
        return false;
    }
    bool possiblyEquals(string s1, string s2) {
        return comp_seqs(s1, s2, 0, 0, 0);
    }
};
