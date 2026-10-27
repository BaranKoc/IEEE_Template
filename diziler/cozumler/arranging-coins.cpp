class Solution {
public:
    int arrangeCoins(int n) {

         int count=0;
         while(n>0)
         {
             count++;
             n=n-count;
         }
         if(n==0)
         {
             return count;
         }
         else if(n<0)
         {
             return count-1;
         }
         return -1;

    }
};
