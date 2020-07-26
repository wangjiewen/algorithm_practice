#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left, right, mid;

            left = 0;
            right = nums.size() - 1;
            while (left <= right) {
                mid = (right + left) / 2;
                if (target == nums[mid])
                    return mid;
                if (nums[left] <= nums[mid]) {
                    if (target >= nums[left] && target <= nums[mid])
                        right = mid;
                    else
                        left = mid + 1;
                } else {
                    if (target >= nums[mid] && target <= nums[right])
                        left = mid;
                    else
                        right = mid - 1;
                }
            }

            return -1;
        }
};

int main(void) {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int ret = s.search(nums, 3);
    printf("%d\n", ret);
    return 0;
}
