long long fun(long long a){
    long long b=a*(a+1)/2;
    return b;
}

class Solution {
public:
    int reachNumber(int target) {

         long long i=1,j=pow(10,5),x=abs(target),ans=0;

    while(i<=j){
        long long m=(i+j)/2;

        if(fun(m)==x){
            ans=m;
        }
        if(x>fun(m)){
            i=m+1;
        }
        else{
            j=m-1;
        }

    }

    if(ans!=0){

        return ans;
    }
    else{

    for(int l=j+1;l<100000;l++){

        if((fun(l)-x)%2 ==0){
             ans=l;

            break;

    }
    }

    }

        return ans;
    }

};
