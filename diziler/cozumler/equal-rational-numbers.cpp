class Solution {
public:
    double toDouble(string s){

       string in="", fn="", rn="";

        int i=0;

        while(i<s.size() && s[i]!='.'){ in+=s[i]; i++; }

        i++;
        while(i<s.size() && s[i]!='('){ fn+=s[i]; i++; }

        i++;
        while(i<s.size() && s[i]!=')'){ rn+=s[i]; i++; }

        double a = 0;

        if(!in.empty()) a=stoi(in);

        i=0;

        while(i<fn.size()){
            a = a*10 + fn[i] - '0';
            i++;
        }

        if(i < 8){

            if(rn.size() == 0){
                while(i <= 8){ a*=10;i++; }
            }

            else {
                int j=0;
                while(i <= 8){
                    a = a*10 + rn[j%rn.size()] - '0';
                    j++;
                    i++;
                }
            }
        }

        return a/10e8;
    }

    bool isRationalEqual(string s, string t) {

        double ans = abs(toDouble(s) - toDouble(t));
        return ans < 0.000000002;
    }
};
