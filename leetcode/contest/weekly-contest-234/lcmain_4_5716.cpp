#include <bits/stdc++.h>

using namespace std;

#define P 1000000007

class Solution {
private:
    long long fastpow3(long long base, long long p) {
        long long ret = 1;
        while (p > 0) {
            if (p % 2 == 1) {
                ret = ret * base % P;
            }
            p = p / 2;
            base = (base * base) % P;
        }
        return ret;
    }
public:
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors == 1)
            return 1;
        else if (primeFactors == 2)
            return 2;
        
        long long p = primeFactors / 3;
        long long m = primeFactors - p * 3;
        
        if (m == 0) {
            m = 1;
        } else if (m == 1) {
            m = 4;
            p -= 1;
        }
        
        return (m * fastpow3(3, p)) % P;
    }
};
class Solution {
public:

};

int main(void)
{
	Solution s;

	return 0;
}

