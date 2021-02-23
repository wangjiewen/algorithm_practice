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
		int ret = 0;

		for (int i = 0; i < k; i++) {
			scanf("%d", &cp[i].boy);
		}
		for (int i = 0; i < k; i++) {
			scanf("%d", &cp[i].girl);
		}

		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if (cp[i].boy != cp[j].boy && cp[i].girl != cp[j].girl) {
					ret += 1;
				}
			}
		}

		printf("%d\n", ret);
	}

	return 0;
}

