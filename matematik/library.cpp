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

namespace prime_counter {
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        vector<bool>prime(n,true);
        for(int i = 2; i*i < n; i++){
            if(prime[i]){
                for(int j = i*i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(prime[i]) cnt++;
        }
        return cnt;
    }
};
}

namespace fast_power {
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }
};
}

}
