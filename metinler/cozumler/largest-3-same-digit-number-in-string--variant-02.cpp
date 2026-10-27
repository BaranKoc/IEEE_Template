class Solution {
public:
    string largestGoodInteger(string num) {

        for(int i='9';i>='0';i--){
            string s;
            s+=i;
            s+=i;
            s+=i;

            if(num.find(s)!=string::npos)
                return s;
        }
        return "";
    }
};
