class Solution {
public:
    int finalValueAfterOperations(vector<string>& o,int c=0) {
           for(auto &i:o) if(i=="++X" or i=="X++") c++; else c--;
           return c;
    }
};
