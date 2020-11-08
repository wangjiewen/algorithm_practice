#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            int num_b = target - nums[i];
            if (m.find(num_b) != m.end()) {
                return {i, m[num_b]};
            }
            m[nums[i]]= i;
        }

        return {-1, -1};
    }

int main() {
    int num_init[] = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> nums(num_init, num_init + sizeof(num_init)/sizeof(int)), ret;
    
    ret = twoSum(nums, target);
    
    cout << ret[0] << " " << ret[1] << endl;
}
