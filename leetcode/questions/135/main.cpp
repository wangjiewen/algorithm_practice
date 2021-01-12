#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int ret = 0;
		int li, ri, mli, mri;
		int l, r;
		int i;
		int size = ratings.size();
		int n1, n2;
		int prev_r;

		ri = -1;
		while (i < size) {
			li = ri + 1;
			i = 1;
			while (i < size && ratings[i] > ratings[li])
				i++;
			mli = i - 1;
			while (i < size && ratings[i] == ratings[mli])
				i++;
			mri = i - 1;
			while (i < size && ratings[i] < ratings[mli])
				i++;
			ri = i - 1;

			n1 = mli - li;
			n2 = ri - mri;

			ret = ret + n1 * (n1 - 1) / 2 + n2 * (n2 - 1) / 2;
			ret = ret + (mri - mli + 1) * max(n1 + 1, n2 + 1);

			if (n1 > prev_r)
	}
};

int main(void)
{
	return 0;
}

