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
		int num;
		scanf("%d", &num);
		if (num / 2020 >= num % 2020) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}

