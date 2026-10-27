class Solution {
public:
    bool isHappy(int n) {

        set<int> hset;
        while(hset.count(n) == 0) {

            if(n == 1)
                return true;

            hset.insert(n);

            int total=0;

            while(n) {

                total += (n % 10) * (n % 10);
                n /= 10;

            }

            n = total;
        }

        return false;
    }
};
