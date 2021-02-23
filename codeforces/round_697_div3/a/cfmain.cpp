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

int main(void)
{
	freopen("in", "r", stdin);

	int loop;
	scanf("%d", &loop);
	while (loop--) {
		long long num;
		scanf("%lld", &num);
		while (num > 1) {
			if (num % 2 != 0) {
				printf("YES\n");
				break;
			}
			num /= 2;
		}
		if (num <= 1) {
			printf("NO\n");
		}
	}

	return 0;
}

