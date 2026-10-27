class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int c = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        int op = numsDivide[0];
        int n = numsDivide.size();
        for(int i = 1;i < n;i++){
            op = __gcd(op,numsDivide[i]);
        }
        for(auto&i : nums){
            pq.push(i);
        }
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            if(op%temp == 0){
                return c;
            }
            if(temp > op){
                return -1;
            }
            c++;

        }
        return -1;
    }
};
