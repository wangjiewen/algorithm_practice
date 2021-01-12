#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

bool solve(vector<int>& flowerbed, int n) {
	int num_zero = 0;
	int num_max = 0;
	int begin = 1;

	for (int i = 0; i < flowerbed.size(); i++) {
		if (flowerbed[i] == 0) {
			num_zero++;
		} else {
			if (begin) {
				num_max += num_zero / 2;
				begin = 0;
			} else {
				num_max += (num_zero - 1) / 2;
			}
			num_zero = 0;
		}
	}
	if (begin)
		num_max += (num_zero + 1) / 2;
	else
		num_max += num_zero / 2;

	return num_max >= n ? true : false;
}

int main(void)
{
	vector<int> f = {0};
	int n = 1;
	bool ret;

	ret = solve(f, n);
	cout << ret << endl;
	return 0;
}
