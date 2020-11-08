#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
    public:
        int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
            int nums1_size = nums1.size();
            int nums2_size = nums2.size();
            int i1 = 0, i2 = 0;
            int new_i1, new_i2;

            while (true) {
                if (i1 == nums1_size)
                    return nums2[i2 + k - 1];
                if (i2 == nums2_size)
                    return nums1[i1 + k - 1];
                if (k == 1)
                    return min(nums1[i1], nums2[i2]);

                new_i1 = min(i1 + k / 2 - 1, nums1_size - 1);
                new_i2 = min(i2 + k / 2 - 1, nums2_size - 1);
                if (nums1[new_i1] <= nums2[new_i2]) {
                    k -= new_i1 - i1 + 1;
                    i1 = new_i1 + 1;
                } else {
                    k -= new_i2 - i2 + 1;
                    i2 = new_i2 + 1;
                }
            }
        }

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int len = nums1.size() + nums2.size();

            return (getKthElement(nums1, nums2, (len + 2) / 2) +
                    getKthElement(nums1, nums2, (len + 1) / 2)) / 2.0;
        }
};

int main(void) {
    vector<int> nums1 = {1, 2}, nums2 = {-1, 3};
    Solution s;
    double ret = s.findMedianSortedArrays(nums1, nums2);
    printf("%lf\n", ret);
    return 0;
}
