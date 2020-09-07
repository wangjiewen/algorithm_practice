#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int ret = 0, temp;

            while (x != 0) {
                temp = x % 10;
                if (ret > INT_MAX/10 || (ret == INT_MAX/10 && temp > 7))
                    return 0;
                if (ret < INT_MIN/10 || (ret == INT_MIN/10 && temp < -8))
                    return 0;
                ret = ret * 10 + temp;
                x /= 10;
            }
            
            return ret;
        }
        
};

int main(void)
{
    int x = INT_MAX;
    int ret;
    Solution s;

    ret = s.reverse(x);
    printf("%d\n", ret);
}
