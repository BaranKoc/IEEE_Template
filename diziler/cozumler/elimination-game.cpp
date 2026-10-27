class Solution {
public:
    int lastRemaining(int n) {
        bool left=true;
        int head=1,step=1;
        while(n>1){
            if(left || (n&1)){
                head=head+step;
            }
            step=step*2;
            n=n/2;
            left=!left;
        }
        return head;
    }
};
