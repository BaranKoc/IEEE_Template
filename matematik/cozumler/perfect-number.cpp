class Solution {
public:
    bool checkPerfectNumber(int num) {

        int sum=1;
        for(int i=2; i<sqrt(num); i++){
            if(num%i==0){

                if(i==num/i){
                    sum += i;
                }
                else{

                    sum += i + num/i;
                }
            }
        }
        if(sum==num && num!=1){
            return true;
        }
        return false;
    }
};
