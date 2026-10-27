#include <algorithm>
#include <cstdint>
#include <functional>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

namespace ieee_template {

namespace balanced_brackets {
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s)
        {
            if(i=='(' or i=='{' or i=='[') st.push(i);
            else
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
}

namespace next_warmer_day {
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> result(n, 0);
        for(int i = 0; i<n; i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                result[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
}

}
