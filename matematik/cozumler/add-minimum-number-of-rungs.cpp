class Solution {
public:
    int addRungs(vector<int>& rungs, int dist)
    {

         long long int count = 0;

         long long int currpos = 0;

         long long int nextposidx = 0;

         while(true)
         {
             if(currpos == rungs[rungs.size()-1])
             {
                 break;
             }

             if((rungs[nextposidx] - currpos) <= dist)
             {
                 currpos = rungs[nextposidx];
                 nextposidx++;
             }
             else
             {

                 long long int temp = (rungs[nextposidx] - currpos);

                 if((temp%dist) == 0)
                 {
                     long long int val = temp/dist;
                     count = count + (val - 1);
                 }
                 else
                 {
                    long long int val = floor(((temp*1.00)/(dist*1.00)));
                    count = count + (val);
                 }
                 currpos = rungs[nextposidx];
             }
         }
         return count;
    }
};
