#include <bits/stdc++.h>

using namespace std;

#define N 10005

class NumArray {
private:
	long long sum[N] = {0};
public:
	NumArray(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			sum[i+1] = sum[i] + nums[i];
		}
	}
	int sumRange(int i, int j) {
		return sum[j+1] - sum[i];
	}
};

int main(void)
{
	vector<int> nums = {-2, 0, 3, -5, 2, -1};
	NumArray *obj = new NumArray(nums);
	cout << obj->sumRange(0, 2) << endl;
	cout << obj->sumRange(2, 5) << endl;
	cout << obj->sumRange(0, 5) << endl;

	return 0;
}

