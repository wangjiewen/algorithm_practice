class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] >= target){
                ans = i;
                break;
            }
        }
        if(ans == -1)
            ans = n;
        return ans;
    }
};
