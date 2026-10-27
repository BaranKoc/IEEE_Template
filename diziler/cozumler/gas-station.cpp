class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = -1;

        int sum = 0 , gastillnow = 0;
        for(int i = 0 ; i < 2*n ; i++){
            if(start == i%n){
                return i%n;
            }
            if(gas[i%n] + gastillnow >= cost[i%n]){
                if(start==-1) start = i;
                gastillnow += gas[i%n]-cost[i%n];
            }else if(gastillnow + gas[i%n] < cost[i%n]){
                start = -1;
                gastillnow = 0;
            }
        }
        return -1;
    }
};
