#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }

            int ret_i = 0;
            int num = nums[ret_i];

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != num) {
                    nums[ret_i++] = num;
                    num = nums[i];
                }
            }

            if (ret_i == 0 || num != nums[ret_i - 1]) {
                nums[ret_i++] = num;
            }

            return ret_i;
        }
};

int main(void)
{
    //vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums = {1};
    Solution s;
    int ret = s.removeDuplicates(nums);

    for (int i = 0; i < ret; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
