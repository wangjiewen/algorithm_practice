#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>

#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

struct cp {
	int boy;
	int girl;
};

int main(void)
{
	freopen("in", "r", stdin);

	int loop;
	scanf("%d", &loop);
	while (loop--) {
		int a, b, k;
		scanf("%d %d %d\n", &a, &b, &k);
		struct cp cp[k];
		long long nboy[a+1] = {0}, ngirl[b+1] = {0};
		long long ret = 0;

		for (int i = 0; i < k; i++) {
			scanf("%d", &cp[i].boy);
			nboy[cp[i].boy] += 1;
		}
		for (int i = 0; i < k; i++) {
			scanf("%d", &cp[i].girl);
			ngirl[cp[i].girl] += 1;
		}

		for (int i = 0; i < k; i++) {
			ret += k - nboy[cp[i].boy] - ngirl[cp[i].girl] + 1;
		}

		printf("%lld\n", ret / 2);
	}

	return 0;
}

