class Solution {
public:
    int minOperations(vector<string>& logs) {

        if(logs.size()==0) return 0;

        stack<string> st;
        for(auto x: logs){
            if (x[0] != '.')
                st.push(x);
            else if(x=="../"){
                 if(!st.empty())  st.pop();
                 else continue;
            }
        }
        return st.size();
    }
};

class Solution {
public:
    int minOperations(vector<string>& logs) {
         int ans = 0;
        for (string log : logs) {
            if (log == "../") {
                ans--;
                ans = max(ans, 0);
            } else if (log != "./")
			   ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (string s : logs) {
            if (s=="../") res = max(0, --res);
            else if (s=="./") continue;
            else res++;
        }
        return res;
    }
};
