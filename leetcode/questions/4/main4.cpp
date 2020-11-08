#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int len1 = nums1.size();
            int len2 = nums2.size();
            int len = (len1 + len2) / 2;
            int i1 = 0, i2 = 0, val1 = 0, val2 = 0;

            for (int i = 0; i <= len; i++) {
                val1 = val2;
                if (i1 >= len1) {
                    if (i2 + len - i - 1 >= i2)
                        val1 = nums2[i2 + len - i - 1];
                    if (i2 + len - i >= i2)
                        val2 = nums2[i2 + len - i];
                    break;
                }
                if (i2 >= len2) {
                    if (i1 + len - i - 1 >= i1)
                        val1 = nums1[i1 + len - i - 1];
                    if (i1 + len - i >= i1)
                        val2 = nums1[i1 + len - i];
                    break;
                }
                if (nums1[i1] < nums2[i2])
                    val2 = nums1[i1++];
                else
                    val2 = nums2[i2++];
            }

            if ((len1 + len2) & 1)
                return val2;
            return (val1 + val2) / 2.0;
        }
};

int main(void) {
    vector<int> nums1 = {2}, nums2 = {1, 3, 4};
    Solution s;
    double ret = s.findMedianSortedArrays(nums1, nums2);
    printf("%lf\n", ret);
    return 0;
}
