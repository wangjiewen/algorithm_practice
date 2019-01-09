class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j, n;
        vector<int> ans;
        bool flag = false;
        n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        return ans;
    }
};
