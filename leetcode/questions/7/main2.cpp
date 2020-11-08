#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int ret = 0;

            while (x != 0) {
                if (ret > INT_MAX/10 || ret < INT_MIN/10)
                    return 0;
                ret = ret * 10 + x % 10;
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

    printf("%d %d\n", INT_MAX, INT_MIN);
    ret = s.reverse(x);
    printf("%d\n", ret);
}
